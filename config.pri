CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
VERSION = 1.0.0

unix{
    CONFIG+=c++14
    QMAKE_CFLAGS_DEBUG +=-O0
    QMAKE_CFLAGS_DEBUG +=-g
    QMAKE_CFLAGS_RELEASE +=-Ofast
    QMAKE_CFLAGS_RELEASE +=-O1
    QMAKE_CXXFLAGS_RELEASE += -Ofast
    QMAKE_CXXFLAGS_RELEASE += -O1
    QMAKE_CXXFLAGS_RELEASE += -msse
    QMAKE_CXXFLAGS_RELEASE += -msse2
    QMAKE_CXXFLAGS_RELEASE += -msse3
    QMAKE_CXXFLAGS_WARN_ON = -Wall -Wno-unused-parameter -Wno-unused-function
}
