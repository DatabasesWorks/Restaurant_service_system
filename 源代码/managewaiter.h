#ifndef MANAGEWAITER_H
#define MANAGEWAITER_H

#include <QDialog>
#include "restaurant.h"
#include "newworker.h"

namespace Ui {
class manageWaiter;
}

class manageWaiter : public QDialog
{
    Q_OBJECT

public:
    explicit manageWaiter(QWidget *parent = 0);
    ~manageWaiter();

    void showWaiter();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

     void OnBtnClicked();

private:
    Ui::manageWaiter *ui;
    newWorker nw;

};

#endif // MANAGEWAITER_H
