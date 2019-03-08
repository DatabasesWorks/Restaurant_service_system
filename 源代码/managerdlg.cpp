#include "managerdlg.h"
#include "ui_managerdlg.h"

managerdlg::managerdlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::managerdlg)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(1);

    QStringList header;
    header<<tr("用户名");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget-> horizontalHeader()->setStretchLastSection(true);//设置充满表宽度
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置只能选取一行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑

    ui->tableWidget_2->setColumnCount(1);

    QStringList head;
    head<<tr("用户名");
    ui->tableWidget_2->setHorizontalHeaderLabels(head);
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);//设置充满表宽度
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);//设置只能选取一行
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
}

managerdlg::~managerdlg()
{
    delete ui;
}

void managerdlg::showIt()
{
    int rowcount = 0;
    QHash<int,Waiter>::iterator i;

    for(i=Restaurant::Instance()->WaiterHash.begin();i!=Restaurant::Instance()->WaiterHash.end();++i)
    {
        ui->tableWidget->insertRow(rowcount);
        ui->tableWidget->setItem(rowcount,0,new QTableWidgetItem(i.value().ReturnWaiterName()));

        rowcount ++;
    }
    rowcount = 0;
    QHash<int,Cook>::iterator it;

    for(it=Restaurant::Instance()->CookHash.begin();it!=Restaurant::Instance()->CookHash.end();++it)
    {
        ui->tableWidget_2->insertRow(rowcount);
        ui->tableWidget_2->setItem(rowcount,0,new QTableWidgetItem(it.value().ReturnCookName()));

        rowcount ++;
    }
}

void managerdlg::on_tableWidget_doubleClicked(const QModelIndex &index)
{

}



void managerdlg::on_tableWidget_2_doubleClicked(const QModelIndex &index)
{

}
