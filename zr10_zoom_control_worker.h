#ifndef ZR1__ZOOM_CONTROL_WORKER_H
#define ZR1__ZOOM_CONTROL_WORKER_H
#include <QObject>
#include "zr10_zoom_control.h"

class ZR10ZoomWorker : public QObject
{
    Q_OBJECT
public:
    explicit ZR10ZoomWorker(ZR10ZoomControl* zoomCtrl, QObject* parent = nullptr)
        : QObject(parent), zoom(zoomCtrl), targetZoom(1.0f) {}

public slots:
    void runZoom() {
        if (zoom)
            zoom->setZoomPosition(targetZoom);
        emit finished();
    }

signals:
    void finished();

public:
    float targetZoom;
    ZR10ZoomControl* zoom;
};
#endif // ZR1__ZOOM_CONTROL_WORKER_H
