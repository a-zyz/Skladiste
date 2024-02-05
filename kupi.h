#ifndef KUPI_H
#define KUPI_H

#include "connection.h"
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QObject>
#include <QItemSelectionModel>
namespace Ui {
class kupi;
}

class kupi : public QDialog
{
    Q_OBJECT

public:
    explicit kupi(QWidget *parent = nullptr,int id=0);
    ~kupi();

private slots:


    void on_pbKupi_clicked();

    void on_pbDodaj_clicked();

private:
    Ui::kupi *ui;

    QSqlTableModel *model;
    QItemSelectionModel *selected;

    int korpa_id;
};

#endif // KUPI_H
