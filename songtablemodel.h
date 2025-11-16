#ifndef SONGTABLEMODEL_H
#define SONGTABLEMODEL_H

#include "QAbstractTableModel"
#include "QVector"
#include "song.h"


class SongTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    enum Coulumns {ColIdx=0, ColTitle, ColArtist, ColAlbum, ColLike, ColDur, ColDate, ColCount };

    explicit SongTableModel(QObject *parent=nullptr);

    int rowCount(const QModelIndex& = QModelIndex()) const override;
    int columnCount(const QModelIndex& = QModelIndex())const override;

    QVariant data(const QModelIndex& index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orient, int role) const override;

    Qt::Qt::ItemFlags flags(const QModelIndex &index) const override;

    const Song& songAt(int row) const;
    void setSongs(QVector<Song> songs);
    void appendSong(const Song& s);
    void clear();
    bool togglelike(int row);

private:
    QVector<Song> m_songs;
};

#endif // SONGTABLEMODEL_H
