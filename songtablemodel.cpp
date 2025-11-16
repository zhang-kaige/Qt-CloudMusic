#include "songtablemodel.h"

SongTableModel::SongTableModel(QObject *parent)
    :QAbstractTableModel(parent)
{

}

int SongTableModel::rowCount(const QModelIndex &) const
{
    return m_songs.size();
}

int SongTableModel::columnCount(const QModelIndex &) const
{
    return ColCount;
}

QVariant SongTableModel::data(const QModelIndex &i, int role) const
{
    if(!i.isValid() || i.row() < 0|| i.row() >= m_songs.size())
        return {};
    const Song &s = m_songs[i.row()];

    if(role == Qt::DisplayRole)
    {
        switch (i.column()) {
        case ColIdx: return i.row() + 1;
        case ColTitle: return s.title;
        case ColArtist: return s.artist;
        case ColAlbum:  return s.album;
        case ColLike:   return s.liked ? QStringLiteral("♥") : QString();
        case ColDur:    return s.durationStr();
        case ColDate:   return s.addDate.toString("yyyy-MM-dd");
        default:        break;
        }
    } else if(role == Qt::UserRole)
    {
        return i.row();
    }
    return {};
}

QVariant SongTableModel::headerData(int section, Qt::Orientation o, int role) const
{
    if(o == Qt::Horizontal && role == Qt::DisplayRole)
    {
        static const QStringList h = {"#","标题","歌手","专辑","喜欢","时长","添加时间"};
        return  h.value(section);
    }
    return {};
}

Qt::ItemFlags SongTableModel::flags(const QModelIndex &index) const
{
    if(!index.isValid()) return Qt::NoItemFlags;
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

const Song &SongTableModel::songAt(int row) const
{
    return m_songs[row];
}

void SongTableModel::setSongs(QVector<Song> songs)
{
    beginResetModel();
    m_songs = std::move(songs);
    endResetModel();
}


