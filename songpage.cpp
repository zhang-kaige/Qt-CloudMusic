#include "songpage.h"
#include "ui_songpage.h"
#include <QStandardItemModel>
#include <QDate>
#include <QDebug>
#include "QScrollBar"
#include "songtablemodel.h"
#include "song.h"

songPage::songPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::songPage)
{
    ui->setupUi(this);

    auto *model = new SongTableModel(this);
    QVector<Song> songs;

    // 填点数据
    songs.push_back(Song{
        1,
        "青花瓷",
        "周杰伦",
        "我很忙",
        268,
        true,
        QDate(2007,11,2),
        "/path/青花瓷.mp3",
        "/path/青花瓷.lrc",
        "/path/我很忙.jpg"
    });


    model->setSongs(songs);
    ui->songTable->setModel(model);

    // 视图外观（列宽策略）
    auto tv = ui->songTable;
    tv->setSelectionBehavior(QAbstractItemView::SelectRows);
    tv->setSelectionMode(QAbstractItemView::SingleSelection);
    tv->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tv->setAlternatingRowColors(true);
    tv->setShowGrid(false);
    tv->verticalHeader()->hide();
    auto hh = tv->horizontalHeader();
    hh->setSectionResizeMode(SongTableModel::ColIdx,    QHeaderView::ResizeToContents);
    hh->setSectionResizeMode(SongTableModel::ColTitle,  QHeaderView::Stretch);
    hh->setSectionResizeMode(SongTableModel::ColArtist, QHeaderView::ResizeToContents);
    hh->setSectionResizeMode(SongTableModel::ColAlbum,  QHeaderView::ResizeToContents);
    hh->setSectionResizeMode(SongTableModel::ColLike,   QHeaderView::Fixed);
    tv->setColumnWidth(SongTableModel::ColLike, 28);
    hh->setSectionResizeMode(SongTableModel::ColDur,    QHeaderView::ResizeToContents);
    hh->setSectionResizeMode(SongTableModel::ColDate,   QHeaderView::ResizeToContents);



//    auto st = ui->songTable;
//    st->setSelectionBehavior(QAbstractItemView::SelectRows);
//    st->setSelectionMode(QAbstractItemView::SingleSelection);
//    st->setEditTriggers(QAbstractItemView::NoEditTriggers);

//    st->setAlternatingRowColors(true);
//    st->setShowGrid(false);
//    st->verticalHeader()->hide();
//    st->horizontalHeader()->setHighlightSections(false);
//    st->horizontalHeader()->setStretchLastSection(false);

//    st->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
//    st->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
//    st->setTextElideMode(Qt::ElideRight);
//    st->setIconSize(QSize(24,24));
//    st->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

//    auto *model = new QStandardItemModel(st);
//    model->setColumnCount(7);
//    model->setHorizontalHeaderLabels(
//        {"#", "标题", "歌手", "专辑", "喜欢", "时长", "添加时间"}
//    );

//    st->setModel(model);

//    auto hh = st->horizontalHeader();
//    hh->setSectionResizeMode(0, QHeaderView::ResizeToContents);
//    hh->setSectionResizeMode(1, QHeaderView::Stretch);
//    hh->setSectionResizeMode(2, QHeaderView::ResizeToContents);
//    hh->setSectionResizeMode(3, QHeaderView::ResizeToContents);
//    hh->setSectionResizeMode(4, QHeaderView::Fixed);         // ♥ 列固定更稳
//    st->setColumnWidth(4, 28);
//    hh->setSectionResizeMode(5, QHeaderView::ResizeToContents);
//    hh->setSectionResizeMode(6, QHeaderView::ResizeToContents);


//    auto mmss = [](int sec){
//        return QString("%1:%2").arg(sec/60,2,10,QChar('0'))
//                               .arg(sec%60,2,10,QChar('0'));
//    };
//    auto addRow = [&](int idx, const QString& title, const QString& artist,
//                      const QString& album, bool liked, int durSec, QDate d){
//        QList<QStandardItem*> row;
//        auto *c0 = new QStandardItem(QString::number(idx));  c0->setTextAlignment(Qt::AlignCenter); row<<c0;
//        auto *c1 = new QStandardItem(title);                                                     row<<c1;
//        auto *c2 = new QStandardItem(artist);                                                    row<<c2;
//        auto *c3 = new QStandardItem(album);                                                     row<<c3;
//        auto *c4 = new QStandardItem(liked ? QStringLiteral("♥") : QString()); c4->setTextAlignment(Qt::AlignCenter); row<<c4;
//        auto *c5 = new QStandardItem(mmss(durSec));                          c5->setTextAlignment(Qt::AlignCenter); row<<c5;
//        auto *c6 = new QStandardItem(d.toString("yyyy-MM-dd"));              c6->setTextAlignment(Qt::AlignCenter); row<<c6;
//        model->appendRow(row);
//    };
//    addRow(1,  "青花瓷",   "周杰伦", "我很忙",             true, 268, QDate(2007,11,2));
//    addRow(2,  "稻香",     "周杰伦", "魔杰座",             false,215, QDate(2008,10,15));
//    addRow(3,  "夜曲",     "周杰伦", "十一月的萧邦",       true, 254, QDate(2005,11,1));
//    addRow(4,  "突然好想你","五月天","后青春期的诗",       false,268, QDate(2008,10,23));
//    addRow(5,  "New Boy",  "朴树",   "我去2000年",         true, 240, QDate(1999,6,1));
//    addRow(6,  "在木星",   "朴树",   "猎户星座",           false,299, QDate(2017,11,28));
//    addRow(7,  "成都",     "赵雷",   "成都",               true, 320, QDate(2016,11,28));
//    addRow(8,  "平凡之路","朴树",   "后会无期",           true, 332, QDate(2014,7,16));
//    addRow(9,  QStringLiteral("南山南"),     QStringLiteral("马頔"),
//           QStringLiteral("孤岛"),           true,  295, QDate(2014,11,11));

//    addRow(10, QStringLiteral("演员"),       QStringLiteral("薛之谦"),
//           QStringLiteral("初学者"),         false, 268, QDate(2015,6,5));

//    addRow(11, QStringLiteral("告白气球"),   QStringLiteral("周杰伦"),
//           QStringLiteral("周杰伦的床边故事"), true, 215, QDate(2016,6,24));

//    addRow(12, QStringLiteral("年少有为"),   QStringLiteral("李荣浩"),
//           QStringLiteral("耳朵"),           true,  266, QDate(2018,10,17));

//    addRow(13, QStringLiteral("光年之外"),   QStringLiteral("邓紫棋"),
//           QStringLiteral("光年之外"),       false, 230, QDate(2016,12,30));

//    addRow(14, QStringLiteral("体面"),       QStringLiteral("于文文"),
//           QStringLiteral("前任3 电影原声"),  true,  247, QDate(2017,12,29));

//    addRow(15, QStringLiteral("追光者"),     QStringLiteral("岑宁儿"),
//           QStringLiteral("夏至未至 原声"),   false, 272, QDate(2017,6,15));

//    addRow(16, QStringLiteral("理想三旬"),   QStringLiteral("陈鸿宇"),
//           QStringLiteral("浓烟下的诗歌电台"), true,  246, QDate(2014,10,20));




}

songPage::~songPage()
{
    delete ui;
}
