#ifndef DESK_H
#define DESK_H

#include "customer.h"
#include "dish.h"

class Desk
{
public:
    bool WaiterChoseOrNot = false;
    bool CookChoseOrNot = false;

    void getCustomer(const QString &name,const QString &pwd)
    {
        this->cuser.CustomerIn(name,pwd);
    }
    void changeDeskNumber(const int &n)
    {
        this->desknumber = n;
    }

    Customer &returnCustmer()
    {
        return this->cuser;
    }

    Dish &returnDish()
    {
        return this->mdish;
    }
   int returnDeskNum()//返回餐桌号
    {
        return this->desknumber;
    }
   void ChangeDeskState(const QString sta);
   QString &returnDeskState();//返回餐桌状态
   void getDish(const QString &dishname,const QString &dishprice,int dishnum);//录入一道菜
   void getRequest(const QString &request);//读取用户需求
   const QString returnRequest();
   void inputCookName(const QString &name);
   QString &returnCookName();
private:
    QString request;
    Customer cuser;
    Dish mdish;
    QString state;
    int desknumber;
    QString cookname;
    //int dishnum;//菜的数量


};
#endif // DESK_H
