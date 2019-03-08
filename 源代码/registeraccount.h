#ifndef REGISTERACCOUNT_H
#define REGISTERACCOUNT_H

#include <QDialog>
#include "restaurant.h"
#include "deskchoose.h"
#include <QMessageBox>

namespace Ui {
class registerAccount;
}

class registerAccount : public QDialog
{
    Q_OBJECT

public:
    explicit registerAccount(QWidget *parent = 0);

    ~registerAccount();
private slots:
    void on_register_2_clicked();


private:
    Ui::registerAccount *ui;
    deskchoose des;
};

#endif // REGISTERACCOUNT_H


