#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QDialog>
#include "managecook.h"
#include "managecustomer.h"
#include "managedish.h"
#include "managewaiter.h"

namespace Ui {
class administrator;
}

class administrator : public QDialog
{
    Q_OBJECT

public:
    explicit administrator(QWidget *parent = 0);
    ~administrator();



private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::administrator *ui;
    manageCustomer mc;
    manageDish md;
    manageWaiter mw;
    manageCook mco;
};

#endif // ADMINISTRATOR_H
