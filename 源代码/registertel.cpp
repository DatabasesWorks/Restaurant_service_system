#include "registertel.h"
#include "ui_registertel.h"

registertel::registertel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registertel)
{
    ui->setupUi(this);
    setWindowTitle(tr("输入手机号"));
}

registertel::~registertel()
{
    delete ui;
}

void registertel::on_confirmButton_clicked()
{
    QString telnumber;
    QByteArray ba;
    const char *s;
    int num = 0;

   telnumber = ui->telnumber->text().trimmed();
   ba = telnumber.toLatin1();
   s = ba.data();
   while(*s && *s>='0' && *s<='9')
   {
       s++;
       num++;
   }
   if(*s)
   {
       QMessageBox::warning(this,tr("手机号错误"),tr("请输入正确的手机号!"),QMessageBox::Ok);
        ui->telnumber->clear();
        ui->telnumber->setFocus();
   }
   else if(num != 11)
         {
           QMessageBox::warning(this,tr("手机号错误"),tr("请输入正确的手机号！"),QMessageBox::Ok);
           ui->telnumber->clear();
           ui->telnumber->setFocus();
         }
         else
        {
             ui->telnumber->clear();
             this->hide();
             registerdialog.show();
        }
}
