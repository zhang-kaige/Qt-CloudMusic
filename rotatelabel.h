#ifndef ROTATELABEL_H
#define ROTATELABEL_H

#include "QLabel"
#include <QPropertyAnimation>
#include "QPainter"

class RotateLabel : public QLabel
{
    Q_OBJECT
    Q_PROPERTY(qreal angle READ angle WRITE setAngle)

public:
    explicit RotateLabel(QWidget *parent=nullptr)
        :QLabel(parent)
    {
        anim = new QPropertyAnimation(this, "angle", this);
        anim->setDuration(4000);
        anim->setStartValue(0);
        anim->setEndValue(360);
        anim->setLoopCount(-1);
    }

    qreal angle() const {return m_angle;}
    void setAngle(qreal angle) {m_angle = angle;update();}

    void startRotate() {anim->start();}
    void stopRotate() {anim->stop();}

protected:
    void paintEvent(QPaintEvent *) override{
        QPainter p(this);
        p.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
        p.translate(width()/2,height()/2);
        p.rotate(m_angle);
        p.translate(-width()/2, -height()/2);
        QLabel::paintEvent(nullptr);
    }

private:
    qreal m_angle = 0;
    QPropertyAnimation *anim;
};

#endif // ROTATELABEL_H
