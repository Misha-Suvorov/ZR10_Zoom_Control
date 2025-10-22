#include "zr10_zoom_control.h"
#include <QDebug>
#include <cmath>

// ---- CRC TABLE ----
static const uint16_t crc16_tab[256] = {
    0x0,0x1021,0x2042,0x3063,0x4084,0x50a5,0x60c6,0x70e7,
    0x8108,0x9129,0xa14a,0xb16b,0xc18c,0xd1ad,0xe1ce,0xf1ef,
    0x1231,0x210,0x3273,0x2252,0x52b5,0x4294,0x72f7,0x62d6,
    0x9339,0x8318,0xb37b,0xa35a,0xd3bd,0xc39c,0xf3ff,0xe3de,
    0x2462,0x3443,0x420,0x1401,0x64e6,0x74c7,0x44a4,0x5485,
    0xa56a,0xb54b,0x8528,0x9509,0xe5ee,0xf5cf,0xc5ac,0xd58d,
    0x3653,0x2672,0x1611,0x630,0x76d7,0x66f6,0x5695,0x46b4,
    0xb75b,0xa77a,0x9719,0x8738,0xf7df,0xe7fe,0xd79d,0xc7bc,
    0x48c4,0x58e5,0x6886,0x78a7,0x840,0x1861,0x2802,0x3823,
    0xc9cc,0xd9ed,0xe98e,0xf9af,0x8948,0x9969,0xa90a,0xb92b,
    0x5af5,0x4ad4,0x7ab7,0x6a96,0x1a71,0xa50,0x3a33,0x2a12,
    0xdbfd,0xcbdc,0xfbbf,0xeb9e,0x9b79,0x8b58,0xbb3b,0xab1a,
    0x6ca6,0x7c87,0x4ce4,0x5cc5,0x2c22,0x3c03,0xc60,0x1c41,
    0xedae,0xfd8f,0xcdec,0xddcd,0xad2a,0xbd0b,0x8d68,0x9d49,
    0x7e97,0x6eb6,0x5ed5,0x4ef4,0x3e13,0x2e32,0x1e51,0xe70,
    0xff9f,0xefbe,0xdfdd,0xcffc,0xbf1b,0xaf3a,0x9f59,0x8f78,
    0x9188,0x81a9,0xb1ca,0xa1eb,0xd10c,0xc12d,0xf14e,0xe16f,
    0x1080,0xa1,0x30c2,0x20e3,0x5004,0x4025,0x7046,0x6067,
    0x83b9,0x9398,0xa3fb,0xb3da,0xc33d,0xd31c,0xe37f,0xf35e,
    0x2b1,0x1290,0x22f3,0x32d2,0x4235,0x5214,0x6277,0x7256,
    0xb5ea,0xa5cb,0x95a8,0x8589,0xf56e,0xe54f,0xd52c,0xc50d,
    0x34e2,0x24c3,0x14a0,0x481,0x7466,0x6447,0x5424,0x4405,
    0xa7db,0xb7fa,0x8799,0x97b8,0xe75f,0xf77e,0xc71d,0xd73c,
    0x26d3,0x36f2,0x691,0x16b0,0x6657,0x7676,0x4615,0x5634,
    0xd94c,0xc96d,0xf90e,0xe92f,0x99c8,0x89e9,0xb98a,0xa9ab,
    0x5844,0x4865,0x7806,0x6827,0x18c0,0x8e1,0x3882,0x28a3,
    0xcb7d,0xdb5c,0xeb3f,0xfb1e,0x8bf9,0x9bd8,0xabbb,0xbb9a,
    0x4a75,0x5a54,0x6a37,0x7a16,0xaf1,0x1ad0,0x2ab3,0x3a92,
    0xfd2e,0xed0f,0xdd6c,0xcd4d,0xbdaa,0xad8b,0x9de8,0x8dc9,
    0x7c26,0x6c07,0x5c64,0x4c45,0x3ca2,0x2c83,0x1ce0,0xcc1,
    0xef1f,0xff3e,0xcf5d,0xdf7c,0xaf9b,0xbfba,0x8fd9,0x9ff8,
    0x6e17,0x7e36,0x4e55,0x5e74,0x2e93,0x3eb2,0xed1,0x1ef0
};

ZR10ZoomControl::ZR10ZoomControl()
    : addr("192.168.144.25"), sendPort(37260), recvPort(37262),
    currentZoom(0.0f), initialized(false)
{
    sock.bind(QHostAddress::AnyIPv4, recvPort);
}

ZR10ZoomControl::~ZR10ZoomControl() {}

// ---- CRC ----
uint16_t ZR10ZoomControl::CRC16_cal(uint8_t *ptr, uint32_t len, uint16_t crc_init)
{
    uint16_t crc = crc_init;
    while (len--) {
        uint8_t temp = (crc >> 8) ^ *ptr++;
        crc = (crc << 8) ^ crc16_tab[temp];
    }
    return crc;
}

uint8_t ZR10ZoomControl::crc_check_16bites(uint8_t *pbuf, uint32_t len, uint32_t *p_result)
{
    uint16_t crc_result = CRC16_cal(pbuf, len, 0);
    *p_result = crc_result;
    return 2;
}

