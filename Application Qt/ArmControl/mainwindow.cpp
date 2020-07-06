#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtDebug>
#include <QtCore>
#include <QtGui>
#include <QStringList>
#include <QPixmap>

QSerialPort serial;

void serial_init(QString portName,QString baudrate);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Adrien/Documents/Projet Bras robot/LP-MECSE2020-Projet-Bras-Robot/Application Qt/ArmControl/Pictures/hand_.png");
    int w = ui->label_hand->width();
    int h = ui->label_hand->height();

    foreach (const QSerialPortInfo &ThisPort, QSerialPortInfo::availablePorts())
    {
    ui->comboBox->addItem(ThisPort.portName());
    }
    
    ui->label_hand->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatioByExpanding));
}

MainWindow::~MainWindow()
{
    serial.close();
    delete ui;
}


void MainWindow::on_pushButton_9_clicked()
{
    qInfo() << "click\n";
    
   serial_init(ui->comboBox->currentText(),ui->comboBox_2->currentText());
   serial.open(QSerialPort::WriteOnly);

}

void serial_init(QString portName,QString baudrate)
{
    serial.setPortName(portName);
    serial.setBaudRate(baudrate.toInt());
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

}
void MainWindow::on_pushButton_1_clicked()
{
    serial.write("1");
}

void MainWindow::on_pushButton_2_clicked()
{
    serial.write("0");
}



void MainWindow::on_pushButton_3_clicked()
{
    serial.write("3");
}



void MainWindow::on_pushButton_4_clicked()
{
    serial.write("2");
}



void MainWindow::on_pushButton_5_clicked()
{
    serial.write("5");
}

void MainWindow::on_pushButton_6_clicked()
{
    serial.write("4");
}

void MainWindow::on_pushButton_7_clicked()
{
    serial.write("7");
}



void MainWindow::on_pushButton_8_clicked()
{
    serial.write("6");
}
