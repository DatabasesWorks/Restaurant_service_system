#ifndef DISH_H
#define DISH_H

#include <QHash>
#include "onedish.h"

class Dish
{
 public:
    void inMap(const int &n,const QString &dishname,const QString &dishprice,const QString &dishstate)
    {
        adish.getDish(dishname,dishprice,dishstate);
        dishmap.insert(n,adish);
    }
    QHash <int,OneDish> &getDishmap()
    {
        return dishmap;
    }
private:
    QHash <int,OneDish> dishmap;
    OneDish adish;
};

#endif // DISH_H
