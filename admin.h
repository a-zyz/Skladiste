#ifndef ADMIN_H
#define ADMIN_H
#include <QSqlDatabase>
#include <QDialog>

namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::admin *ui;

};

#endif // ADMIN_H
