#ifndef SONG_H
#define SONG_H

#include <QString>  // 建议用尖括号
#include <QDate>

// 纯数据结构：表示一首歌
struct Song {
    int     id = 0;
    QString title;
    QString artist;
    QString album;

    int     durationSec = 0;
    bool    liked = false;
    QDate   addDate;

    QString filePath;     // 音频路径
    QString lyricPath;    // 歌词路径
    QString coverPath;    // 封面路径

    // 把总秒数格式化为 "mm:ss"
    QString durationStr() const {
        return QString("%1:%2")
               .arg(durationSec/60, 2, 10, QChar('0'))
               .arg(durationSec%60, 2, 10, QChar('0'));
    }
};

#endif // SONG_H
