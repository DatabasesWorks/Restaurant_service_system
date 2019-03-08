#ifndef COOKASSESS_H
#define COOKASSESS_H

#include <QDialog>

namespace Ui {
class cookassess;
}

class cookassess : public QDialog
{
    Q_OBJECT

public:
    explicit cookassess(QWidget *parent = 0);
    ~cookassess();

    void showIt();
private:
    Ui::cookassess *ui;
};

#endif // COOKASSESS_H
