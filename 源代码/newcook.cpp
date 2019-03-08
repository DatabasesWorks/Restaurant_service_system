#include "newcook.h"
#include "ui_newcook.h"
#include <QMessageBox>

newCook::newCook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newCook)
{
    ui->setupUi(this);
}

newCook::~newCook()
{
    delete ui;
}

void newCook::on_pushButton_clicked()
{
    QString userName;
    QString passWord;

    //读入用户名及密码
    userName = (ui->usernameEdit->text()).trimmed();
    passWord = ui->pwdEdit->text();
    name = userName;
    password = passWord;
    if(userName.isEmpty())//判断用户名是否为空
    {
        QMessageBox::warning(this,tr("提示"),tr("请输入用户名！"),QMessageBox::Ok);//弹出提示信息
        ui->pwdEdit->clear();
        ui->usernameEdit->setFocus();
    }
    else if(Restaurant::Instance()->FindCookName(userName) == true)//判断用户名是否已经存在
            {
                QMessageBox::warning(this,tr("提示"),tr("用户名已存在！"),QMessageBox::Ok);//弹出提示信息
                ui->pwdEdit->clear();
                ui->usernameEdit->clear();
                ui->usernameEdit->setFocus();
            }
         else if(passWord.isEmpty())
                {
                    QMessageBox::warning(this,tr("提示"),tr("请输入密码！"),QMessageBox::Ok);//弹出提示信息
                    ui->pwdEdit->clear();
                    ui->pwdEdit->setFocus();
                }
                else
                     {
                         ui->usernameEdit->clear();
                         ui->pwdEdit->clear();
                         ui->usernameEdit->setFocus();
                         Restaurant::Instance()->getCookHash(userName,passWord);

                         QDialog::accept();
                        this->close();

                     }
}
