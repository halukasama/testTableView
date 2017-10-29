#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QTimer>

#include "remotetabelview.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    void initMainWindow();

private slots:
    void doAdd();
    void doClear();
    void doUpdate();
    void doUpdateCount(int count);

private:
    QLabel *m_countLabel;
    QPushButton *m_addBtn;
    QPushButton *m_updateBtn;
    QPushButton *m_deleteBtn;
    QPushButton *m_clearBtn;

    QTimer *m_timer;

    RemoteTableView *m_view;
}; // Main Frame

#endif // MAINWINDOW_H
