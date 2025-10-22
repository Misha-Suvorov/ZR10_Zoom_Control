#include <QCoreApplication>
#include "zr10_zoom_control.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    ZR10ZoomControl zoom;

    //zoom.setZoomPosition(30.0f);
    zoom.setZoomPosition(9.0f);

    return a.exec();
}
