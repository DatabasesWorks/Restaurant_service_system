#include "managewaiter.h"
#include "ui_managewaiter.h"
#include <QMessageBox>

manageWaiter::manageWaiter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manageWaiter)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(3);

    QStringList header;
    header<<tr("服务员")<<tr("密码")<<tr(" ");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget-> horizontalHeader()->setStretchLastSection(true);//设置充满表宽度
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置只能选取一行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑

}

manageWaiter::~manageWaiter()
{
    delete ui;
}

void manageWaiter::showWaiter()
{
    int rowcount = 0;
    QHash<int,Waiter>::iterator i;

    for(i=Restaurant::Instance()->WaiterHash.begin();i!=Restaurant::Instance()->WaiterHash.end();++i)
    {
        QPushButton * pBtn = new QPushButton();
        pBtn->setText("删除");

        ui->tableWidget->insertRow(rowcount);
        ui->tableWidget->setItem(rowcount,0,new QTableWidgetItem(i.value().ReturnWaiterName()));
        ui->tableWidget->setItem(rowcount,1,new QTableWidgetItem(i.value().ReturnWaiterPassword()));

        connect(pBtn, SIGNAL(clicked()), this, SLOT(OnBtnClicked()));
        ui->tableWidget->setCellWidget(rowcount,2,pBtn);
        rowcount ++;
    }

}


void manageWaiter::OnBtnClicked()
{
    QPushButton * senderObj = qobject_cast<QPushButton *>(sender());
    if(senderObj == 0)
    {
        return;
    }
    QModelIndex index =ui->tableWidget->indexAt(QPoint(senderObj->frameGeometry().x(),senderObj->frameGeometry().y()));

    int row=index.row();

    QHash<int,Waiter>::iterator i;

    for(i=Restaurant::Instance()->WaiterHash.begin();i!=Restaurant::Instance()->WaiterHash.end();++i)
    {
        if(i.value().ReturnWaiterName() == ui->tableWidget->item(row,0)->text())
        {
            Restaurant::Instance()->WaiterHash.erase(i);
        }
    }

    ui->tableWidget->removeRow(row);

}

void manageWaiter::on_pushButton_clicked()
{
    if(nw.exec() == QDialog::Accepted)
    {
        int row_count = ui->tableWidget->rowCount();

        QPushButton * pBtn = new QPushButton();
        pBtn->setText("删除");

        ui->tableWidget->insertRow(row_count);
        ui->tableWidget->setItem(row_count,0,new QTableWidgetItem(nw.name));
        ui->tableWidget->setItem(row_count,1,new QTableWidgetItem(nw.password));

        connect(pBtn, SIGNAL(clicked()), this, SLOT(OnBtnClicked()));
        ui->tableWidget->setCellWidget(row_count,2,pBtn);
    }
}

void manageWaiter::on_pushButton_2_clicked()
{
    QMessageBox::information(NULL,"提示","修改成功",QMessageBox::Yes);
}


void manageWaiter::on_pushButton_3_clicked()
{
    this->close();
}
