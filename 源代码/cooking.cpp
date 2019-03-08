#include "cooking.h"
#include "ui_cooking.h"

cooking::cooking(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cooking)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget_2->setColumnCount(2);
    ui->tableWidget_3->setColumnCount(1);

    QStringList header;

    header<<tr("菜名")<<tr("是否催菜");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget-> horizontalHeader()->setStretchLastSection(true);//设置充满表宽度
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置只能选取一行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
    ui->tableWidget_2->setHorizontalHeaderLabels(header);
    ui->tableWidget_2-> horizontalHeader()->setStretchLastSection(true);//设置充满表宽度
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);//设置只能选取一行
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑

    QStringList head;

    head<<tr("菜名");
    ui->tableWidget_3->setHorizontalHeaderLabels(head);
    ui->tableWidget_3-> horizontalHeader()->setStretchLastSection(true);//设置充满表宽度
    ui->tableWidget_3->setSelectionBehavior(QAbstractItemView::SelectRows);//设置只能选取一行
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
}

cooking::~cooking()
{
    delete ui;
}

void cooking::showDish(int n)
{
    num = n;
    int row_1 = ui->tableWidget->rowCount();
    int row_2 = ui->tableWidget->rowCount();
    int row_3 = ui->tableWidget->rowCount();

    ui->deskNum->setText("服务桌号：" + QString::number(num));

    QHash<int,Desk>::iterator i;

    for(i=Restaurant::Instance()->DeskHash.begin();i!=Restaurant::Instance()->DeskHash.end();++i)
    {
        if(i.value().returnDeskNum() == n)
        {
            QHash<int,OneDish>::iterator it;

            for(it=i.value().returnDish().getDishmap().begin();it!=i.value().returnDish().getDishmap().end();++it)
            {
                if(it.value().putDishState() == "未做")
                    {
                        ui->tableWidget->insertRow(row_1);
                        ui->tableWidget->setItem(row_1,0,new QTableWidgetItem(it.value().putDishName()));
                        ui->tableWidget->setItem(row_1,1,new QTableWidgetItem(it.value().putUrgeOrder()));//
                        row_1++;
                    }
                else if(it.value().putDishState() == "开始做")
                    {
                        ui->tableWidget_2->insertRow(row_2);
                        ui->tableWidget_2->setItem(row_2,0,new QTableWidgetItem(it.value().putDishName()));
                        ui->tableWidget_2->setItem(row_2,1,new QTableWidgetItem(it.value().putUrgeOrder()));//
                        row_2++;
                    }
                    else
                        {
                            ui->tableWidget_3->insertRow(row_3);
                            ui->tableWidget_3->setItem(row_3,0,new QTableWidgetItem(it.value().putDishName()));
                            row_3++;
                        }
            }

        }
    }
}

void cooking::on_pushButton_clicked()
{
    if(ui->tableWidget->isItemSelected(ui->tableWidget->currentItem()))
    {

   int row = ui->tableWidget->currentRow();
   int row_2 = ui->tableWidget_2->rowCount();

   ui->tableWidget_2->insertRow(row_2);
   ui->tableWidget_2->setItem(row_2,0,new QTableWidgetItem(ui->tableWidget->item(row,0)->text()));
   ui->tableWidget_2->setItem(row_2,1,new QTableWidgetItem(ui->tableWidget->item(row,1)->text()));//

   ui->tableWidget->removeRow(row);
    }
}

void cooking::on_pushButton_2_clicked()
{
    if(ui->tableWidget_2->isItemSelected(ui->tableWidget_2->currentItem()))
    {
    int row_2 = ui->tableWidget_2->currentRow();
    int row_3 = ui->tableWidget_3->rowCount();

    ui->tableWidget_3->insertRow(row_3);
    ui->tableWidget_3->setItem(row_3,0,new QTableWidgetItem(ui->tableWidget_2->item(row_2,0)->text()));

    ui->tableWidget_2->removeRow(row_2);
    }
}
void cooking::closeEvent(QCloseEvent *event)
{
    int row = ui->tableWidget->rowCount();
    int row_2 = ui->tableWidget_2->rowCount();
    int row_3 = ui->tableWidget_3->rowCount();

    QHash<int,Desk>::iterator i;

    for(i=Restaurant::Instance()->DeskHash.begin();i!=Restaurant::Instance()->DeskHash.end();++i)
    {
        if(i.value().returnDeskNum() == num)
        {
            for(int n=0;n<row_2;n++)
            {
                QHash<int,OneDish>::iterator it;

                for(it=i.value().returnDish().getDishmap().begin();it!=i.value().returnDish().getDishmap().end();++it)
                    {
                        if(it.value().putDishName() == ui->tableWidget_2->item(n,0)->text()&&it.value().putDishState() == "未做")
                            {
                                it.value().changeDishState("开始做");
                                break;
                            }
                    }
            }
            for(int n=0;n<row_3;n++)
               {
                QHash<int,OneDish>::iterator it;

                for(it=i.value().returnDish().getDishmap().begin();it!=i.value().returnDish().getDishmap().end();++it)
                    {
                        if(it.value().putDishName() == ui->tableWidget_3->item(n,0)->text()&&(it.value().putDishState() == "未做"||it.value().putDishState() == "开始做"))
                            {
                                it.value().changeDishState("已做完");
                                break;
                            }
                    }
               }
         }
     }

    if(row == 0 && row_2 == 0)//desk??
    {
        QHash<int,Desk>::iterator i;

        for(i=Restaurant::Instance()->DeskHash.begin();i!=Restaurant::Instance()->DeskHash.end();++i)
        {
            if(i.value().returnDeskNum() == num)
            {
                QHash<int,Cook>::iterator it;

                for(it=Restaurant::Instance()->CookHash.begin();it!=Restaurant::Instance()->CookHash.end();++it)
                {
                    if(it.value().ReturnCookName() == i.value().returnCookName())
                    {
                        it.value().changeDesk(0);
                    }
                }
            }
        }
    }
    for(int n=0;n<row;n++)
    {
        ui->tableWidget->removeRow(0);
    }

    for(int n=0;n<row_2;n++)
    {
        ui->tableWidget_2->removeRow(0);
    }

    for(int n=0;n<row_3;n++)
    {
        ui->tableWidget_3->removeRow(0);
    }

}
