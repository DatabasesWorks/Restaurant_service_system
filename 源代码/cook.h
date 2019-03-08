#ifndef COOK_H
#define COOK_H

#include <QString>
#include "QHash"
class Cook
{
public:
    Cook();
    void CookIn(const QString &name,const QString &pwd);
    QString &ReturnCookName();
    QString &ReturnCookPassword();
    void changeDesk(int n);
    void getMark(const int n);
    int &returnDeskNum();
private:
    QString name;
    QString password;
    int desknum =0 ;
    QHash<int,int> CookMark;
};

#endif // COOK_H
