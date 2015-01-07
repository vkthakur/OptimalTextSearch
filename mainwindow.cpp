#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "otsa.h"
#include "naive.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("MENU");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    otsa ot;
    ot.setModal(true);
    ot.exec();

}

void MainWindow::on_pushButton_clicked()
{
    naive nv;
    nv.setModal(true);
    nv.exec();
}
