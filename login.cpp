#include "login.h"
#include "ui_login.h"
#include "admin.h"
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlRecord>
#include <QSqlError>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    admin j;

    j.exec();
    close();
}


void login::on_pbNapraviNalog_clicked()
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel *model = new QSqlTableModel;

    model->setTable("Kupce");

    db.transaction();

    QSqlRecord record = model->record();

    if(ui->leIme->text().isEmpty()){
        QMessageBox::warning(this,tr("Unos kupaca"),tr("Ime kupca ne smije biti prazno!"));
            ui->leIme->setStyleSheet("border: 1px solid red; background-color: rgb(255, 255, 255);");
        return;
    }
    else if(ui->lePrezime->text().isEmpty()){
        QMessageBox::warning(this,tr("Unos kupaca"),tr("Prezime kupca ne smije biti prazno!"));
            ui->lePrezime->setStyleSheet("border: 1px solid red; background-color: rgb(255, 255, 255);");
        return;
    }
    else if(ui->leMail->text().isEmpty()){
        QMessageBox::warning(this,tr("Unos kupca"),tr("Email kupca ne smije biti prazan!"));
            ui->leMail->setStyleSheet("border: 1px solid red; background-color: rgb(255, 255, 255);");
        return;
    }
    else if(ui->leTelefon->text().isEmpty()){
        QMessageBox::warning(this,tr("Unos kupca"),tr("Telefon kupca ne smije biti prazan!"));
        ui->leTelefon->setStyleSheet("border: 1px solid red; background-color: rgb(255, 255, 255);");
        return;
    }
    else if(ui->leSifra->text().isEmpty()){
        QMessageBox::warning(this,tr("Unos kupca"),tr("Sifra kupca ne smije biti prazan!"));
        ui->leSifra->setStyleSheet("border: 1px solid red; background-color: rgb(255, 255, 255);");
        return;
    }



    record.setValue("Ime",ui->leIme->displayText());
    record.setValue("Prezime",ui->lePrezime->displayText());
    record.setValue("Sifra",ui->leSifra->displayText());
    record.setValue("E-mail", ui->leMail->displayText());
    record.setValue("Telefon",ui->leTelefon->displayText());
    record.setValue("Adresa",ui->leAdresa->displayText());




    if(!model->insertRecord(-1,record)){
        QMessageBox::warning(this,tr("Unos kupca"),tr("Greska!"));
        db.rollback();

        qDebug() << db.lastError();
    }
    else{
        db.commit();
        QMessageBox::information(this,tr("Unos kupca"),tr("Uspijesno unesen"));
    }

    close();
}

