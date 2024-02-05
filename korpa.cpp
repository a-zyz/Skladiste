#include "korpa.h"
#include "ui_korpa.h"
#include <QSqlRelationalTableModel>

korpa::korpa(QWidget *parent,int id) :
    QDialog(parent),
    ui(new Ui::korpa)
{
    ui->setupUi(this);
    user_id=id;

    createConnection();
    model = new QSqlRelationalTableModel;
    model->setTable("Korpa");
    model->setFilter("user_id LIKE '"+ QString::number(id)+"'");
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->hideColumn(2);
    ui->tableView->resizeColumnsToContents();

    qDebug()<<model->lastError();
}

korpa::~korpa()
{
    delete ui;

}

void korpa::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::database();
    QString s="DELETE FROM Korpa WHERE user_id LIKE '"+ QString::number(user_id)+"'";
    QSqlQuery query;

    query.exec(s);
    qDebug()<<query.lastError();
    model->setTable("Korpa");
    model->setFilter("user_id LIKE '"+ QString::number(user_id)+"'");
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->hideColumn(2);
    ui->tableView->resizeColumnsToContents();
}

