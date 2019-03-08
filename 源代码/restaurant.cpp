#include "restaurant.h"

Restaurant *Restaurant::restaurant = NULL;

Restaurant *Restaurant::Instance()
{
    if(restaurant == NULL)
        restaurant = new Restaurant();
    return restaurant;
}

void Restaurant::InCustomerHash()
{
    QSqlQuery query;
    Customer cus;
    int i = 1;

    query.exec("select * from user");
    while(query.next())
    {
       cus.CustomerIn(query.value(0).toString(),query.value(1).toString());
       qDebug()<<query.value(0).toString()<<query.value(1).toString()<<"顾客";
        CustomerHash.insert(i,cus);
        i++;
    }
}

void Restaurant::InCookHash()
{
    QSqlQuery query;
    Cook c;
    int i = 1;

    query.exec("select * from cook");
    while(query.next())
    {
       c.CookIn(query.value(0).toString(),query.value(1).toString());
       qDebug()<<query.value(0).toString()<<query.value(1).toString()<<"厨师";
       CookHash.insert(i,c);
        i++;
    }
}

 void Restaurant::InWaiterHash()
 {
     QSqlQuery query;
     Waiter w;
     int i = 1;

     query.exec("select * from waiter");
     while(query.next())
     {
        w.getName(query.value(0).toString());
        w.getPassword(query.value(1).toString());
        qDebug()<<query.value(0).toString()<<query.value(1).toString()<<"服务员";
        WaiterHash.insert(i,w);
        i++;
     }
 }

 void Restaurant::InDishHash()
 {

     QSqlQuery query;
     OneDish od;
     int i = 1;

     query.exec("select * from dish");
     while(query.next())
     {
        od.getDishName(query.value(0).toString());
        od.getDishPrice(query.value(1).toString());
        //od.getDish(query.value(0).toString(),query.value(1).toString(),"未做");
        qDebug()<<query.value(0).toString()<<query.value(1).toString()<<"菜单";
        DishHash.insert(i,od);
        i++;
     }
 }

 void Restaurant::InAdministratorHash()
 {
     QSqlQuery query;
     int i = 1;

     query.exec("select * from admini");
     while(query.next())
     {
        AdministratorHash.insert(query.value(0).toString(),query.value(1).toString());
        qDebug()<<query.value(0).toString()<<query.value(1).toString()<<"餐厅管理员";
        i++;
     }
 }

 void Restaurant::InDeskHash()
 {
     QSqlQuery query;
     Desk desk;
     int i = 1;

     query.exec("select * from desk");
     while(query.next())
     {
        desk.changeDeskNumber(query.value(0).toInt());
        desk.ChangeDeskState(query.value(1).toString());
        qDebug()<<query.value(0).toInt()<<query.value(1).toString()<<"餐桌";
        DeskHash.insert(i,desk);
        i++;
     }

 }

void Restaurant::FlashDishHash()
{
    QHash<int,OneDish>::iterator i;

    for(i=DishHash.begin();i!=DishHash.end();++i)
     {
        DishHash.erase(i);
     }
}

void Restaurant::InManagerHash()
{
    QSqlQuery query;
    int i = 1;

    query.exec("select * from manager");
    while(query.next())
    {
       ManagerHash.insert(query.value(0).toString(),query.value(1).toString());
       qDebug()<<query.value(0).toString()<<query.value(1).toString()<<"餐厅经理";
       i++;
    }
}

 void Restaurant::InsertCustomer()
 {
     QSqlQuery query;
     QHash<int,Customer>::iterator i;

     query.exec("delete from user");

     for(i=CustomerHash.begin();i!=CustomerHash.end();++i)
      {
            DataBase::Insitial()->inserct(i.value().returnCustomerName(),i.value().returnPassword());
      }
 }

 void Restaurant::InsertDish()
 {
     QSqlQuery query;
     QHash<int,OneDish>::iterator i;

     query.exec("delete from dish");

     for(i=DishHash.begin();i!=DishHash.end();++i)
      {
           DataBase::Insitial()->insertInDishMap(i.value().putDishName(),i.value().putDishPrice());
      }
 }

 void Restaurant::InsertCook()
 {
     QHash<int,Cook>::iterator i;

     for(i=CookHash.begin();i!=CookHash.end();++i)
      {
           DataBase::Insitial()->insertInDishMap(i.value().ReturnCookName(),i.value().ReturnCookPassword());
      }

 }

bool Restaurant::FindCustomerName(const QString &name)
{
    QHash<int,Customer>::iterator i;

    for(i=CustomerHash.begin();i!=CustomerHash.end();++i)
    {
        if(i.value().returnCustomerName() == name)
             return true;
    }

    return false;
}

bool Restaurant::FindCustomerPassword(const QString &pwd)
{
    QHash<int,Customer>::iterator i;

    for(i=CustomerHash.begin();i!=CustomerHash.end();++i)
    {
        if(i.value().returnPassword() == pwd)
             return true;
    }

    return false;
}

bool Restaurant::FindWaiterName(const QString &name)
{
    QHash<int,Waiter>::iterator i;

    for(i=Restaurant::Instance()->WaiterHash.begin();i!=Restaurant::Instance()->WaiterHash.end();++i)
    {
        if(i.value().ReturnWaiterName() == name)
             return true;
    }

    return false;
}

