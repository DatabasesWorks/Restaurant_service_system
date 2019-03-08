#ifndef ONEDISH_H
#define ONEDISH_H

#include <QString>

class OneDish
{
public:
    void getDish(const QString &dishname,const QString &dishprice,const QString &dishstate);
    void getDishName(const QString &dishname);
    void getDishPrice(const QString &dishprice);
    void changeDishState(const QString &dishstate);
    void changeUrgeOrder();

    const QString putDishName();
    const QString putDishPrice();
    const QString putDishState();
    const QString putUrgeOrder();
private:
    QString dishname;
    QString dishprice;
    QString dishstate;
    QString UrgeOrder;
};

#endif // ONEDISH_H
