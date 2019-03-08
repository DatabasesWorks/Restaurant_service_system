#ifndef COOKING_H
#define COOKING_H

#include <QDialog>
#include "restaurant.h"
#include <QCloseEvent>


namespace Ui {
class cooking;
}

class cooking : public QDialog
{
    Q_OBJECT

public:
    explicit cooking(QWidget *parent = 0);
    ~cooking();

    void showDish(int n);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void closeEvent(QCloseEvent *event);

private:
    Ui::cooking *ui;
    int num;
};

#endif // COOKING_H
