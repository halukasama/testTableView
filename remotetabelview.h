#ifndef REMOTETABELVIEW_H
#define REMOTETABELVIEW_H

#include <QTableView>
#include "remotetablemodel.h"
#include "delegates.h"

class RemoteTableView : public QTableView
{
    Q_OBJECT
public:
    RemoteTableView(QWidget *parent = 0);
    ~RemoteTableView(void);

public:
    void addRow(const QStringList &rowList);
    int rowCount();
    void CleanView();
    void doRemove();
    void doChangeValue();
signals:
    void updateCountSig(int cnt);


private:
    void initRemoteTableView();
    void initHeaderInfo();

private:
    QList<QStringList> m_dataGridLst;
    RemoteTableModel *m_model;
    ProgressDelegate *m_progressDelegate;
};

#endif // REMOTETABELVIEW_H
