#ifndef DESKCHOOSE_H
#define DESKCHOOSE_H

#include <QDialog>
//#include "customer.h"
//#include "login.h"
#include "order.h"
//#include "desk.h"
#include "restaurant.h"

namespace Ui {
class deskchoose;
}

class deskchoose : public QDialog
{
    Q_OBJECT

public:
    explicit deskchoose(QWidget *parent = 0);
    ~deskchoose();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_sure_clicked();

    void on_exit_clicked();

    void setUnable(int n);

    void setAble(int &n);

    bool IsDeskUsed(int &n);


private:
    Ui::deskchoose *ui;
    Customer customer;
    Order o;
};

#endif // DESKCHOOSE_H
