#ifndef ZR10_ZOOM_CONTROL_H
#define ZR10_ZOOM_CONTROL_H

#include <QUdpSocket>
#include <QHostAddress>
#include <QThread>
#include <QElapsedTimer>
#include <vector>
#include <utility>

class ZR10ZoomControl
{
public:
    ZR10ZoomControl();
    ~ZR10ZoomControl();

    // встановлює зум до цільового значення (1.0–30.0)
    void setZoomPosition(float zoom);

    // можна задати вручну, якщо відомо поточне положення
    void setCurrentZoomKnown(float zoom);

private:
    QUdpSocket sock;
    QHostAddress addr;
    quint16 sendPort;
    quint16 recvPort;
    float currentZoom;
    bool initialized;

    // CRC
    uint16_t CRC16_cal(uint8_t *ptr, uint32_t len, uint16_t crc_init);
    uint8_t crc_check_16bites(uint8_t *pbuf, uint32_t len, uint32_t *p_result);

    // надсилання команд
    void sendCommand(uint8_t cmd_id, const std::vector<uint8_t> &payload);
    void sendAutoFocus();
    void sendZoomStop();
    void sendAbsoluteZoomCmdOnly(float zoomVal);

    // допоміжні функції
    std::pair<float,int> computeStepAndDelay(float zoomVal);

    // отримає реальне значення зуму з камери (через 0x18)
    bool queryZoomFromCamera(float &zoomOut);
};

#endif // ZR10_ZOOM_CONTROL_H
