#include "kupi.h"
#include "ui_kupi.h"
#include "korpa.h"

kupi::kupi(QWidget *parent,int id) :
    QDialog(parent),
    ui(new Ui::kupi)
{
    ui->setupUi(this);
    korpa_id=id;

    createConnection();
    model = new QSqlTableModel(this);
    model->setTable("Proizvodi");
    model->setFilter("Dostupni_proizvodi>0");
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setSortingEnabled(true);
}

kupi::~kupi()
{
    delete ui;
}




void kupi::on_pbKupi_clicked()
{
    korpa o(this, korpa_id);
    o.setModal(true);
    o.exec();

}


void kupi::on_pbDodaj_clicked()
{
    QSqlDatabase db = QSqlDatabase::database();
    db.transaction();
    QSqlRelationalTableModel *model2=new QSqlRelationalTableModel;
    model2->setTable("Korpa");
    model2->select();
    selected = ui->tableView->selectionModel();
    QModelIndex rowIndex = selected->currentIndex();
    int rb=rowIndex.row();
    if(rb<0){

      return;
    }
    QSqlRecord record=model2->record();
    record.setValue("Ime_artikla",model->index(rb,0).data().toString());
    record.setValue("Cijena",model->index(rb,5).data().toReal());
    record.setValue("user_id",korpa_id);
    if(!model2->insertRecord(-1,record)){
      QMessageBox::warning(this,tr("Unos u korpu"),tr("Greska!"));
      db.rollback();

      qDebug() << db.lastError();
    }
    else{
      db.commit();
      QMessageBox::information(this,tr("Unos u korpu"),tr("Uspijesno uneseno"));
    }


    QSqlRecord record2=model->record();
    record2.setValue("Ime_proizvoda",model->index(rb,0).data().toString());
    record2.setValue("Zemlja_porijekla",model->index(rb,1).data().toString());
    record2.setValue("Proizvodjac",model->index(rb,2).data().toString());
    record2.setValue("Dostupni_proizvodi",model->index(rb,3).data().toInt()-1);
    record2.setValue("Stanje",model->index(rb,4).data().toString());
    record2.setValue("Cijena",model->index(rb,5).data().toReal());

    model->setRecord(rb,record2);
    model->submitAll();
    model->setFilter("Dostupni_proizvodi>0");
    ui->tableView->setModel(model);
}

