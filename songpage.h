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

signals:
    void playRequested(const QString &filePath,
                       const QString &lyricPath,
                       const QString &coverPath);

private:
    Ui::songPage *ui;
};

#endif // SONGPAGE_H
