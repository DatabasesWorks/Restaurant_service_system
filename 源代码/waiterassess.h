#ifndef WAITERASSESS_H
#define WAITERASSESS_H

#include <QDialog>

namespace Ui {
class waiterassess;
}

class waiterassess : public QDialog
{
    Q_OBJECT

public:
    explicit waiterassess(QWidget *parent = 0);
    ~waiterassess();

private:
    Ui::waiterassess *ui;
};

#endif // WAITERASSESS_H
