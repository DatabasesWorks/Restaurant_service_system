#include "onedish.h"

void OneDish::getDish(const QString &dishname,const QString &dishprice,const QString &dishstate)
{
    this->dishname = dishname;
    this->dishprice = dishprice;
    this->dishstate = dishstate;
    this->UrgeOrder = "否";
}

const QString OneDish::putDishName()
{
    return this->dishname;
}

const QString OneDish::putDishPrice()
{
    return this->dishprice;
}

const QString OneDish::putDishState()
{
    return this->dishstate;
}

void OneDish::getDishName(const QString &dishname)
{
    this->dishname = dishname;
}

void OneDish::getDishPrice(const QString &dishprice)
{
    this->dishprice = dishprice;
}

void OneDish::changeDishState(const QString &dishstate)
{
    this->dishstate = dishstate;
}

void OneDish::changeUrgeOrder()
{
    this->UrgeOrder = "是";
}

const QString OneDish::putUrgeOrder()
{
    return this->UrgeOrder;
}
