#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QFileDialog"
#include "QSplitter"
#include "QTimer"
#include "QScrollBar"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "wc";

    player = new QMediaPlayer(this);
    player->setVolume(70);

    splitter = new QSplitter(Qt::Horizontal,this);

//    connect(ui->fileButton,&QPushButton::clicked,this,&MainWindow::openFile);

    ui->leftWidget->setViewMode(QListView::ListMode);
    ui->leftWidget->setIconSize(QSize(20,20));
    ui->leftWidget->setSpacing(6);
    ui->leftWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->leftWidget->setUniformItemSizes(true);
    ui->leftWidget->setFrameShape(QFrame::NoFrame);
    ui->leftWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    auto addItem = [&](const QIcon& icon, const QString& text, int pageIndex){
        auto *it = new QListWidgetItem(icon,text);
        it->setSizeHint(QSize(160,36));
        it->setData(Qt::UserRole,pageIndex);
        ui->leftWidget->addItem(it);
    };

    hp = new Homepage(this);
    up = new UserPage(this);
    sp = new songPage(this);

    int idxHp = ui->rightWidget->addWidget(hp);
    int idxSp = ui->rightWidget->addWidget(sp);
    int idxUp = ui->rightWidget->addWidget(up);

    connect(ui->leftWidget, &QListWidget::currentItemChanged,this,
            [this](QListWidgetItem* cur,QListWidgetItem*){
            if(!cur) return;
            ui->rightWidget->setCurrentIndex(cur->data(Qt::UserRole).toInt());
        }
    );
    qDebug() << "idxHp:" << idxHp;
    qDebug() << "idxHp:" << idxUp;
    qDebug() << "idxSp:" << idxSp;
    addItem(QIcon(":/images/ico.png"),tr("主页"),idxHp);
    addItem(QIcon(":/images/icon.png"),tr("歌单"),idxSp);
    addItem(QIcon(":/images/icon.png"),tr("个人信息"),idxUp);



    ui->leftWidget->setCurrentRow(0);

    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,4);
    ui->splitter->setCollapsible(0,false);

    QTimer::singleShot(0,this,[this]{
        int w = ui->splitter->size().width();
            if (w <= 0) w = this->width();            // 兜底
            QList<int> sizes{ w * 1 / 5, w * 4 / 5 }; // 1:4
            ui->splitter->setSizes(sizes);
        });

    ui->barWidget->setFixedHeight(90);

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
//   ui->songLabel->setText(file);
   qDebug() << "选择的文件是:" << file;

   player->setMedia(QUrl::fromLocalFile(file));
   player->play();
}

