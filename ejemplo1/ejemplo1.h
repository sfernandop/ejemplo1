#ifndef ejemplo1_H
#define ejemplo1_H

#include <QtGui>
#include "ui_counterDlg.h"
#include "MyThread.h"
//#include <thread>



class ejemplo1 : public QWidget, public Ui_Counter
{
Q_OBJECT
public:
    ejemplo1();
    virtual ~ejemplo1();
  //  QTimer *timer =new QTimer(this);
    int contador=0;
    bool activo=false;
    //MyThread *hilo =new MyThread();
    MyThread *hilos[4];
    int numhilo=0;
    
public slots:
	void doButton();
	void doLcd();
	void sumhilo();
};

#endif // ejemplo1_H
