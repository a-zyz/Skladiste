#ifndef KORPA_H
#define KORPA_H

#include "connection.h"
#include <QMessageBox>
#include <QSqlRelationalTableModel>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QObject>

namespace Ui {
class korpa;
}

class korpa : public QDialog
{
    Q_OBJECT

public:
    explicit korpa(QWidget *parent = nullptr,int id=0);
    ~korpa();

private slots:
    void on_pushButton_clicked();

private:
    Ui::korpa *ui;
    int user_id;
    QSqlRelationalTableModel *model;
};

#endif // KORPA_H
