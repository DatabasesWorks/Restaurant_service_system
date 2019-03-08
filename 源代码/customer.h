#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>

class Customer
{
  public:
    void CustomerIn(const QString &name,const QString &pwd)
    {
        this->name = name;
        this->password = pwd;
    }

    void ChangeTable(const int &table)
    {
        this->table = table;
    }

    QString &returnCustomerName();//返回用户名
    QString &returnPassword();//返回密码
    void changeName(const QString mname);//修改用户名
    int &returnProcess();//修改当前顾客状态

  private:
    QString name;
    QString password;
    int process = 0;//当前顾客状态：1.点菜，2.等待
    int table;
};

#endif // CUSTOMER_H
