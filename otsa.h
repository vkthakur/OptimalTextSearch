#ifndef OTSA_H
#define OTSA_H

#include <QDialog>

namespace Ui {
class otsa;
}

class otsa : public QDialog
{
    Q_OBJECT

public:
    explicit otsa(QWidget *parent = 0);
    ~otsa();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::otsa *ui;
};

#endif // OTSA_H
