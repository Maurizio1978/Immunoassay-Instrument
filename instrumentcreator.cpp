#include <instrumentcreator.h>

QString InstrumentCreator::m_InstrumentVersion;

//InstrumentCreator::InstrumentCreator(Builder *instrumentBuilder)
//{
//    m_InstrumentBuilder = instrumentBuilder;
//}

void InstrumentCreator::Update()
{

}

InstrumentCreator::~InstrumentCreator()
{

}

Instrument* InstrumentCreator::GetInstrument()
{
    return m_InstrumentBuilder->GetInstrument();
}

void InstrumentCreator::ReadXML()
{
    try
    {
        logger::Info("Configuration >>");
        std::string configurationPath = QDir::currentPath().toStdString();
        configurationPath += "/Configuration.xml";

        QFile file(configurationPath.c_str());
        if (!file.open(QIODevice::ReadOnly))
        {
            logger::Error("Configuration:: Error Opening Configuration.xml!");
            throw;
        }
        // Set data into the QDomDocument before processing
        QDomDocument configurationXml;
        configurationXml.setContent(&file);
        file.close();

        QDomElement root = configurationXml.documentElement();
        QDomElement element = root.firstChild().toElement();
        while (!element.isNull())
        {
            if (element.tagName() == "instrument")
                m_InstrumentVersion = element.attribute("type", "");

            element = element.nextSibling().toElement();
        }

        if (m_InstrumentVersion.isEmpty())
        {
            logger::Error("Configuration:: Error Version is empty!");
            //throw ConfigurationException(m_InstrumentVersion.toStdString());
        }
        logger::Info("Instrument version = %s", m_InstrumentVersion.toStdString());
        logger::Info("Configuration <<");
    }
    catch (ConfigurationException &cException)
    {
       logger::Info("Configuration Parameter = %s is missing!", cException.GetError());
    }
}

void InstrumentCreator::CreateInstrument()
{
    try
    {
        m_InstrumentBuilder->BuildNewInstrument();

        m_InstrumentBuilder->BuildPlateRack();
        m_InstrumentBuilder->BuildSampleRack();
        m_InstrumentBuilder->BuildDilutionRack();
        m_InstrumentBuilder->BuildReagentRack();
    }
    catch (...)
    {
    }
}
