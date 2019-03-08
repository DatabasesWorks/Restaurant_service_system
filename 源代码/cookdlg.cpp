#include "cookdlg.h"
#include "ui_cookdlg.h"

cookdlg::cookdlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cookdlg)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(1);

    QStringList header;

    header<<tr("桌号");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget-> horizontalHeader()->setStretchLastSection(true);//设置充满表宽度
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置只能选取一行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑

}

void cookdlg::showCookDesk(const QString &name)
{
    int rowcount = 0;
    username = name;
    //qDebug()<<username<<"cao";
    QHash<int,Desk>::iterator i;

    for(i=Restaurant::Instance()->DeskHash.begin();i!=Restaurant::Instance()->DeskHash.end();++i)
    {
      if(i.value().returnDeskState() == "用餐中")
        {
            ui->tableWidget->insertRow(rowcount);
            ui->tableWidget->setItem(rowcount,0,new QTableWidgetItem(QString::number(i.value().returnDeskNum())));

            rowcount++;
        }
    }
}
cookdlg::~cookdlg()
{
    delete ui;
}

void cookdlg::on_tableWidget_clicked(const QModelIndex &index)
{
    desknum = ui->tableWidget->item(index.row(),0)->text().toInt();
}

void cookdlg::on_pushButton_clicked()
{
    QHash<int,Cook>::iterator i;

    for(i=Restaurant::Instance()->CookHash.begin();i!=Restaurant::Instance()->CookHash.end();++i)
    {
      if(i.value().ReturnCookName() == username)
        {
           i.value().changeDesk(desknum);
           QHash<int,Desk>::iterator it;

           for(it=Restaurant::Instance()->DeskHash.begin();it!=Restaurant::Instance()->DeskHash.end();++it)
           {
             if(it.value().returnDeskNum() == desknum)
               {
                  it.value().inputCookName(i.value().ReturnCookName());
               }
           }
        }
    }

    c.showDish(desknum);
    this->close();
    c.show();
}
void cookdlg::closeEvent(QCloseEvent *event)
{
    int row = ui->tableWidget->rowCount();

    for(int i=0;i<row;i++)
    {
        ui->tableWidget->removeRow(0);
    }

}
