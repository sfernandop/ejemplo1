 #ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QtGui>

class MyThread: public QThread
{
    Q_OBJECT
signals:
  void tick();
  
public:
  MyThread();
  ~MyThread();
private:
    void run();

};

#endif // MYTHREAD_H
