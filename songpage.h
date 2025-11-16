#ifndef SONGPAGE_H
#define SONGPAGE_H

#include <QWidget>

namespace Ui {
class songPage;
}

class songPage : public QWidget
{
    Q_OBJECT

public:
    explicit songPage(QWidget *parent = nullptr);
    ~songPage();

private:
    Ui::songPage *ui;
};

#endif // SONGPAGE_H
