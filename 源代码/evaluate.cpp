#include "evaluate.h"
#include "ui_evaluate.h"

evaluate::evaluate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::evaluate)
{
    ui->setupUi(this);
}

evaluate::~evaluate()
{
    delete ui;
}

void evaluate::on_pushButton_clicked()
{
    QHash<int,Desk>::iterator i;

    for(i=Restaurant::Instance()->DeskHash.begin();i!=Restaurant::Instance()->DeskHash.end();++i)
    {
      if(i.value().returnDeskNum() == Restaurant::Instance()->desk.returnDeskNum())
        {
          QHash<int,Cook>::iterator it;

          for(it=Restaurant::Instance()->CookHash.begin();it!=Restaurant::Instance()->CookHash.end();++it)
          {
            if(i.value().returnCookName() == it.value().ReturnCookName())
              {
                it.value().getMark(ui->comboBox_2->currentText().toInt());
              }
          }
           i.value().ChangeDeskState("空闲");
        }
    }

    QHash<int,Waiter>::iterator mi;

    for(mi=Restaurant::Instance()->WaiterHash.begin();mi!=Restaurant::Instance()->WaiterHash.end();++mi)
    {
      if(mi.value().findDeskNum(Restaurant::Instance()->desk.returnDeskNum()))
        {
          mi.value().getMark(ui->comboBox->currentText().toInt());
          mi.value().clearDeskNum(Restaurant::Instance()->desk.returnDeskNum());
        }
    }


    this->close();
}
