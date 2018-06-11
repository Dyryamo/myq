#include "myq.h"
#include <QDebug>
void myq::init(){
   loginwindows = new login(this);
}
myq::myq(QWidget *parent)
    : QMainWindow(parent)
{
   init();
   loginwindows->show();
}

myq::~myq()
{

}
