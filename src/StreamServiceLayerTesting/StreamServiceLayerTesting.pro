QT += testlib qml quick
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase ordered
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_streamservicelayertestfixture.cpp

SUBDIRS = QStreamServiceLayer
