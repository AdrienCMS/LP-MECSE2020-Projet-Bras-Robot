#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>

//Ici, on défini la classe MyThread qui hérite de la classe QThread
class myThread :public QThread
{
    Q_OBJECT
public:
//On défini les méthodes de la classe
    myThread();
    virtual void run();
//Ainsi que les signaux quelle est à même d'envoyer
signals:
    void NewVal(int);
};


#endif // MYTHREAD_H
