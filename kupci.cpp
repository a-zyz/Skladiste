#include "kupci.h"
#include "ui_kupci.h"

kupci::kupci(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::kupci)
{
    ui->setupUi(this);

    createConnection();
    model = new QSqlTableModel(this);
    model->setTable("Kupce");
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

kupci::~kupci()
{
    delete ui;
}
