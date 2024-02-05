#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "onama.h"
#include "proizvodi.h"
#include "kupci.h"
#include "kupi.h"
#include "admin.h"
#include "admin.cpp"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pbONama_clicked()
{
    ONama x;
    x.setModal(true);
    x.exec();
}




void MainWindow::on_pbProizvodi_clicked()
{
    Proizvodi f;
    f.setModal(true);
    f.exec();
}


void MainWindow::on_pbKupci_clicked()
{
    kupci z;
    z.setModal(true);
    z.exec();
}


void MainWindow::on_pbKupci_2_clicked()
{
    admin l;
    l.setModal(true);
    l.exec();

}

