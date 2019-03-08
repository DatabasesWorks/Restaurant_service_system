#include "managedish.h"
#include "ui_managedish.h"
#include <QMessageBox>

manageDish::manageDish(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manageDish)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);

    QStringList header;
    header<<tr("菜名")<<tr("单价/元")<<tr(" ");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget-> horizontalHeader()->setStretchLastSection(true);//设置充满表宽度
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置只能选取一行

}

manageDish::~manageDish()
{
    delete ui;
}

void manageDish::showDishMap()
{
    int rowcount = 0;
    QHash<int,OneDish>::iterator i;

    for(i=Restaurant::Instance()->DishHash.begin();i!=Restaurant::Instance()->DishHash.end();++i)
    {
        QPushButton * pBtn = new QPushButton();
        pBtn->setText("删除");

        ui->tableWidget->insertRow(rowcount);
        ui->tableWidget->setItem(rowcount,0,new QTableWidgetItem(i.value().putDishName()));
        ui->tableWidget->setItem(rowcount,1,new QTableWidgetItem(i.value().putDishPrice()));

        connect(pBtn, SIGNAL(clicked()), this, SLOT(OnBtnClicked()));
        ui->tableWidget->setCellWidget(rowcount,2,pBtn);
    }

}

void manageDish::OnBtnClicked()
{
    QPushButton * senderObj = qobject_cast<QPushButton *>(sender());
    if(senderObj == 0)
    {
        return;
    }
    QModelIndex index =ui->tableWidget->indexAt(QPoint(senderObj->frameGeometry().x(),senderObj->frameGeometry().y()));

    int row=index.row();
    ui->tableWidget->removeRow(row);

}

void manageDish::on_pushButton_clicked()
{
    int row_count = ui->tableWidget->rowCount();

    QPushButton * pBtn = new QPushButton();
    pBtn->setText("删除");

    ui->tableWidget->insertRow(row_count);
    ui->tableWidget->setItem(row_count,0,new QTableWidgetItem(""));
    ui->tableWidget->setItem(row_count,1,new QTableWidgetItem(""));

    connect(pBtn, SIGNAL(clicked()), this, SLOT(OnBtnClicked()));
    ui->tableWidget->setCellWidget(row_count,2,pBtn);
}

void manageDish::on_pushButton_2_clicked()
{
    int row = 0;
    int row_count = ui->tableWidget->rowCount();

    for(;row < row_count;row++)
    {
        qDebug()<<ui->tableWidget->item(row,0)->text();
        if(ui->tableWidget->item(row,0)->text().isEmpty())
        {
            QMessageBox::warning(this,tr("错误"),tr("请输入菜名！"),QMessageBox::Ok);//暂时不知道怎么将光标移动过去
            break;
        }
        else if(ui->tableWidget->item(row,1)->text().isEmpty())//待尝试
                {
                     QMessageBox::warning(this,tr("错误"),tr("请输入价格！"),QMessageBox::Ok);//暂时不知道怎么将光标移动过去
                     break;
                }
    }

    if(row == ui->tableWidget->rowCount())
    {
        int myrow = 0;

        Restaurant::Instance()->FlashDishHash();

        for(;myrow < row_count;myrow ++ )
        {
            Restaurant::Instance()->getDishHash(ui->tableWidget->item(myrow,0)->text(),ui->tableWidget->item(myrow,1)->text(),myrow+1);
        }
    }
}

void manageDish::on_pushButton_3_clicked()
{
    this->close();
}
