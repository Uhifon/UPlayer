#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     myPlayer =new Play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    QString txt = item->text(0);
    void* hwd = (void*)ui->label->winId();
    QString url ="http://ivi.bupt.edu.cn/hls/cctv1hd.m3u8";
     myPlayer->Start(hwd,url);
}
