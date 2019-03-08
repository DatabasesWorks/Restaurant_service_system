#include "pay.h"
#include "ui_pay.h"

pay::pay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pay)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(2);

    QStringList header;
    header<<tr("菜名")<<tr("单价/元");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget-> horizontalHeader()->setStretchLastSection(true);//设置充满表宽度
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置只能选取一行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑

}

pay::~pay()
{
    delete ui;
}

void pay::showDish()
{
    ui->label->setText("桌号：" + QString::number(Restaurant::Instance()->desk.returnDeskNum()));

    int row_count = ui->tableWidget->rowCount(); //获取表单行数
    int price = 0;
    QHash<int,Desk>::iterator i;

    for(i=Restaurant::Instance()->DeskHash.begin();i!=Restaurant::Instance()->DeskHash.end();++i)
    {
        if(i.value().returnDeskNum() == Restaurant::Instance()->desk.returnDeskNum())
        {
            QHash<int,OneDish>::iterator it;

            for(it=i.value().returnDish().getDishmap().begin();it!=i.value().returnDish().getDishmap().end();++it)
            {
                ui->tableWidget->insertRow(row_count);
                ui->tableWidget->setItem(row_count,0,new QTableWidgetItem(it.value().putDishName()));
                ui->tableWidget->setItem(row_count,1,new QTableWidgetItem(it.value().putDishPrice()));

                price += it.value().putDishPrice().toInt();
            }
        }
    }

    ui->label_2->setText("合计：" + QString::number(price));

}

void pay::on_pushButton_clicked()
{
    QDialog::accept();
    this->close();
}
