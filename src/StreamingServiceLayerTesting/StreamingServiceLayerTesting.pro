QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_streamingservicelayertestfixture.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/release/ -lStreamingServiceLayer
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/debug/ -lStreamingServiceLayer
else:unix: LIBS += -L$$OUT_PWD -lStreamingServiceLayer

INCLUDEPATH += $$PWD/../StreamingServiceLayer
DEPENDPATH += $$PWD/../StreamingServiceLayer

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/release/StreamingServiceLayer.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/debug/StreamingServiceLayer.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/StreamingServiceLayer.a
