#ifndef COOKDLG_H
#define COOKDLG_H

#include <QDialog>
#include "database.h"
#include "restaurant.h"
#include "cooking.h"

namespace Ui {
class cookdlg;
}

class cookdlg : public QDialog
{
    Q_OBJECT

public:
    explicit cookdlg(QWidget *parent = 0);
    ~cookdlg();

    void showCookDesk(const QString &name);
private slots:
    void on_pushButton_clicked();
    void on_tableWidget_clicked(const QModelIndex &index);
    void closeEvent(QCloseEvent *event);

private:
    Ui::cookdlg *ui;
    cooking c;
    QString username;
    int desknum;
};

#endif // COOKDLG_H
