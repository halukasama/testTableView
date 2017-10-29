#ifndef REMOTETABLEMODEL_H
#define REMOTETABLEMODEL_H

#include <QWidget>
#include <QAbstractTableModel>

class RemoteTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    RemoteTableModel(QWidget *parent = 0);
    ~RemoteTableModel(void);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    //bool setData(const QModelIndex &index, const QVariant &value, int role);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;

public:
    void setHoriHeaderList(const QStringList &horiHeaderLst);
    void setVertHeaderList(const QStringList &VertHeaderLst);
    void setModelDatas(QList<QStringList> *rowlist);
    void refresh();

signals:
    void updateCount(int cnt);

private:
    QStringList m_horiHeaderLst;
    QStringList m_vertHeaderLst;
    QList<QStringList> *m_arrRowLst;
}; // Table Model for RemoteView

#endif // REMOTETABLEMODEL_H
