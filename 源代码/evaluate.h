#ifndef EVALUATE_H
#define EVALUATE_H

#include <QDialog>
#include "restaurant.h"

namespace Ui {
class evaluate;
}

class evaluate : public QDialog
{
    Q_OBJECT

public:
    explicit evaluate(QWidget *parent = 0);
    ~evaluate();

private slots:
    void on_pushButton_clicked();

private:
    Ui::evaluate *ui;
};

#endif // EVALUATE_H
