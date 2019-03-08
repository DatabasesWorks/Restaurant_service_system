#include "administrator.h"
#include "ui_administrator.h"

administrator::administrator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrator)
{
    ui->setupUi(this);
}

administrator::~administrator()
{
    delete ui;
}

void administrator::on_pushButton_clicked()
{
   mc.showCustomer();
   mc.show();
}

void administrator::on_pushButton_2_clicked()
{
    md.showDishMap();
    md.show();
}

void administrator::on_pushButton_3_clicked()
{
    mw.showWaiter();
    mw.show();
}

void administrator::on_pushButton_4_clicked()
{
    mco.showCook();
    mco.show();
}
