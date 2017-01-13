include(config.pri)

QT += xml

CONFIG(release, debug|release) {

    message("Release Mode")

    unix{
        INCLUDEPATH += /opt/local/include
        LIBS += -L/opt/local/lib \
        -lopencv_core \
        -lopencv_imgproc \
        -lopencv_highgui \
        -lopencv_imgcodecs
    }
}


CONFIG(debug, debug|release) {

    message("Debug Mode")

    unix{
        INCLUDEPATH += /opt/local/debug/include
        LIBS += -L/opt/local/debug/lib \
        -lopencv_core \
        -lopencv_imgproc \
        -lopencv_highgui \
        -lopencv_imgcodecs
    }
}

HEADERS += \
    $$PWD/src/classifier.h \
    $$PWD/src/cutils.h \
    $$PWD/src/fpdw_detector.h \
    $$PWD/src/fpdw_utils.h \
    $$PWD/src/nms.h \
    $$PWD/src/sse.hpp \
    $$PWD/src/structs.h

SOURCES += \
    $$PWD/src/classifier.cpp \
    $$PWD/src/cutils.cpp \
    $$PWD/src/fpdw_detector.cpp \
    $$PWD/src/fpdw_utils.cpp \
    $$PWD/src/main.cpp \
    $$PWD/src/nms.cpp
