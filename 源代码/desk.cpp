#include "desk.h"

void Desk::ChangeDeskState(const QString sta)
{
    this->state = sta;
}

QString &Desk::returnDeskState()
{
    return this->state;
}

void Desk::getDish(const QString &dishname,const QString &dishprice,const int dishnum)
{
    mdish.inMap(dishnum,dishname,dishprice,"未做");
}

void Desk::getRequest(const QString &request)
{
    this->request = request;
}

const QString Desk::returnRequest()
{
    return this->request;
}

void Desk::inputCookName(const QString &name)
{
    this->cookname = name;
}

QString &Desk::returnCookName()
{
    return this->cookname;
}
