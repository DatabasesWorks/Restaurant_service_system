#ifndef WAITINGFOR_H
#define WAITINGFOR_H

#include <QDialog>
#include "dish.h"
#include "evaluate.h"
#include "restaurant.h"
#include "pay.h"

namespace Ui {
class waitingfor;
}

class waitingfor : public QDialog
{
    Q_OBJECT

public:
    explicit waitingfor(QWidget *parent = 0);
    ~waitingfor();

    void showDish();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void closeEvent(QCloseEvent *event);

private:
    Ui::waitingfor *ui;
    evaluate eva;
    pay p;
};

#endif // WAITINGFOR_H
