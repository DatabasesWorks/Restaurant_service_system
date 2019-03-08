#ifndef NEWCOOK_H
#define NEWCOOK_H

#include <QDialog>
#include "restaurant.h"

namespace Ui {
class newCook;
}

class newCook : public QDialog
{
    Q_OBJECT

public:
    explicit newCook(QWidget *parent = 0);
    ~newCook();

    QString name;
    QString password;
private slots:
    void on_pushButton_clicked();

private:
    Ui::newCook *ui;
};

#endif // NEWCOOK_H
