#ifndef ORDER_H
#define ORDER_H

#include <QDialog>
#include <QHeaderView>
#include <QAbstractItemView>
#include "waitingfor.h"
#include "restaurant.h"

namespace Ui {
class Order;
}

class Order : public QDialog
{
    Q_OBJECT

public:
    explicit Order(QWidget *parent = 0);
    ~Order();
    void showDisH();

private slots:
    void on_tableWidget_cellDoubleClicked(int row, int column);

    void on_pushButton_clicked();

    void OnBtnClicked();

    void closeEvent(QCloseEvent *event);

private:
    Ui::Order *ui;
    waitingfor wf;
};

#endif // ORDER_H
