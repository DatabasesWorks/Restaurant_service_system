#include <QApplication>
#include "mainwindow.h"
#include"database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QMessageBox::StandardButton rb = QMessageBox::information(NULL,"提示","是否读取数据库数据",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
    if(rb == QMessageBox::Yes)
       {
        if(!DataBase::Insitial()->createConnection())
        {
            return 0;
        }
        Restaurant::Instance()->InCustomerHash();//读入顾客数据
        Restaurant::Instance()->InDeskHash();//读入餐桌数据
        Restaurant::Instance()->InCookHash();//
        Restaurant::Instance()->InAdministratorHash();
        Restaurant::Instance()->InWaiterHash();
        Restaurant::Instance()->InDishHash();
        Restaurant::Instance()->InManagerHash();
      }
    else
        {
            qDebug()<<"dudul";
        }



    return a.exec();
}
