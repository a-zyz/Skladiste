#include "onama.h"
#include "ui_onama.h"

ONama::ONama(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ONama)
{
    ui->setupUi(this);
}

ONama::~ONama()
{
    delete ui;
}
