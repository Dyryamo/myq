#ifndef MYQ_H
#define MYQ_H

#include <QMainWindow>
#include "login.h"
class myq : public QMainWindow
{
    Q_OBJECT
    login *loginwindows;
public:
    myq(QWidget *parent = 0);
    ~myq();
    void init();
};

#endif // MYQ_H
