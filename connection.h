#ifndef CONNECTION_H
#define CONNECTION_H


#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
static bool createConnection ()
{
    QSqlDatabase db = QSqlDatabase::addDatabase ("QSQLITE");
    db.setDatabaseName("C:/Users/edinn/Downloads/SKLADISTE_PROJEKAT/SKLADISTE PROJEKAT/skladiste.db");
    if (!db.open())
    {

        QMessageBox::critical(nullptr, QObject::tr("Baza ne može biti otvorena"),
                              QObject::tr("Konekcija sa bazom nije uspjela.\n"
                                          "Kliknite na Cancel za izlaz."),
                              QMessageBox::Cancel);

        return false;

    }
    return true;
}

#endif // CONNECTION_H
