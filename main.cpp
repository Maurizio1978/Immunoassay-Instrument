#include "mainmenu.h"
#include <QApplication>
#include <QFileDialog>
//#include <reader.h>
#include <fstream>
#include <instrumentcreator.h>
#include <Templates/matrix.h>
//#include <SampleObservers/sampleobserver.h>

tthread::mutex aspiration_mutex;
tthread::condition_variable aspiration_con;
int startVolume = 50;
bool goDown = false;

void PumpThread(void *param)
{
  logger::Info("PumpThread >>> ");
  while (startVolume > 0)
  {
      startVolume -= 1;
      //tthread::this_thread::sleep_for(tthread::chrono::seconds(1));
      if ((startVolume % 5) == 0)
      {
            logger::Info("PumpThread >>> residual volume = %d", startVolume);
            aspiration_mutex.lock();
            goDown = true;
            aspiration_con.notify_all();
            aspiration_mutex.unlock();
      }
  }

  logger::Info("PumpThread <<< ");
}

void MotorZThread(void *param)
{
    while (true)
    {
          logger::Info("MotorZThread >>> ");
          aspiration_mutex.lock();
          while (!goDown)
              aspiration_con.wait(aspiration_mutex);

          logger::Info("MotorZThread >>> Going Down");
          goDown = false;
          aspiration_mutex.unlock();

          logger::Info("MotorZThread <<< ");
    }
}
// main function, loop
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu w;
    try
    {
        logger::Info("Main >>> main::Application Start");
        Templates::TMatrix<int> matrix(3, 3);

        time_t rawtime;
        time(&rawtime);

        tm *bd;
        bd = localtime(&rawtime);
        bd->tm_mday = 1;
        bd->tm_mon = 1;
        bd->tm_year = 100;
        Sample sample("marco", "123", bd);

        SamplesList samplesList;
        samplesList.AddSample(sample);

//        std::string configurationPath = QDir::currentPath().toStdString();
//        configurationPath += "/Configuration.xml";

//        QFile file(configurationPath.c_str());
//        if (!file.open(QIODevice::ReadOnly))
//        {
//            logger::GetInstance().operator <<("Error Opening Configuration.xml");
//            throw;
//        }
//        // Set data into the QDomDocument before processing
//        QDomDocument configurationXml;
//        configurationXml.setContent(&file);
//        file.close();

//        QString instrumentVersion("");
//        QDomElement root = configurationXml.documentElement();
//        QDomElement element = root.firstChild().toElement();
//        while (!element.isNull())
//        {
//            if (element.tagName() == "instrument")
//                instrumentVersion = element.attribute("type", "");

//            element = element.nextSibling().toElement();
//        }
//        if (instrumentVersion.isEmpty())
//            throw;

//        tthread::thread mt(MotorZThread, NULL);
//        tthread::thread pt(PumpThread, NULL);


//        Configuration instrumentConfiguration;

        InstrumentCreator::ReadXML();

        Builder *instrumentBuilder;
        if (InstrumentCreator::m_InstrumentVersion == "mago4")
            instrumentBuilder = new Mago4Builder();
        else if (InstrumentCreator::m_InstrumentVersion == "mago4s")
            instrumentBuilder = new Mago4sBuilder();

        InstrumentCreator instrumentCreator(instrumentBuilder, &samplesList);
        instrumentCreator.CreateInstrument();



//        pt.join();
//        mt.join();
        logger::Info("Main <<< main::Application End");
    }
    catch (...)
    {

    }

    w.show();
    a.exec();
}
