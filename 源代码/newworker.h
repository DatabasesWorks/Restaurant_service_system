#ifndef NEWWORKER_H
#define NEWWORKER_H

#include <QDialog>
#include "restaurant.h"
namespace Ui {
class newWorker;
}

class newWorker : public QDialog
{
    Q_OBJECT

public:
    explicit newWorker(QWidget *parent = 0);
    ~newWorker();
    QString name;
    QString password;

private slots:
    void on_pushButton_clicked();

private:
    Ui::newWorker *ui;
};

#endif // NEWWORKER_H
