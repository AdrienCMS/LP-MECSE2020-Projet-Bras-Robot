#include "mythread.h"
#include <QtDebug>
#include <QtGlobal>
#include <QTcpServer>
#include <QTcpSocket>


myThread::myThread() :QThread()
{

}

void myThread::run()
{

    static int val = 0;


    while(1)
    {

        qInfo() << "thread alive\n";

    }

}


