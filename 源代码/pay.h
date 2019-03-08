#ifndef PAY_H
#define PAY_H

#include <QDialog>
#include "restaurant.h"

namespace Ui {
class pay;
}

class pay : public QDialog
{
    Q_OBJECT

public:
    explicit pay(QWidget *parent = 0);
    ~pay();

    void showDish();

private slots:
    void on_pushButton_clicked();

private:
    Ui::pay *ui;
};

#endif // PAY_H
