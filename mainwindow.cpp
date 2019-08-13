#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    buf = new QByteArray;

    bg = new BackGround();
    //connect(ui->btnA, SIGNAL(clicked()), bg, SLOT(Trigger()));
    connect(bg, SIGNAL(Generator()), this, SLOT(CatchGenerator()));


    socket = new QUdpSocket;
    socket->bind(QHostAddress::LocalHost, 1234);
    connect(socket, SIGNAL(readyRead()), this, SLOT(CatchUDP()));
    connect(this, SIGNAL(TriggerUDP(QByteArray *)), bg, SLOT(Trigger(QByteArray *)));
    char data[] = "bind";
    socket->writeDatagram(data, sizeof(data), QHostAddress::LocalHost, 1234);

    bg->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CatchGenerator()
{
    ui->textOut->appendPlainText("Catched");
}

void MainWindow::CatchUDP()
{
    while (socket->hasPendingDatagrams() == true)
    {
        buf->resize(socket->pendingDatagramSize());
        socket->readDatagram(buf->data(),buf->size());

        qDebug() << "get data" << endl;
        emit TriggerUDP(buf);
    }
}
