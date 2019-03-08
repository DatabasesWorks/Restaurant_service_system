#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("欢迎光临"));//窗口标题
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_clicked()
{
    logindialog.ChangeType(1);
    if(logindialog.exec() == QDialog::Accepted)
    {
        logindialog.close();
        switch(Restaurant::Instance()->ReturnCustomerProcess(Restaurant::Instance()->desk.returnCustmer().returnCustomerName()))
        {
            case 0:
                    deskchoosedialog.show();
                    break;
            case 1:
             {
                    QHash<int,Desk>::iterator i;

                    for(i=Restaurant::Instance()->DeskHash.begin();i!=Restaurant::Instance()->DeskHash.end();++i)
                        {
                             if(i.value().returnCustmer().returnCustomerName() == Restaurant::Instance()->desk.returnCustmer().returnCustomerName())
                                 {
                                        Restaurant::Instance()->desk.changeDeskNumber(i.value().returnDeskNum());
                                 }
                        }
                    orderdialog.showDisH();
                    orderdialog.show();
                    break;
             }
            case 2:
            {
                     QHash<int,Desk>::iterator i;
                     for(i=Restaurant::Instance()->DeskHash.begin();i!=Restaurant::Instance()->DeskHash.end();++i)
                        {
                            if(i.value().returnCustmer().returnCustomerName() == Restaurant::Instance()->desk.returnCustmer().returnCustomerName())
                                {
                                    Restaurant::Instance()->desk.changeDeskNumber(i.value().returnDeskNum());

                                }
                        }
                    waitdialog.showDish();
                    waitdialog.show();
                    break;
            }
        }
    }
}

void MainWindow::on_register_clicked()
{
    inputtel.show();
}

void MainWindow::on_adminisator_clicked()
{
    logindialog.ChangeType(2);
    if(logindialog.exec() == QDialog::Accepted)
    {
        logindialog.close();
        administratordialog.show();
    }
}

void MainWindow::on_waiter_clicked()
{
    logindialog.ChangeType(3);
    if(logindialog.exec() == QDialog::Accepted)
    {
        logindialog.close();
        waiterdialog.show();
    }
}

void MainWindow::on_cook_clicked()
{
    logindialog.ChangeType(4);
    if(logindialog.exec() == QDialog::Accepted)
    {
        QHash<int,Cook>::iterator i;

        for(i=Restaurant::Instance()->CookHash.begin();i!=Restaurant::Instance()->CookHash.end();++i)
           {
               if(i.value().ReturnCookName() == logindialog.name && (i.value().returnDeskNum()!= 0))
                   {
                        cookingdialog.showDish(i.value().returnDeskNum());
                        logindialog.close();
                        cookingdialog.show();
                        break;
                   }
               else
                   {
                        cookdialog.showCookDesk(logindialog.name);
                        logindialog.close();
                        cookdialog.show();
                        break;
                   }
           }

    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton rb = QMessageBox::information(NULL,"提示","是否将数据存入数据库？",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
    if(rb == QMessageBox::Yes)
       {
            //qDebug()<<"fuck lu";
            Restaurant::Instance()->InsertCustomer();
            Restaurant::Instance()->InsertDish();
            Restaurant::Instance()->InsertCook();
        }
    else
        {

        }
}


void MainWindow::on_managegr_clicked()
{
    logindialog.ChangeType(5);
    if(logindialog.exec() == QDialog::Accepted)
    {
        logindialog.close();
        managerdialog.showIt();
        managerdialog.show();
    }
}

void MainWindow::on_Register_clicked()
{
    inputtel.show();
}
