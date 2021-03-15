QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L'C:/Program Files (x86)/IntelSWTools/system_studio_2020/OpenCL/sdk/lib/x32/' -lOpenCL
else:win32:CONFIG(debug, debug|release): LIBS += -L'C:/Program Files (x86)/IntelSWTools/system_studio_2020/OpenCL/sdk/lib/x64/' -lOpenCL
else:unix: LIBS += -L'C:/Program Files (x86)/IntelSWTools/system_studio_2020/OpenCL/sdk/lib/x64/' -lOpenCL

INCLUDEPATH += 'C:/Program Files (x86)/IntelSWTools/system_studio_2020/OpenCL/sdk/include/'
DEPENDPATH += 'C:/Program Files (x86)/IntelSWTools/system_studio_2020/OpenCL/sdk/include/'





