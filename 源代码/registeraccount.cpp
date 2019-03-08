#include "registeraccount.h"
#include "ui_registeraccount.h"
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDebug>

registerAccount::registerAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerAccount)
{
    ui->setupUi(this);
}

registerAccount::~registerAccount()
{
    delete ui;
}

void registerAccount::on_register_2_clicked()
{
    QString username;
    QString password;
    QString password2;

    //读入用户名及密码
    username = ui->usernameEdit->text();
    password = ui->passwordEdit->text();
    password2 = ui->password2Edit->text();
    if(username.isEmpty())//判断用户名是否为空
    {
        QMessageBox::warning(this,tr("请输入用户名"),tr("请输入用户名！"),QMessageBox::Ok);//弹出提示信息
        ui->passwordEdit->clear();
        ui->password2Edit->clear();
        ui->usernameEdit->setFocus();
    }
    else if(DataBase::Insitial()->findCustomer(username) == true)//判断用户名是否已经存在
            {
                QMessageBox::warning(this,tr("请输入用户名"),tr("用户名已存在！"),QMessageBox::Ok);//弹出提示信息
                ui->passwordEdit->clear();
                ui->password2Edit->clear();
                ui->usernameEdit->setFocus();
            }
         else if(password.isEmpty()||password2.isEmpty())
                {
                    QMessageBox::warning(this,tr("请输入密码"),tr("请输入密码！"),QMessageBox::Ok);//弹出提示信息
                    ui->passwordEdit->clear();
                    ui->password2Edit->clear();
                    ui->passwordEdit->setFocus();
                }


                else if(password != password2)
                        {
                            QMessageBox::warning(this,tr("密码错误"),tr("请检查两次输入的密码是否一致！"),QMessageBox::Ok);
                            ui->passwordEdit->clear();
                            ui->password2Edit->clear();
                            ui->passwordEdit->setFocus();
                        }
                        else
                            {
                                ui->usernameEdit->clear();
                                ui->passwordEdit->clear();
                                ui->password2Edit->clear();
                                ui->usernameEdit->setFocus();
                                Restaurant::Instance()->desk.getCustomer(username,password);
                                Restaurant::Instance()->getCustomer(username,password);
                                this->close();
                                des.show();
                            }
                //QMessageBox ChoseSave(QMessageBox::information,"提示","是否保存当前用户",QMessageBox::Yes|QMessageBox::No);


}


