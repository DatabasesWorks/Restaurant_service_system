#ifndef MANAGERDLG_H
#define MANAGERDLG_H

#include <QDialog>
#include "restaurant.h"
#include "waiterassess.h"
#include "cookassess.h"

namespace Ui {
class managerdlg;
}

class managerdlg : public QDialog
{
    Q_OBJECT

public:
    explicit managerdlg(QWidget *parent = 0);
    ~managerdlg();

    void showIt();
private slots:
    void on_tableWidget_doubleClicked(const QModelIndex &index);

    void on_tableWidget_2_doubleClicked(const QModelIndex &index);

private:
    Ui::managerdlg *ui;
    waiterassess wa;
    cookassess ca;
};

#endif // MANAGERDLG_H
