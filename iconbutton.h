#ifndef ICONBUTTON_H
#define ICONBUTTON_H
#include "QToolButton"

class IconButton : public QToolButton
{
    Q_OBJECT
public:
    explicit IconButton(QWidget *parent = nullptr);
};

#endif // ICONBUTTON_H
