#include "ejemplo1.h"

ejemplo1::ejemplo1(): Ui_Counter()
{
	for(int j=0;j<4;j++){
	  hilos[j]=new MyThread();
	}
	setupUi(this);
	show();
	connect(button, SIGNAL(clicked()), this, SLOT(doButton()) );
//fase1// connect(timer, SIGNAL(timeout()), this, SLOT(doLcd()) );
//fase2// connect(hilo, SIGNAL(started()), this, SLOT(doLcd()) );
//fase2// connect(hilo, SIGNAL(tick()), this, SLOT(doLcd()));
//	connect(hilos[numhilo], SIGNAL(started()), this, SLOT(doLcd()) );
	connect(hilos[0], SIGNAL(tick()), this, SLOT(doLcd()) );
	connect(hilos[0], SIGNAL(finished()), this, SLOT(sumhilo()) );
	connect(hilos[1], SIGNAL(tick()), this, SLOT(doLcd()) );
	connect(hilos[1], SIGNAL(finished()), this, SLOT(sumhilo()) );
	connect(hilos[2], SIGNAL(tick()), this, SLOT(doLcd()) );
	connect(hilos[2], SIGNAL(finished()), this, SLOT(sumhilo()) );
	connect(hilos[3], SIGNAL(tick()), this, SLOT(doLcd()) );
	connect(hilos[3], SIGNAL(finished()), this, SLOT(sumhilo()) );
}

ejemplo1::~ejemplo1()
{
}

void ejemplo1::doButton()
{
	qDebug() << "click on button";
//fase1// timer->start(1000);
	
	
	if(activo==true){
	  activo=false;
//fase2//  hilo->terminate();
	  hilos[0]->wait();
	}
	else{
	  activo=true;
//fase2//  hilo->start();
	  hilos[numhilo]->start();
	  
	}
}

void ejemplo1::doLcd()
{
        contador++;
	lcdNumber->display(contador);
	qDebug() << "Contador+1";	
  
	
}

void ejemplo1::sumhilo()
{
        numhilo++;
	qDebug() << "Siguiente hilo: "+ numhilo;
	lcdNumber2->display(numhilo);
	if(numhilo<4){
	  hilos[numhilo]->start();
	}
}



