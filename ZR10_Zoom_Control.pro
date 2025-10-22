QT = core network

CONFIG += c++17 cmdline



INCLUDEPATH += C:\opencv_source\opencv-4.12.0_Modules_Release\build\install\include
DEPENDPATH += C:\opencv_source\opencv-4.12.0_Modules_Release\build\install\include
LIBS += C:\opencv_source\opencv-4.12.0_Modules_Release\build\install\x64\vc17\lib\opencv_world4120.lib

INCLUDEPATH += C:\Qt\6.7.3\msvc2019_64\include
DEPENDPATH += C:\Qt\6.7.3\msvc2019_64\include

INCLUDEPATH += C:\Qt\6.7.3\msvc2019_64\include\QtGui
DEPENDPATH += C:\Qt\6.7.3\msvc2019_64\include\QtGui

INCLUDEPATH += C:\Qt\6.7.3\msvc2019_64\include\QtWidgets
DEPENDPATH += C:\Qt\6.7.3\msvc2019_64\include\QtWidgets

INCLUDEPATH += C:\Qt\6.7.3\msvc2019_64\include\QtCore
DEPENDPATH += C:\Qt\6.7.3\msvc2019_64\include\QtCore

INCLUDEPATH += C:\Qt\6.7.3\msvc2019_64\include\QtNetwork
DEPENDPATH += C:\Qt\6.7.3\msvc2019_64\include\QtNetwork


INCLUDEPATH += C:\c_library_v2-master\c_library_v2-master
DEPENDPATH += C:\c_library_v2-master\c_library_v2-master

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        zr10_zoom_control.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    zr10_zoom_control.h
