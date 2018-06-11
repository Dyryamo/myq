#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QMainWindow>
#include <QMouseEvent>
#include <QRect>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();
     void setAreaMovable(const QRect *rt);

private slots:
    void on_closebtn_clicked();
    void iconIsActived(QSystemTrayIcon::ActivationReason reason);

    void on_pushButton_clicked(bool checked);

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void closeEvent(QCloseEvent *);
    void checkaccoundandpasswd();
private:
    void initrayIcon();
    void initraymenu();
private:
    Ui::login *ui;
    QRect m_areaMovable;
    bool m_bPressed;
    QPoint m_ptPress;
    QSystemTrayIcon *trayIcon;  //托盘
    QMenu  *trayContextMenu;
    //托盘事件
    QAction *quitAction;        //退出

};

#endif // LOGIN_H
