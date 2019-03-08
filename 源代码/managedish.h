#ifndef MANAGEDISH_H
#define MANAGEDISH_H

#include <QDialog>
#include "restaurant.h"

namespace Ui {
class manageDish;
}

class manageDish : public QDialog
{
    Q_OBJECT

public:
    explicit manageDish(QWidget *parent = 0);
    ~manageDish();

    void showDishMap();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void OnBtnClicked();

private:
    Ui::manageDish *ui;

};

#endif // MANAGEDISH_H
