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

INCLUDEPATH += C:/Boost/boost_1_62_0

SOURCES += main.cpp\
        mainmenu.cpp \
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
    biuld/debug/moc_mainmenu.cpp \
    Factory/factory.cpp \
    Instrument/instrument.cpp \
    Instrument/SampleRack/samplerack.cpp \
    Instrument/DilutionRack/dilutionrack.cpp \
    Instrument/WellRack/wellrack.cpp \
    Mago4/mago4.cpp \
    Mago4S/mago4s.cpp \
    Mago4/DilutionRack/dilutionrack.cpp \
    Mago4/Mago4DilutionRack/mago4dilutionrack.cpp \
    Mago4/DilutionRack/dilutionrack.cpp \
    Mago4/mago4dilutionrack.cpp \
    Mago4/Mago4SampleRack/mago4samplerack.cpp \
    Mago4/Mago4WellRack/mago4wellrack.cpp \
    Mago4S/Mago4sDilutionRack/mago4sdilutionrack.cpp \
    Mago4S/Mago4sSampleRack/mago4ssamplerack.cpp \
    Mago4S/Mago4sWellRack/mago4swellrack.cpp \
    Instrument/configuration.cpp

HEADERS  += mainmenu.h \
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
    tinythread.h \
    InstrumentConfiguration/configuration.h \
    Exceptions/exceptions.h \
    reader.h \
    constants.h \
    biuld/ui_mainmenu.h \
    Templates/matrix.h \
    Samples/sampleslist.h \
    SampleObservers/sampleobserver.h \
    Factory/factory.h \
    Instrument/instrument.h \
    Factory/mago4factory.h \
    Factory/mago4sfactory.h \
    Instrument/SampleRack/samplerack.h \
    Instrument/DilutionRack/dilutionrack.h \
    Instrument/WellRack/wellrack.h \
    Mago4/mago4.h \
    Mago4S/mago4s.h \
    Mago4/Mago4DilutionRack/mago4dilutionrack.h \
    Mago4/Mago4SampleRack/mago4samplerack.h \
    Mago4/Mago4WellRack/mago4wellrack.h \
    Mago4S/Mago4sDilutionRack/mago4sdilutionrack.h \
    Mago4S/Mago4sSampleRack/mago4ssamplerack.h \
    Mago4S/Mago4sWellRack/mago4swellrack.h \
    Templates/listiterator.h \
    Instrument/configuration.h \
    Templates/singleton.h

FORMS    += mainmenu.ui

QT += xml