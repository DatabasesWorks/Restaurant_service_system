#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMessageBox>
#include "database.h"
#include "restaurant.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

    QString name;

    void ChangeType(const int &type)
    {
        this->type = type;
    }

    int ReturnType()
    {
        return this->type;
    }
private slots:
    void on_loginbutton_clicked();
    void on_quit_clicked();

private:
    Ui::login *ui;
    int type;//代表不同的用户：1.顾客。2，餐厅管理员。3，服务员。4.厨师。5.餐厅经理。

};

#endif // LOGIN_H
