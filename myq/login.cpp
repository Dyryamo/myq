#include "login.h"
#include "ui_login.h"
#include <QDebug>
void login::initrayIcon(){

    qDebug()<<"hello initrayIcon"<<endl;
    trayIcon = new QSystemTrayIcon(this);
    this->setWindowIcon(QIcon(tr("avatar.png")));
    trayIcon->setToolTip(QString("myq"));
    trayIcon->setContextMenu(trayContextMenu);
    connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(iconIsActived(QSystemTrayIcon::ActivationReason)));
    trayIcon->setIcon(QIcon(tr("bitbug_favicon.ico")));
    trayIcon->show();
}

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{

    this->setParent(NULL);
    setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
    m_areaMovable.setRect(0,0,427,325);

    initraymenu();
    initrayIcon();
}
void login::initraymenu(){

    qDebug()<<"hello world"<<endl;
    quitAction =new QAction(tr("退出"), this);
    quitAction->setIcon(QIcon(tr("bitbug_favicon.ico")));
    connect(quitAction,SIGNAL(triggered(bool)),qApp,SLOT(quit()));
    trayContextMenu=new QMenu(this);
    trayContextMenu->addAction(quitAction);
}
login::~login()
{
    delete ui;
}

//关闭窗口
void  login::closeEvent(QCloseEvent *event){
    if(trayIcon->isVisible()) {
        hide();
        trayIcon->showMessage(tr("提示"), tr("你的myq正在后台运行"));
        event->ignore();
    }
    else {
        event->accept();
    }
}
void login::iconIsActived(QSystemTrayIcon::ActivationReason reason){
    switch(reason) {
        case QSystemTrayIcon::DoubleClick:
        case QSystemTrayIcon::Trigger:
        if(this->isVisible()==true) {
        }
        else {
            this->show();
            this->activateWindow();
        }
        break;
        default:
        break;
   }
}
void login::on_closebtn_clicked()
{
    this->close();
}

void login::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        m_ptPress = event->pos();
        m_bPressed = m_areaMovable.contains(m_ptPress);
    }

}

void login::mouseMoveEvent(QMouseEvent *event){
    if(m_bPressed){

        move(pos() + event->pos() - m_ptPress);
    }
}

void login::mouseReleaseEvent(QMouseEvent *event){
    m_bPressed = false;
}





void login::checkaccoundandpasswd(){
    QString a = ui->username->text();


}

void login::on_pushButton_clicked(bool checked)
{
    checkaccoundandpasswd();
}
