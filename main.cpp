#include <QCoreApplication>
#include <QTimer>   // Додано для таймерів
#include <QThread>  // Додано для QThread::msleep
#include <QDebug>   // Додано для qDebug
#include "zr10_zoom_control.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ZR10ZoomControl zoom;

    qDebug() << "[TEST 1]";
    zoom.setZoomPosition(19.0f);
    QThread::msleep(3000);

    qDebug() << "[TEST 2] focus near";
    zoom.startManualFocusNear();
    QThread::msleep(1500);
    zoom.stopManualFocus();
    qDebug() << "[TEST 2] End";
    QThread::msleep(2000);

    qDebug() << "[TEST 3] Focus far";
    zoom.startManualFocusFar();
    QThread::msleep(1500);
    zoom.stopManualFocus();
    qDebug() << "[TEST 3] End";
    QThread::msleep(2000);

    qDebug() << "[TEST 4] Autofocus";
    zoom.triggerAutoFocus();
    qDebug() << "[TEST 4] End";


    QTimer::singleShot(5000, &a, &QCoreApplication::quit);

    return a.exec();
}
