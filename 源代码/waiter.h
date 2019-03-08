#ifndef WAITER_H
#define WAITER_H

#include <QString>
#include "QHash"

class Waiter
{
public:
    Waiter();

    void getName(QString name);//读入用户名
    void getPassword(QString pwd);//读入密码
    void changeDesknum(const int &n);//改变服务员服务餐桌
    int &ReturnWaiterDesk();//返回服务员服务餐桌号
    QString &ReturnWaiterName();//返回服务员名
    QString &ReturnWaiterPassword();//返回服务员密码
    int &returnMarkTime();//返回服务员被评价的次数,即服务过的餐桌数
    void getMark(const int &n);//打一次分
    void getDeskNum(const int &n);//服务一桌
    void clearDeskNum(const int &n);//结束服务一桌
    QHash <int,int> &returnDeskNum();
    bool findDeskNum(const int &n);
private:
    QString name;
    QString password;
    int desknum = 0;
    QHash <int,int> WaiterMark;
    QHash <int,int> WaiterDeskNum;
};

#endif // WAITER_H
