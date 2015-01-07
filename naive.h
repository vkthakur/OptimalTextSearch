#ifndef NAIVE_H
#define NAIVE_H

#include <QDialog>

namespace Ui {
class naive;
}

class naive : public QDialog
{
    Q_OBJECT

public:
    explicit naive(QWidget *parent = 0);
    ~naive();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::naive *ui;
};

#endif // NAIVE_H
