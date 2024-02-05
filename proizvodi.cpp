#include "proizvodi.h"
#include "ui_proizvodi.h"
Proizvodi::Proizvodi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Proizvodi)
{
    ui->setupUi(this);

    createConnection();
    model = new QSqlTableModel(this);
    model->setTable("Proizvodi");
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

Proizvodi::~Proizvodi()
{
    delete ui;
}
