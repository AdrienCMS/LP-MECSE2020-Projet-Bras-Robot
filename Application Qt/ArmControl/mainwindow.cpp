#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtDebug>
#include <QtCore>
#include <QtGui>
#include <QPixmap>

 myThread com;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Adrien/Documents/Projet Bras robot/LP-MECSE2020-Projet-Bras-Robot/Application Qt/ArmControl/Pictures/hand_.png");
    int w = ui->label_hand->width();
    int h = ui->label_hand->height();

    ui->label_hand->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatioByExpanding));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_9_clicked()
{
    qInfo() << "click\n";
    com.start();
}
