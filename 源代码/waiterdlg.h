#ifndef WAITERDLG_H
#define WAITERDLG_H

#include <QDialog>
#include "restaurant.h"
#include "database.h"
#include "serve.h"


namespace Ui {
class waiterdlg;
}

class waiterdlg : public QDialog
{
    Q_OBJECT

public:
    explicit waiterdlg(QWidget *parent = 0);
    ~waiterdlg();

    void showWaiterDesk(const QString &waiter);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void closeEvent(QCloseEvent *event);

private:
    Ui::waiterdlg *ui;
    serve s;
    int choosedesk;
    QString waitername;
    QString username;
};

#endif // WAITERDLG_H
