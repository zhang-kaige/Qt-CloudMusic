#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QSplitter>
#include "homepage.h"
#include "userpage.h"
#include "songpage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void openFile();


private:
    Ui::MainWindow *ui;

    QMediaPlayer *player = nullptr;
    QSplitter *splitter = nullptr;

    Homepage *hp = nullptr;
    UserPage *up = nullptr;
    songPage *sp = nullptr;
};
#endif // MAINWINDOW_H
