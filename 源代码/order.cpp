#include "order.h"
#include "ui_order.h"
#include <QDebug>

Order::Order(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Order)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(2);
    QStringList header;
    header<<tr("菜名")<<tr("单价/元");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget-> horizontalHeader()->setStretchLastSection(true);//设置充满表宽度
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置只能选取一行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑



    ui->tableWidget_2->setColumnCount(3);
    QStringList head;
    head<<tr("菜名")<<tr("单价")<<tr(" ");
    ui->tableWidget_2->setHorizontalHeaderLabels(header);
    ui->tableWidget_2-> horizontalHeader()->setStretchLastSection(true);//设置充满表宽度
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);//设置只能选取一行
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
}

Order::~Order()
{
    delete ui;
}

void Order::showDisH()
{

    int row_count = ui->tableWidget->rowCount(); //获取表单行数
    QHash<int,OneDish>::iterator i;

    for(i=Restaurant::Instance()->DishHash.begin();i!=Restaurant::Instance()->DishHash.end();++i)
    {
       ui->tableWidget->insertRow(row_count);
       ui->tableWidget->setItem(row_count,0,new QTableWidgetItem(i.value().putDishName()));
       ui->tableWidget->setItem(row_count,1,new QTableWidgetItem(i.value().putDishPrice()));
       row_count ++;
    }

}

void Order::on_tableWidget_cellDoubleClicked(int row, int column)
{
    QString dishname;
    QString dishprice;
    QPushButton * pBtn = new QPushButton();
    pBtn->setText("删除");
    int rowcount;

    dishname = ui->tableWidget->item(row,0)->text();
    dishprice = ui->tableWidget->item(row,1)->text();

    rowcount = ui->tableWidget_2->rowCount();
    ui->tableWidget_2->insertRow(rowcount);
    ui->tableWidget_2->setItem(rowcount,0,new QTableWidgetItem(dishname));
    ui->tableWidget_2->setItem(rowcount,1,new QTableWidgetItem(dishprice));
}

void Order::on_pushButton_clicked()
{
    int allrow;

    allrow = ui->tableWidget_2->rowCount();
    int desknum = Restaurant::Instance()->desk.returnDeskNum();

    for(int i=0;i<allrow;i++)
    {
       Restaurant::Instance()->desk.returnDish().inMap(i+1,ui->tableWidget_2->item(i,0)->text(),ui->tableWidget_2->item(i,1)->text(),"未做");
       Restaurant::Instance()->GetDeskDish(ui->tableWidget_2->item(i,0)->text(),ui->tableWidget_2->item(i,1)->text(),desknum,i+1);//存入哈希表
    }
    Restaurant::Instance()->ChangeCustomerProcess(Restaurant::Instance()->desk.returnCustmer().returnCustomerName());
    this->close();
    wf.showDish();
    wf.show();
}
void Order::OnBtnClicked()//
{
        QPushButton * senderObj=qobject_cast<QPushButton *>(sender());
        if(senderObj == 0)
        {
            return;
        }
        QModelIndex index =ui->tableWidget_2->indexAt(QPoint(senderObj->frameGeometry().x(),senderObj->frameGeometry().y()));

        int row=index.row();
        ui->tableWidget_2->removeRow(row);
}
void Order::closeEvent(QCloseEvent *event)
{
    int row = ui->tableWidget->rowCount();

    for(int i=0;i<row;i++)
    {
        ui->tableWidget->removeRow(0);
    }
    int row2 = ui->tableWidget_2->rowCount();

    for(int i=0;i<row2;i++)
    {
        ui->tableWidget_2->removeRow(0);
    }
}
