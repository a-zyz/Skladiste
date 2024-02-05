#ifndef PROIZVODI_H
#define PROIZVODI_H

#include <QDialog>
#include "connection.h"
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QObject>

namespace Ui {
class Proizvodi;
}

class Proizvodi : public QDialog
{
    Q_OBJECT

public:
    explicit Proizvodi(QWidget *parent = nullptr);
    ~Proizvodi();

private:
    Ui::Proizvodi *ui;

    QSqlTableModel *model;

};


#endif // PROIZVODI_H
