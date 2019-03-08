#include "login.h"
#include "ui_login.h"
#include <QDebug>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}
void login::on_loginbutton_clicked()
{
    QString namestring;
    QString pwdstring;


    namestring = ui->username->text();
    namestring = namestring.trimmed();
    pwdstring = ui->password->text();
    if(namestring.isEmpty())
    {
        QMessageBox::information(this,tr("请输入用户名"),tr("请输入用户名"),QMessageBox::Ok);
        ui->password->clear();
        ui->username->setFocus();
    }
    else if(pwdstring.isEmpty())
            {
                QMessageBox::information(this,tr("请输入密码"),tr("请输入密码"),QMessageBox::Ok);
                ui->password->clear();
                ui->username->setFocus();
            }
        else
         {
            switch(this->ReturnType())
                {
                    case 1:if(Restaurant::Instance()->FindCustomerName(namestring) == true)
                            {
                                if(Restaurant::Instance()->FindCustomerPassword(pwdstring) == true)
                                    {
                                    ui->password->clear();
                                    ui->username->clear();

                                    Restaurant::Instance()->desk.getCustomer(namestring,pwdstring);//应该读入所有信息

                                        QDialog::accept();
                                    }
                                else
                                    {
                                    QMessageBox::warning(this,tr("密码错误"),tr("请输入正确的密码再登录！"),QMessageBox::Ok);
                                     ui->password->clear();
                                     ui->password->setFocus();
                                     }
                            }
                            else
                            {
                                QMessageBox::warning(this,tr("用户名不存在"),tr("请输入正确的用户名再登录！"),QMessageBox::Ok);
                                ui->password->clear();
                                ui->username->setFocus();
                            }
                            break;

                    case 2:  if(DataBase::Insitial()->findAdministrator(namestring) == true)
                                       {
                                             if(DataBase::Insitial()->findPasswordAdministrator(pwdstring) == true)
                                                  {
                                                 ui->password->clear();
                                                 ui->username->clear();
                                                      //csm.CustomerIn(namestring,pwdstring);
                                                      QDialog::accept();
                                                   }
                                              else
                                                  {
                                                    QMessageBox::warning(this,tr("密码错误"),tr("请输入正确的密码再登录！"),QMessageBox::Ok);
                                                    ui->password->clear();
                                                    ui->password->setFocus();
                                                   }
                                        }
                             else
                               {
                                  QMessageBox::warning(this,tr("用户名不存在"),tr("请输入正确的用户名再登录！"),QMessageBox::Ok);
                                  ui->password->clear();
                                  ui->username->clear();
                                  ui->username->setFocus();
                              }
                             break;
                    case 3: if(Restaurant::Instance()->FindWaiterName(namestring) == true)
                                {
                                    if(Restaurant::Instance()->FindWaiterPassword(pwdstring))
                                        {
                                            ui->password->clear();
                                            ui->username->clear();
                                            //csm.CustomerIn(namestring,pwdstring);
                                            QDialog::accept();
                                        }
                                    else
                                        {
                                            QMessageBox::warning(this,tr("密码错误"),tr("请输入正确的密码再登录！"),QMessageBox::Ok);
                                            ui->password->clear();
                                            ui->password->setFocus();
                                        }
                                }
                        else
                            {
                                QMessageBox::warning(this,tr("用户名不存在"),tr("请输入正确的用户名再登录！"),QMessageBox::Ok);
                                ui->password->clear();
                                ui->username->setFocus();
                            }
                            break;
                 case 4:if(Restaurant::Instance()->FindCookName(namestring) == true)
                        {
                            if(Restaurant::Instance()->FindCookPassword(pwdstring))
                             {
                                ui->password->clear();
                                ui->username->clear();
                                //csm.CustomerIn(namestring,pwdstring);
                                QDialog::accept();
                            }
                            else
                                {
                                QMessageBox::warning(this,tr("密码错误"),tr("请输入正确的密码再登录！"),QMessageBox::Ok);
                                ui->password->clear();
                                ui->password->setFocus();
                            }
                        }
                        else
                        {
                            QMessageBox::warning(this,tr("用户名不存在"),tr("请输入正确的用户名再登录！"),QMessageBox::Ok);
                            ui->password->clear();
                            ui->username->setFocus();
                        }
            break;
        case 5:if(Restaurant::Instance()->FindManagerName(namestring) == true)
                {
                    if(Restaurant::Instance()->FindManagerPassword(pwdstring))
                        {
                            ui->password->clear();
                            ui->username->clear();
                            //csm.CustomerIn(namestring,pwdstring);
                            QDialog::accept();
                        }
                    else
                        {
                            QMessageBox::warning(this,tr("密码错误"),tr("请输入正确的密码再登录！"),QMessageBox::Ok);
                            ui->password->clear();
                            ui->password->setFocus();
                        }
                }
        else
            {
                QMessageBox::warning(this,tr("用户名不存在"),tr("请输入正确的用户名再登录！"),QMessageBox::Ok);
                ui->password->clear();
                ui->username->setFocus();
            }
            break;
                }
           }
}

void login::on_quit_clicked()
{
    this->close();
}
