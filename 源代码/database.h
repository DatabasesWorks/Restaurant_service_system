#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QDebug>

class DataBase
{
public:
    static DataBase *Insitial();

     bool createConnection();

     bool findCustomer(const QString &name)
    {
        QSqlQuery customerquery;//创建顾客表

        customerquery.exec("select name  from user");
        while(customerquery.next())
        {
            if(customerquery.value(0).toString() == name)
            {
               return true;
            }
        }
        return false;
    }
    bool findPassword(const QString &psw)
    {
        QSqlQuery customerquery;//创建顾客表

        customerquery.exec("select password from user");
        while(customerquery.next())
        {
            if(customerquery.value(0).toString() == psw)
            {
               return true;
            }
        }
        return false;
    }
    void inserct(const QString &name,const QString &pwd);//不可删除


    bool findAdministrator(const QString &name)
   {
       QSqlQuery administratorquery;//创建管理员

       administratorquery.exec("select name  from administrator");
       while(administratorquery.next())
       {
           if(administratorquery.value(0).toString() == name)
           {
              return true;
           }
       }
       return false;
   }

    bool findPasswordAdministrator(const QString &psw)
    {
        QSqlQuery query;//创建管理员

        query.exec("select password from administrator");
        while(query.next())
        {
            if(query.value(0).toString() == psw)
            {
               return true;
            }
        }
        return false;
    }

    QString resdDeskState(const int &n)//读取餐桌状态
    {
        QSqlQuery query;//创建管理员

        query.exec("select * from desk");
        while(query.next())
        {
            if(query.value(0).toInt() == n && query.value(1).toString() == "用餐中")
            {
               return query.value(1).toString();
            }
        }
        return NULL;
    }

    void changeDeskState(const int &n)//更改餐桌状态
    {
       QSqlQuery query;//创建餐桌表

        query.prepare("UPDATE INTO desk(num,state) VALUES(?,?)");
        query.addBindValue(n);
        query.addBindValue("用餐中");

        if(!query.exec())
            qDebug()<<"搞事啊";
    }

    bool findWaiter(const QString &name)
   {
       QSqlQuery query;//创建管理员

       query.exec("select name  from waiter");
       while(query.next())
       {
           if(query.value(0).toString() == name)
           {
              return true;
           }
       }
       return false;
   }

    bool findPasswordWaiter(const QString &psw)
    {
        QSqlQuery query;//创建管理员

        query.exec("select password from waiter");
        while(query.next())
        {
            if(query.value(0).toString() == psw)
            {
               return true;
            }
        }
        return false;
    }
    bool findCook(const QString &name)
    {
        QSqlQuery query;

        query.exec("select name from cook");
        while(query.next())
        {
            if(query.value(0).toString() == name)
            return true;
        }
        return false;
    }
    bool findPasswordCook(const QString &pwd);

    void insertInDishMap(const QString &dishname,const QString &dishprice);//插入菜单表
    void insertInCook(const QString &name,const QString &pwd);//插入厨师表

private:
    DataBase() {}
    static DataBase *database;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");//创建数据库
};

#endif // DATABASE_H