//UDP sendings
void ZR10ZoomControl::sendCommand(uint8_t cmd_id, const std::vector<uint8_t> &payload)
{
    std::vector<uint8_t> buf = {0x55,0x66,0x01,0x02,0x00,0x00,0x00,cmd_id};
    buf.insert(buf.end(), payload.begin(), payload.end());

    uint32_t crc_result = 0;
    crc_check_16bites(buf.data(), (uint32_t)buf.size(), &crc_result);

    QByteArray packet(reinterpret_cast<const char*>(buf.data()), (int)buf.size());
    packet.append(static_cast<char>(crc_result & 0xFF));
    packet.append(static_cast<char>((crc_result >> 8) & 0xFF));

    sock.writeDatagram(packet, addr, sendPort);
}

// ---- AutoFocus ----
void ZR10ZoomControl::sendAutoFocus()
{
    std::vector<uint8_t> payload = {1,0,0,0,0};
    sendCommand(0x04, payload);
    qDebug() << "Sent Auto Focus command";
}

// ---- STOP ----
void ZR10ZoomControl::sendZoomStop()
{
    sendCommand(0x10, {});
    qDebug() << "Sent Zoom STOP command";
}

// ---- Step ----
std::pair<float,int> ZR10ZoomControl::computeStepAndDelay(float zoomVal)
{
    if (zoomVal < 10.0f)
        return {0.1f, 600};
    else if (zoomVal < 20.0f)
        return {0.5f, 400};
    else if (zoomVal < 25.0f)
        return {1.0f, 450};
    else
        return {1.0f, 600};
}

// ---- ABS ----
void ZR10ZoomControl::sendAbsoluteZoomCmdOnly(float zoomVal)
{
    zoomVal = std::clamp(zoomVal, 1.0f, 30.0f);
    int intPart = static_cast<int>(zoomVal);
    int fracPart = static_cast<int>(std::round((zoomVal - intPart) * 10.0f));
    if (fracPart == 10) { intPart += 1; fracPart = 0; }

    std::vector<uint8_t> payload = { (uint8_t)intPart, (uint8_t)fracPart };
    sendCommand(0x0F, payload);
    qDebug().noquote() << QString("Sent ABS zoom %1.%2").arg(intPart).arg(fracPart);
    currentZoom = zoomVal;
}

// ---- Отримати поточний зум з камери ----
bool ZR10ZoomControl::queryZoomFromCamera(float &zoomOut)
{
    uint8_t command[] = {0x55,0x66,0x01,0x00,0x00,0x00,0x00,0x18};
    uint32_t crc_result;
    crc_check_16bites(command, sizeof(command), &crc_result);

    QByteArray packet(reinterpret_cast<const char*>(command), sizeof(command));
    packet.append((char)(crc_result & 0xFF));
    packet.append((char)((crc_result >> 8) & 0xFF));

    sock.writeDatagram(packet, addr, sendPort);
    qDebug() << "Sent zoom request (0x18)";

    QElapsedTimer timer;
    timer.start();
    while (timer.elapsed() < 3000) {
        if (sock.hasPendingDatagrams()) {
            QByteArray data;
            data.resize(sock.pendingDatagramSize());
            sock.readDatagram(data.data(), data.size());

            if (data.size() >= 10 && (uint8_t)data[7] == 0x18) {
                uint8_t zoomInt = (uint8_t)data[8];
                uint8_t zoomFrac = (uint8_t)data[9];
                zoomOut = zoomInt + zoomFrac / 10.0f;
                qDebug() << "Received real zoom value:" << zoomOut;
                return true;
            }
        }
        QThread::msleep(20);
    }

    qDebug() << "Zoom query timeout — no reply from camera";
    return false;
}

// ---- Встановити поточний зум ----
void ZR10ZoomControl::setCurrentZoomKnown(float zoom)
{
    currentZoom = std::clamp(zoom, 1.0f, 30.0f);
    initialized = true;
    qDebug() << "Current zoom manually set to" << currentZoom;
}

// ---- Головна функція ----
void ZR10ZoomControl::setZoomPosition(float targetZoom)
{
    targetZoom = std::clamp(targetZoom, 1.0f, 30.0f);
    float realZoom;

    if (queryZoomFromCamera(realZoom)) {
        currentZoom = realZoom;
        initialized = true;
    } else {
        qDebug() << "Using internal zoom estimate:" << currentZoom;
    }

    qDebug() << "Start moving zoom from" << currentZoom << "to" << targetZoom;

    const int MAX_STEPS = 500;
    int steps = 0;

    while (std::fabs(currentZoom - targetZoom) > 0.049f && steps < MAX_STEPS)
    {
        ++steps;
        auto [step, delayMs] = computeStepAndDelay(currentZoom);

        if (targetZoom < currentZoom) {
            float next = std::max(targetZoom, currentZoom - step);
            sendAbsoluteZoomCmdOnly(next);
        } else {
            float next = std::min(targetZoom, currentZoom + step);
            sendAbsoluteZoomCmdOnly(next);
        }

        QThread::msleep(delayMs);
    }

    sendZoomStop();
    sendAutoFocus();

    if (steps >= MAX_STEPS)
        qDebug() << "Warning: reached MAX_STEPS without exact convergence. currentZoom =" << currentZoom;
    else
        qDebug() << "Zoom position reached:" << currentZoom << "in" << steps << "steps";
}
