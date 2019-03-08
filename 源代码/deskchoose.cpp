#include "deskchoose.h"
#include "ui_deskchoose.h"

deskchoose::deskchoose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deskchoose)
{
    ui->setupUi(this);
    ui->sure->setDisabled(true);
    ui->button1->setDisabled(true);
    QHash<int,Desk>::iterator i;

    for(i=Restaurant::Instance()->DeskHash.begin();i!=Restaurant::Instance()->DeskHash.end();++i)
    {
      if(i.value().returnDeskState() == "用餐中")
        {
            setUnable(i.value().returnDeskNum());
        }
    }
}

deskchoose::~deskchoose()
{
    delete ui;
}

void deskchoose::setUnable(int n)
{
    switch(n)
    {
        case 1:ui->pushButton->setDisabled(true);
                break;
        case 2:ui->pushButton_2->setDisabled(true);
                break;
        case 3:ui->pushButton_3->setDisabled(true);
                break;
        case 4:ui->pushButton_4->setDisabled(true);
                break;

    }

}

void deskchoose::setAble(int &n)
{
    switch(n)
    {
        case 1:ui->pushButton->setEnabled(true);
                break;
        case 2:ui->pushButton_2->setEnabled(true);
                break;
        case 3:ui->pushButton_3->setEnabled(true);
                break;
        case 4:ui->pushButton_4->setEnabled(true);
                break;
    }

}

bool deskchoose::IsDeskUsed(int &n)
{
    QHash<int,Desk>::iterator i;

    for(i=Restaurant::Instance()->DeskHash.begin();i!=Restaurant::Instance()->DeskHash.end();++i)
    {
      if(i.value().returnDeskState() == "用餐中"&&i.value().returnDeskNum() == n)
        {
            return true;
        }
    }

    return false;
}

void deskchoose::on_pushButton_clicked()
{
    Restaurant::Instance()->desk.changeDeskNumber(1);
    Restaurant::Instance()->desk.returnCustmer().ChangeTable(1);

    for(int i =1;i < 5;i ++)
    {
        if(IsDeskUsed(i))
        {
            setUnable(i);
        }
        else
            setAble(i);
    }
    ui->sure->setEnabled(true);
    ui->pushButton->setDisabled(true);
    ui->sure->setFocus();
}

void deskchoose::on_pushButton_2_clicked()
{
    Restaurant::Instance()->desk.changeDeskNumber(2);
    Restaurant::Instance()->desk.returnCustmer().ChangeTable(2);


    for(int i =1;i < 5;i ++)
    {
        if(IsDeskUsed(i))
        {
            setUnable(i);
        }
        else
            setAble(i);
    }
    ui->sure->setEnabled(true);
    ui->pushButton_2->setDisabled(true);
    ui->sure->setFocus();
}

void deskchoose::on_pushButton_3_clicked()
{
    Restaurant::Instance()->desk.changeDeskNumber(3);
    Restaurant::Instance()->desk.returnCustmer().ChangeTable(3);


    for(int i =1;i < 5;i ++)
    {
        if(IsDeskUsed(i))
        {
            setUnable(i);
        }
        else
            setAble(i);
    }
    ui->sure->setEnabled(true);
    ui->pushButton_3->setDisabled(true);
    ui->sure->setFocus();
}

void deskchoose::on_pushButton_4_clicked()
{
    Restaurant::Instance()->desk.changeDeskNumber(4);
    Restaurant::Instance()->desk.returnCustmer().ChangeTable(4);


    for(int i =1;i < 5;i ++)
    {
        if(IsDeskUsed(i))
        {
            setUnable(i);
        }
        else
            setAble(i);
    }
    ui->sure->setEnabled(true);
    ui->pushButton_4->setDisabled(true);
    ui->sure->setFocus();
}

void deskchoose::on_sure_clicked()
{
    Restaurant::Instance()->ChangeDeskState(Restaurant::Instance()->desk.returnDeskNum());
    Restaurant::Instance()->ChangeDeskUser(Restaurant::Instance()->desk.returnCustmer().returnCustomerName(),Restaurant::Instance()->desk.returnDeskNum());
    Restaurant::Instance()->ChangeCustomerProcess(Restaurant::Instance()->desk.returnCustmer().returnCustomerName());
    this->close();
    o.showDisH();
    o.show();
}

void deskchoose::on_exit_clicked()
{
    this->close();
}
