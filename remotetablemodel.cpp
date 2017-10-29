#include "remotetablemodel.h"

RemoteTableModel::RemoteTableModel(QWidget *parent)
    : m_arrRowLst(new QList<QStringList>)
{

}

RemoteTableModel::~RemoteTableModel()
{
    m_horiHeaderLst.clear();
    m_vertHeaderLst.clear();
    m_arrRowLst = NULL;
}

int RemoteTableModel::rowCount(const QModelIndex &parent) const
{
    if (m_vertHeaderLst.size() > 0)
        return m_vertHeaderLst.size();

    if (NULL == m_arrRowLst) {
        return 0;
    } else {
        return m_arrRowLst->size();
    }
}

int RemoteTableModel::columnCount(const QModelIndex &parent) const
{
    if (m_horiHeaderLst.size() > 0)
        return m_horiHeaderLst.size();

    if (NULL == m_arrRowLst) {
        return 0;
    } else if (m_arrRowLst->size() < 1) {
        return 0;
    } else {
        return m_arrRowLst->first().size();
    }
}

QVariant RemoteTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (NULL == m_arrRowLst)
        return QVariant();
    if (m_arrRowLst->size() < 1)
        return QVariant();

    if (role == Qt::TextAlignmentRole) {
        return int(Qt::AlignLeft | Qt::AlignVCenter);
    } else if (role == Qt::DisplayRole) {
        if (index.row() >= m_arrRowLst->size())
            return QVariant();
        if (index.column() >= m_arrRowLst->first().size())
            return QVariant();
        return m_arrRowLst->at(index.row()).at(index.column());
    }
    return QVariant();
}
#if 0
bool RemoteTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

}
#endif
QVariant RemoteTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {//Horizontal Table Header
            if (m_horiHeaderLst.size() > section) {
                return m_horiHeaderLst[section];
            } else {
                return QVariant();
            }
        } else {
            if (m_vertHeaderLst.size() > section) {
                return m_vertHeaderLst[section];
            } else {
                return QVariant();
            }
        }
    }
    return QVariant();
}

Qt::ItemFlags RemoteTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    Qt::ItemFlags flag = QAbstractItemModel::flags(index);

    return flag;
}

void RemoteTableModel::setHoriHeaderList(const QStringList &horiHeaderLst)
{
    m_horiHeaderLst = horiHeaderLst;
}

void RemoteTableModel::setVertHeaderList(const QStringList &VertHeaderLst)
{
    m_vertHeaderLst = VertHeaderLst;
}

void RemoteTableModel::setModelDatas(QList<QStringList> *rowlist)
{
    m_arrRowLst = rowlist;
}

void RemoteTableModel::refresh()
{
    if (!m_arrRowLst->isEmpty()) {
        beginResetModel();
        endResetModel();
    }

    emit updateCount(rowCount(QModelIndex()));
}
