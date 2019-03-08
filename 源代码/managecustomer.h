#ifndef MANAGECUSTOMER_H
#define MANAGECUSTOMER_H

#include <QDialog>
#include "restaurant.h"

namespace Ui {
class manageCustomer;
}

class manageCustomer : public QDialog
{
    Q_OBJECT

public:
    explicit manageCustomer(QWidget *parent = 0);
    ~manageCustomer();

    void showCustomer();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void OnBtnClicked();

private:
    Ui::manageCustomer *ui;
};

#endif // MANAGECUSTOMER_H
