#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    ui->StartSession->setVisible((false));

}

MainMenu::~MainMenu()
{
    delete ui;
}