bool Restaurant::FindWaiterPassword(const QString &pwd)
{
    QHash<int,Waiter>::iterator i;

    for(i=Restaurant::Instance()->WaiterHash.begin();i!=Restaurant::Instance()->WaiterHash.end();++i)
    {
        if(i.value().ReturnWaiterPassword() == pwd)
             return true;
    }

    return false;
}

bool Restaurant::FindCookName(const QString &name)
{

    QHash<int,Cook>::iterator i;

    for(i=Restaurant::Instance()->CookHash.begin();i!=Restaurant::Instance()->CookHash.end();++i)
    {
        if(i.value().ReturnCookName() == name)
             return true;
    }

    return false;

}

bool Restaurant::FindCookPassword(const QString &pwd)
{
    QHash<int,Cook>::iterator i;

    for(i=Restaurant::Instance()->CookHash.begin();i!=Restaurant::Instance()->CookHash.end();++i)
    {
        if(i.value().ReturnCookPassword() == pwd)
             return true;
    }

    return false;

}

bool Restaurant::FindManagerName(const QString &name)
{
    QHash<QString,QString>::iterator i;

    for(i=Restaurant::Instance()->ManagerHash.begin();i!=Restaurant::Instance()->ManagerHash.end();++i)
    {
        if(i.key() == name)
             return true;
    }

    return false;
}

bool Restaurant::FindManagerPassword(const QString &pwd)
{
    QHash<QString,QString>::iterator i;

    for(i=Restaurant::Instance()->ManagerHash.begin();i!=Restaurant::Instance()->ManagerHash.end();++i)
    {
        if(i.value() == pwd)
             return true;
    }
    return false;
}

bool Restaurant::ChangeDeskState(int n)
{
    QHash<int,Desk>::iterator i;

    for(i=DeskHash.begin();i!=DeskHash.end();++i)
    {
        if(i.value().returnDeskNum() == n)
            {
                i.value().ChangeDeskState("用餐中");
                return true;
            }
    }

    return false;

}

void Restaurant::ChangeDeskUser(QString &name,int n)
{
    QHash<int,Desk>::iterator i;

    for(i=DeskHash.begin();i!=DeskHash.end();++i)
    {
        if(i.value().returnDeskNum() == n)
            {
                i.value().returnCustmer().changeName(name);
            }
    }

}

int Restaurant::ReturnAllDeskNum()
{
    QHash<int,Desk>::iterator i;
    int num = 0;

    for(i=DeskHash.begin();i!=DeskHash.end();++i)
    {
        qDebug()<<i.value().returnDeskNum()<<"hh";
        num++;
    }

    return num;

}

int Restaurant::countCustomer()
{
    QHash <int,Customer>::iterator i;
    int row = 0;

    for(i=CustomerHash.begin();i!=CustomerHash.end();++i)
    {
       row++;
    }

    return row;
}

void Restaurant::getCustomer(const QString &name,const QString &pwd)
{
    Customer c;

    c.CustomerIn(name,pwd);
    CustomerHash.insert(countCustomer()+1,c);
}

void Restaurant::GetDeskDish(const QString &dishname, const QString &dishprice, const int &desknum, const int dishnum)
{
    QHash<int,Desk>::iterator i;

    for(i=DeskHash.begin();i!=DeskHash.end();++i)
    {
        if(i.value().returnDeskNum() == desknum)
            {
               i.value().getDish(dishname,dishprice,dishnum);
            }
    }

}

void Restaurant::getDishHash(const QString &dishname, const QString &dishprice,const int &n)
{
    OneDish o;

    o.getDishName(dishname);
    o.getDishPrice(dishprice);
    DishHash.insert(n,o);
}

void Restaurant::getWaiterHash(const QString &name,const QString &pwd)
{
    Waiter w;
    int n = 1;

    w.getName(name);
    w.getPassword(pwd);

    QHash<int,Waiter>::iterator i;

    for(i=Restaurant::Instance()->WaiterHash.begin();i!=Restaurant::Instance()->WaiterHash.end();++i)
    {
        n++;
    }
     WaiterHash.insert(n,w);
}

void Restaurant::getCookHash(const QString &name, const QString &pwd)
{
    Cook c;
    int n = 1;

    c.CookIn(name,pwd);

    QHash<int,Cook>::iterator i;

    for(i=Restaurant::Instance()->CookHash.begin();i!=Restaurant::Instance()->CookHash.end();++i)
    {
        n++;
    }
     CookHash.insert(n,c);

}

void Restaurant::ChangeCustomerProcess(const QString &name)
{
    QHash<int,Customer>::iterator i;

    for(i=CustomerHash.begin();i!=CustomerHash.end();++i)
    {
        if(i.value().returnCustomerName() == name)
        {
            i.value().returnProcess()++;
        }
    }
}

int Restaurant::ReturnCustomerProcess(const QString &name)
{
    QHash<int,Customer>::iterator i;

    for(i=CustomerHash.begin();i!=CustomerHash.end();++i)
    {
        if(i.value().returnCustomerName() == name)
        {
            return i.value().returnProcess();
        }
    }

}
