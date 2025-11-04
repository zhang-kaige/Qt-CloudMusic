#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QFileDialog"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "wc";

    player = new QMediaPlayer(this);
    player->setVolume(70);

    connect(ui->fileButton,&QPushButton::clicked,this,&MainWindow::openFile);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
   const QString file = QFileDialog::getOpenFileName(
               this,
               tr("选择文件"),
               QString(),
               tr("所有文件 (*);;图片 (*.png *.jpg *.jpeg *.bmp);;文本 (*.txt)")
               );

   if(file.isEmpty())
   {
       qDebug() << "取消选择!";
       return;
   }
   ui->songLabel->setText(file);
   qDebug() << "选择的文件是:" << file;

   player->setMedia(QUrl::fromLocalFile(file));
   player->play();
}

