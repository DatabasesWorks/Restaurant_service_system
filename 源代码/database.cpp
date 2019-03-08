#include "database.h"

DataBase* DataBase::database = NULL;

DataBase * DataBase::Insitial()
{
    if(database == NULL)
        database = new DataBase();
    return database;
}

bool DataBase::createConnection()
{
    QSqlQuery customerquery;//创建顾客表
    QSqlQuery administratorquery;//创建管理员表
    QSqlQuery dishquery;//创建菜谱表
    QSqlQuery waiterquery;//创建服务员表
    QSqlQuery deskquery;//创建餐桌表
    QSqlQuery cookquery;//创建厨师表
    QSqlQuery managerquery;//创建餐厅经理表
    //QSqlQuery cusdishquery;//存储餐桌菜单

    db.setHostName("HomeWork");
    db.setDatabaseName("restaurant");
    db.setUserName("lick16");
    db.setPassword("123456");
    if(!db.open())
    {
        return false;
    }
    if(customerquery.exec("create table user(name varchar[30] primary key,password varchar[30])"))
        qDebug()<<"初始化成功";//初始化顾客表
    customerquery.exec("delete from user");//清空表

    customerquery.exec("insert into user values('c001','111')");
    customerquery.exec("insert into user values('c002','222')");

    administratorquery.exec("create table administrator(name varchar[30] primary key,password varchar[30])");//初始化管理员表
    administratorquery.exec("delete from administrator");

    administratorquery.exec("insert into administrator values('a001','111')");
    administratorquery.exec("insert into administrator values('a002','222')");

    waiterquery.exec("create table waiter(name varchar[30] primary key,password varchar[30])");
    waiterquery.exec("delete from waiter");

    waiterquery.exec("insert into waiter values('w001','111')");
    waiterquery.exec("insert into waiter values('w002','222')");

    dishquery.exec("create table dish(name varchar primary key,price varchar[])");//初始化菜谱表
    dishquery.exec("delete from dish");

    dishquery.exec("insert into dish values('红烧肉','28')");
    dishquery.exec("insert into dish values('西红柿炒鸡蛋','18')");

    deskquery.exec("create table desk(num int primary key,state varchar[30])");//初始化餐桌
    deskquery.exec("delete from desk");

    deskquery.exec("insert into desk values(1,'空闲')");
    deskquery.exec("insert into desk values(2,'空闲')");
    deskquery.exec("insert into desk values(3,'空闲')");
    deskquery.exec("insert into desk values(4,'空闲')");

    cookquery.exec("create table cook(name varchar[30] primary key,password varchar[30])");//初始化厨师表
    cookquery.exec("delete  from cook");//清空表

    customerquery.exec("insert into cook values('co001','111')");
    customerquery.exec("insert into cook values('co002','222')");

    managerquery.exec("create table manager(name varchar[30] primary key,password varchar[30])");//初始化餐厅经理
    //managerquery.exec("delete from manager");//清空表

    managerquery.exec("insert into manager values('m001','111')");
    return true;


}

void DataBase::inserct(const QString &name, const QString &pwd)
{
       QSqlQuery customerquery;//创建顾客表

        customerquery.prepare("INSERT INTO user(name,pwd)""VALUES(?,?)");
        customerquery.addBindValue(name);
        customerquery.addBindValue(pwd);

        customerquery.exec();
}

void DataBase::insertInDishMap(const QString &dishname,const QString &dishprice)
{
    QSqlQuery query;

    query.prepare("INSERT INTO dish(name,price)""VALUES(?,?)");
    query.addBindValue(dishname);
    query.addBindValue(dishprice);

    query.exec();

}

void DataBase::insertInCook(const QString &name,const QString &pwd)
{
    QSqlQuery query;

    query.prepare("INSERT INTO cook(name,pwd)""VALUES(?,?)");
    query.addBindValue(name);
    query.addBindValue(pwd);

    query.exec();

}

bool DataBase::findPasswordCook(const QString &pwd)
{
    QSqlQuery query;

    query.exec("select password from cook");
    while(query.next())
    {
        if(query.value(0).toString() == pwd)
        return true;
    }
    return false;
}

