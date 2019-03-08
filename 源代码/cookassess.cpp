#include "cookassess.h"
#include "ui_cookassess.h"

cookassess::cookassess(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cookassess)
{
    ui->setupUi(this);
}

cookassess::~cookassess()
{
    delete ui;
}
