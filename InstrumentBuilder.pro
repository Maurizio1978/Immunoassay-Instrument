#-------------------------------------------------
#
# Project created by QtCreator 2015-02-26T09:17:46
#
#-------------------------------------------------

QT       += core gui
QT 		 += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InstrumentBuilder
TEMPLATE = app


SOURCES += main.cpp\
        mainmenu.cpp \
    mago4builder.cpp \
    mago4sbuilder.cpp \
    instrumentcreator.cpp \
    InstrumentDefinition/instrument.cpp \
    InstrumentDefinition/bay.cpp \
    InstrumentDefinition/holder.cpp \
    InstrumentDefinition/rack.cpp \
    InstrumentDefinition/platerack.cpp \
    InstrumentDefinition/dilutionrack.cpp \
    InstrumentDefinition/reagentrack.cpp \
    InstrumentDefinition/samplerack.cpp \
    Logger/logger.cpp \
    tinythread.cpp \
    InstrumentConfiguration/configuration.cpp \
    Exceptions/exceptions.cpp \
    reader.cpp \
    constants.cpp \
    biuld/debug/moc_mainmenu.cpp \
    Samples/sampleslist.cpp \
    SampleObservers/sampleobserver.cpp \
    biuld/debug/moc_mainmenu.cpp

HEADERS  += mainmenu.h \
    builder.h \
    mago4builder.h \
    mago4sbuilder.h \
    instrumentcreator.h \
    InstrumentDefinition/instrument.h \
    InstrumentDefinition/bay.h \
    InstrumentDefinition/holder.h \
    InstrumentDefinition/rack.h \
    InstrumentDefinition/platerack.h \
    InstrumentDefinition/dilutionrack.h \
    InstrumentDefinition/reagentrack.h \
    InstrumentDefinition/samplerack.h \
    Logger/logger.h \
    fast_mutex.h \
    instrumentelements.h \
    tinythread.h \
    InstrumentConfiguration/configuration.h \
    Exceptions/exceptions.h \
    reader.h \
    constants.h \
    biuld/ui_mainmenu.h \
    Templates/matrix.h \
    Samples/sampleslist.h \
    SampleObservers/sampleobserver.h

FORMS    += mainmenu.ui

QT += xml