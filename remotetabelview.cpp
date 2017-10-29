#include <QHeaderView>

#include "remotetabelview.h"

RemoteTableView::RemoteTableView(QWidget *parent)
    : m_model(new RemoteTableModel)
    , m_progressDelegate(new ProgressDelegate)
{
    initRemoteTableView();
    connect(m_model, &RemoteTableModel::updateCount, this, &RemoteTableView::updateCountSig);
    initHeaderInfo();
}

RemoteTableView::~RemoteTableView()
{
    if (m_progressDelegate) {
        delete m_progressDelegate;
        m_progressDelegate = NULL;
    }

    if (m_model) {
        delete m_model;
        m_model = NULL;
    }
    m_dataGridLst.clear();
}

void RemoteTableView::addRow(const QStringList &rowList)
{
    m_dataGridLst.append(rowList);
    m_model->refresh();
}

int RemoteTableView::rowCount()
{
    return m_model->rowCount(QModelIndex());
}

void RemoteTableView::doRemove()
{
    QModelIndexList indexLst = selectedIndexes();
    int modelCnt = indexLst.count();
    if (modelCnt <= 0)
        return;

    QList<int> rows;
    for (int i = (modelCnt - 1); i >= 0; i--) {
        QModelIndex index = indexLst.at(i);
        int row = index.row();
        if (!rows.contains(row))
            rows.append(row);
    }

    if (rows.isEmpty())
        return;

    qSort(rows);

    for(int i = (rows.count() - 1); i >=0; i--) {
        m_dataGridLst.removeAt(rows.at(i));
    }

    m_model->refresh();
#if 0
    foreach (int rowIndex, rows) {
        QModelIndex index = indexLst.at(row);
        int row =
    }
#endif
}

void RemoteTableView::CleanView()
{
    m_dataGridLst.clear();
    m_model->refresh();
}

void RemoteTableView::doChangeValue()
{
    // 10
    int maxrf = 10;
    if (maxrf > rowCount())
        return;

    for(int i = 0; i < maxrf; i++) {
        QStringList fileLst = m_dataGridLst.at(i);
        int progress = rand()%100;
        QStringList rowLst;
        rowLst << fileLst.at(0) << fileLst.at(1)
               << QString::number(progress) << fileLst.at(3)
               << fileLst.at(4) << fileLst.at(5);
        m_dataGridLst.replace(i, rowLst);
    }

    m_model->refresh();
}

void RemoteTableView::initRemoteTableView()
{
    setAlternatingRowColors(true);
    //setStyleSheet("QTableView{background-color: rgb(250, 250, 115);"
    //    "alternate-background-color: rgb(141, 163, 215);}");
    setSelectionBehavior(QAbstractItemView::SelectRows);
    horizontalHeader()->setStretchLastSection(true);
    horizontalHeader()->setHighlightSections(false);
    verticalHeader()->setVisible(false);
    setShowGrid(false);
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    setSelectionMode(QAbstractItemView::ExtendedSelection);

    setModel(m_model);
    initHeaderInfo();
    m_model->setModelDatas(&m_dataGridLst);
    setItemDelegate(m_progressDelegate);
}

void RemoteTableView::initHeaderInfo()
{
    QStringList header;
    header << tr("name") << tr("size") << tr("progress") << tr("speed") << tr("left time") << tr("state");
    //header << tr("子系统名称") << tr("状态") << tr("进度") << tr("emmm") << tr("没想好") << tr("设置");
    m_model->setHoriHeaderList(header);
}
