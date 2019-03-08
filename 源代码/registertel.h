#ifndef REGISTERTEL_H
#define REGISTERTEL_H

#include <QDialog>
#include <QMessageBox>
#include "registeraccount.h"

namespace Ui {
class registertel;
}

class registertel : public QDialog
{
    Q_OBJECT

public:
    explicit registertel(QWidget *parent = 0);
    ~registertel();

private slots:
    void on_confirmButton_clicked();

private:
    Ui::registertel *ui;
    registerAccount registerdialog;
};

#endif // REGISTERTEL_H
