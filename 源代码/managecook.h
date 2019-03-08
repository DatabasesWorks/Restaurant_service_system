#ifndef MANAGECOOK_H
#define MANAGECOOK_H

#include <QDialog>
#include "restaurant.h"
#include "newcook.h"

namespace Ui {
class manageCook;
}

class manageCook : public QDialog
{
    Q_OBJECT

public:
    explicit manageCook(QWidget *parent = 0);
    ~manageCook();

    void showCook();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

     void OnBtnClicked();

private:
    Ui::manageCook *ui;
    newCook nc;
};

#endif // MANAGECOOK_H
