TARGET=BoostSerialize
CONFIG += console
CONFIG -= app_bundle
OBJECTS_DIR=obj
INCLUDEPATH+=include
INCLUDEPATH +=/usr/local/include/
LIBS+=-L/usr/local/lib
LIBS+=-lboost_serialization -lboost_iostreams
macx:QMAKE_CXXFLAGS+= -stdlib=libc++
DEPENDPATH=include
SOURCES += \
    src/main.cpp \
    src/Sphere.cpp

HEADERS += \
    include/Sphere.h
