#include "admin.h"
#include "ui_admin.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include "kupi.h"
#include "kupi.cpp"
#include "login.h"

admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
    createConnection();
}

admin::~admin()
{
    delete ui;
}

void admin::on_pushButton_clicked()
{
    QSqlDatabase db=QSqlDatabase::database();

    QString email=ui->leEmail->displayText();
    QString sifra=ui->leSifra->displayText();

    QSqlQuery query("SELECT * FROM Kupce");


    int mail = query.record().indexOf("E-mail");
    int pass = query.record().indexOf("Sifra");
    int id = query.record().indexOf("id");
    while (query.next())
    {
        qDebug()<<query.value(mail).toString();
        qDebug()<<query.value(pass).toString();
        if(email==query.value(mail).toString()&&sifra==query.value(pass).toString()){

            kupi l(this,query.value(id).toInt());
            l.setModal(true);
            l.exec();
            this->close();


        }

    }
    qDebug()<<db.lastError();
    qDebug()<<query.lastError();

}


void admin::on_pushButton_2_clicked()
{
    login f;
    f.setModal(true);
    f.exec();
    close();
}

