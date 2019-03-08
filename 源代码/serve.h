#ifndef SERVE_H
#define SERVE_H

#include <QDialog>
#include "restaurant.h"

namespace Ui {
class serve;
}

class serve : public QDialog
{
    Q_OBJECT

public:
    explicit serve(QWidget *parent = 0);
    ~serve();
    void showDish(int n);

    void closeEvent(QCloseEvent *event);

private:
    Ui::serve *ui;
};

#endif // SERVE_H
