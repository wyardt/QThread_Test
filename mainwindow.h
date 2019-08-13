#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QDebug>
#include "background.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    BackGround *bg;
    QUdpSocket *socket;
    QByteArray *buf;
public slots:
    void CatchGenerator();
    void CatchUDP(void);
signals:
    void TriggerUDP(QByteArray *);
};

#endif // MAINWINDOW_H
