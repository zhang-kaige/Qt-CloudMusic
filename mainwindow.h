#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QSplitter>
#include "homepage.h"
#include "userpage.h"
#include "songpage.h"
#include "bottombar.h"

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

private slots:
    void handlePlayRequested(const QString &filePath,
                             const QString &lyricPath,
                             const QString &coverPath);


private:
    Ui::MainWindow *ui;

    QMediaPlayer *player = nullptr;
    QSplitter *splitter = nullptr;

    Homepage *hp = nullptr;
    UserPage *up = nullptr;
    songPage *sp = nullptr;
    BottomBar *bb = nullptr;
};
#endif // MAINWINDOW_H
