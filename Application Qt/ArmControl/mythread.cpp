#include "mythread.h"
#include <QtDebug>
#include <QtGlobal>
#include <QTcpServer>
#include <QTcpSocket>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QtGui>
#include <QSerialPort>
#include <QSerialPortInfo>

QSerialPort serial;

myThread::myThread() :QThread()
{

}

void myThread::run()
{

    static int val = 0;


    while(1)
    {

        serial.setPortName()

        qInfo() << "thread alive\n";

    }

}


