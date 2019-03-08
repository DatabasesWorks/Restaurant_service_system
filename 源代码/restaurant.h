#ifndef RESTAURANT_H
#define RESTAURANT_H


#include "desk.h"
#include <QCloseEvent>
#include "QHash"
#include "cook.h"
#include "waiter.h"
#include "database.h"

class Restaurant
{
public:
    Desk desk;//当前用户
    QHash <int,Customer> CustomerHash;//存储从数据库中读取的全部顾客账户
    QHash <int,Cook> CookHash;//从数据库读取厨师账户
    QHash <int,Waiter> WaiterHash;//从数据库读取服务员账户
    QHash <QString,QString> AdministratorHash;//从数据库读取管理员账户
    QHash <QString,QString> ManagerHash;//从数据库读取餐厅经理账户
    QHash <int,OneDish> DishHash;//从数据库读取菜单表
    QHash <int,Desk> DeskHash;//从数据库读取餐桌表

    static Restaurant *Instance();
    void InCustomerHash();//读取用户表
    void InCookHash();//读取厨师表
    void InWaiterHash();//读取服务员表
    void InAdministratorHash();//读取系统管理员表
    void InDishHash();//读取菜单表
    void InDeskHash();//读取餐桌表
    void InManagerHash();//读取餐厅经理表

    void FlashDishHash();//清空菜单表
    //void Flash

    void InsertCustomer();//写入数据库顾客表
    void InsertCook();//写入厨师表
    void InsertWaiter();
    void InsertDesk();
    void InsertDish();//写入餐单表

    bool FindCustomerName(const QString &name);//查找顾客用户名
    bool FindCustomerPassword(const QString &pwd);//查找顾客密码
    bool FindWaiterName(const QString &name);//查询服务员名
    bool FindWaiterPassword(const QString &pwd);//查询服务员密码
    bool FindCookName(const QString &name);//查询厨师名
    bool FindCookPassword(const QString &pwd);//查询厨师密码
    bool FindManagerName(const QString &name);//查询餐厅经理用户名
    bool FindManagerPassword(const QString &pwd);//查询餐厅经理密码

    int countCustomer();//统计顾客总数
    void getCustomer(const QString &name,const QString &pwd);//新建用户名
    bool ChangeDeskState(int n);//改变哈希表餐桌状态
    void ChangeDeskUser(QString &name, int n);//改变餐桌用户名
    void ChangeCustomerProcess(const QString &name);//改变用户状态
    int ReturnCustomerProcess(const QString &name);//返回用户状态
    //void ChangeWaiterProcess(const QString &name);//改变服务员状态

    int ReturnAllDeskNum();//统计餐桌数
    void GetDeskDish(const QString &dishname, const QString &dishprice, const int &desknum, const int dishnum);//一条条录入菜单(餐桌的菜)
    void getWaiterHash(const QString &name,const QString &pwd);//录入服务员表
    void getCookHash(const QString &name,const QString &pwd);//录入厨师表
    void getDishHash(const QString &dishname, const QString &dishprice,const int &n);//录入哈希表菜单
    Restaurant(){}
    static Restaurant *restaurant;
};

#endif // RESTAURANT_H
