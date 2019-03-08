#include "waiterassess.h"
#include "ui_waiterassess.h"

waiterassess::waiterassess(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::waiterassess)
{
    ui->setupUi(this);
}

waiterassess::~waiterassess()
{
    delete ui;
}
