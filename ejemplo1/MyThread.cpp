#include "MyThread.h"

MyThread::MyThread()
{
    
}
void MyThread::run()
{
//fase2//  bool infi=true;
    qDebug() << "hilo iniciado";
//fase2//  while(infi){
    for(int i=0;i<5;i++){
    sleep(1);
    emit tick();
      qDebug() << "hilo emitido";
  }    
}

MyThread::~MyThread()
{
    
}