#ifndef KUPCI_H
#define KUPCI_H

#include <QDialog>
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
class kupci;
}

class kupci : public QDialog
{
    Q_OBJECT

public:
    explicit kupci(QWidget *parent = nullptr);
    ~kupci();

private:
    Ui::kupci *ui;

    QSqlTableModel *model;

};

#endif // KUPCI_H
