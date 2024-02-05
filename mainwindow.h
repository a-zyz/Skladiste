#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "connection.h"
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QObject>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pbONama_clicked();



    void on_pbProizvodi_clicked();

    void on_pbKupci_clicked();

    void on_pbKupci_2_clicked();

private:
    Ui::MainWindow *ui;

    QSqlTableModel *model;
};
#endif // MAINWINDOW_H
