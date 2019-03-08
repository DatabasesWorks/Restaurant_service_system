#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include "login.h"
#include "registertel.h"
#include "deskchoose.h"
#include "administrator.h"
#include "waiterdlg.h"
#include "cookdlg.h"
#include "managerdlg.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_login_clicked();

    void on_register_clicked();

    void on_adminisator_clicked();

    void on_waiter_clicked();

    void on_cook_clicked();


    void on_managegr_clicked();

    void closeEvent(QCloseEvent *event);

    void on_Register_clicked();

private:
    Ui::MainWindow *ui;
    login logindialog;
    registertel inputtel;
    deskchoose deskchoosedialog;
    administrator administratordialog;
    waiterdlg waiterdialog;
    cookdlg cookdialog;
    Order orderdialog;
    waitingfor waitdialog;
    managerdlg managerdialog;
    cooking cookingdialog;


};

#endif // MAINWINDOW_H
