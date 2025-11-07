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

    void setZoomPosition(float zoom);

    void setCurrentZoomKnown(float zoom);

    // --- НОВІ ПУБЛІЧНІ ФУНКЦІЇ ---

    /**
     * @brief Запускає одноразовий цикл автоматичного фокусування.
     * (Використовує команду 0x04).
     */
    void triggerAutoFocus();

    /**
     * @brief Починає ручне фокусування "вдалечінь" (на нескінченність).
     * (Використовує команду 0x06, значення 1).
     */
    void startManualFocusFar();

    /**
     * @brief Починає ручне фокусування "зблизька".
     * (Використовує команду 0x06, значення -1).
     */
    void startManualFocusNear();

    /**
     * @brief Зупиняє будь-яке активне ручне фокусування.
     * (Використовує команду 0x06, значення 0).
     */
    void stopManualFocus();

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

    // --- ВАШІ ОРИГІНАЛЬНІ МЕТОДИ ---
    void sendCommand(uint8_t cmd_id, const std::vector<uint8_t> &payload);
    void sendAutoFocus(); // залишається приватним, викликається з triggerAutoFocus
    void sendZoomStop();
    void sendAbsoluteZoomCmdOnly(float zoomVal);

    std::pair<float,int> computeStepAndDelay(float zoomVal);

    bool queryZoomFromCamera(float &zoomOut);

    // --- НОВИЙ ПРИВАТНИЙ МЕТОД ---
    /**
     * @brief Надсилає команду ручного фокусування (CMD 0x06) з правильним DataLen=1.
     */
    void sendManualFocusCmd(int8_t focusVal);
};

#endif // ZR10_ZOOM_CONTROL_H
