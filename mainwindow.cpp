#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bg = new BackGround();
    connect(bg, SIGNAL(Generator()), this, SLOT(CatchGenerator()));
    connect(ui->btnA, SIGNAL(clicked()), bg, SLOT(Trigger()));
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
