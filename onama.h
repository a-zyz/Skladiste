#ifndef ONAMA_H
#define ONAMA_H

#include <QDialog>

namespace Ui {
class ONama;
}

class ONama : public QDialog
{
    Q_OBJECT

public:
    explicit ONama(QWidget *parent = nullptr);
    ~ONama();

private:
    Ui::ONama *ui;
};

#endif // ONAMA_H
