#include "waiterdlg.h"
#include "ui_waiterdlg.h"
#include <QMessageBox>
#include <QDebug>
waiterdlg::waiterdlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::waiterdlg)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget_2->setColumnCount(1);

    QStringList header;

    header<<tr("桌号");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget-> horizontalHeader()->setStretchLastSection(true);//设置充满表宽度
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置只能选取一行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑

    QStringList head;

    head<<tr("桌号");
    ui->tableWidget_2->setHorizontalHeaderLabels(head);
    ui->tableWidget_2-> horizontalHeader()->setStretchLastSection(true);//设置充满表宽度
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);//设置只能选取一行
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑

}

waiterdlg::~waiterdlg()
{
    delete ui;
}

void waiterdlg::showWaiterDesk(const QString &waiter)
{
    username = waiter;
    int rowcount = 0;

    QHash<int,Desk>::iterator i;

    for(i=Restaurant::Instance()->DeskHash.begin();i!=Restaurant::Instance()->DeskHash.end();++i)
    {
      if(i.value().returnDeskState() == "用餐中"&&(!i.value().WaiterChoseOrNot))
        {
            ui->tableWidget->insertRow(rowcount);
            ui->tableWidget->setItem(rowcount,0,new QTableWidgetItem(QString::number(i.value().returnDeskNum())));

            rowcount++;
        }
    }
    rowcount = 0;
    QHash<int,Waiter>::iterator mi;

    for(mi=Restaurant::Instance()->WaiterHash.begin();mi!=Restaurant::Instance()->WaiterHash.end();++mi)
    {
        if(mi.value().ReturnWaiterName() == waiter)
        {
            QHash<int,int>::iterator it;

            for(it = mi.value().returnDeskNum().begin();it!= mi.value().returnDeskNum().end();++it)
            {
                ui->tableWidget_2->insertRow(rowcount);
                ui->tableWidget_2->setItem(rowcount,0,new QTableWidgetItem(QString::number(it.value())));

                rowcount++;
            }
        }
    }
}


void waiterdlg::on_pushButton_clicked()
{
    if(ui->tableWidget->isItemSelected(ui->tableWidget->currentItem()))
    {
        QHash<int,Desk>::iterator i;

        for(i=Restaurant::Instance()->DeskHash.begin();i!=Restaurant::Instance()->DeskHash.end();++i)
        {
          if(i.value().returnDeskNum() == ui->tableWidget->item(ui->tableWidget->currentRow(),0)->text().toInt())
            {
              i.value().WaiterChoseOrNot = true;
            }
        }

        QHash<int,Waiter>::iterator mi;

        for(mi=Restaurant::Instance()->WaiterHash.begin();mi!=Restaurant::Instance()->WaiterHash.end();++mi)
        {
            if(mi.value().ReturnWaiterName() == username)
            {
               mi.value().getDeskNum(ui->tableWidget->item(ui->tableWidget->currentRow(),0)->text().toInt());
            }
        }

        int row = ui->tableWidget->currentRow();
        int row_2 = ui->tableWidget_2->rowCount();

        ui->tableWidget_2->insertRow(row_2);
        ui->tableWidget_2->setItem(row_2,0,new QTableWidgetItem(ui->tableWidget->item(row,0)->text()));

        ui->tableWidget->removeRow(row);
    }
    else
    {
        QMessageBox::warning(this,tr("提示"),tr("请选择需要服务的餐桌！"),QMessageBox::Ok);
    }
}

void waiterdlg::on_pushButton_2_clicked()
{
    if(ui->tableWidget_2->isItemSelected(ui->tableWidget_2->currentItem()))
    {
        s.showDish(ui->tableWidget_2->item(ui->tableWidget_2->currentRow(),0)->text().toInt());
        this->close();
        s.show();
    }
    else
    {
        QMessageBox::warning(this,tr("提示"),tr("请选择需要服务的餐桌！"),QMessageBox::Ok);
    }
}

void waiterdlg::closeEvent(QCloseEvent *event)
{
    int row = ui->tableWidget->rowCount();
    int row_2 = ui->tableWidget_2->rowCount();

    for(int i=0;i<row;i++)
    {
        ui->tableWidget->removeRow(0);
    }
    for(int i=0;i<row_2;i++)
    {
        ui->tableWidget_2->removeRow(0);
    }
}
