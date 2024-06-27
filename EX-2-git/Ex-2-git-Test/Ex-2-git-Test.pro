QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_ex_2_tests.cpp ../Ex-2-Sources/Ex-2-sources-realization.cpp
HEADERS += ../Ex-2-Sources/Ex-2-sources-headers.h
