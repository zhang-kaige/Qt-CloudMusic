#ifndef BOTTOMBAR_H
#define BOTTOMBAR_H

#include <QWidget>
#include "QMediaPlayer"
namespace Ui {
class BottomBar;
}

class BottomBar : public QWidget
{
    Q_OBJECT

public:
    explicit BottomBar(QWidget *parent = nullptr);
    ~BottomBar();

    void setSongInfo(const QString &title, const QString &artist, const QString &coverPath);
    QPixmap makeRoundPixmap(const QPixmap &src, int size);
    void startCoverRotate();
private:
    Ui::BottomBar *ui;


};

#endif // BOTTOMBAR_H
