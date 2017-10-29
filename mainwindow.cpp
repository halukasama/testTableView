#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , m_countLabel(new QLabel)
    , m_addBtn(new QPushButton)
    , m_updateBtn(new QPushButton)
    , m_deleteBtn(new QPushButton)
    , m_clearBtn(new QPushButton)
    , m_timer(new QTimer)
    , m_view(new RemoteTableView)
{
    initMainWindow();

    connect(m_addBtn, SIGNAL(clicked()), this, SLOT(doAdd()));
    connect(m_deleteBtn, SIGNAL(clicked()), this, SLOT(doRemove()));
    connect(m_updateBtn, SIGNAL(clicked()), this, SLOT(doUpdate()));
    connect(m_clearBtn, SIGNAL(clicked()), this, SLOT(doClear()));

    connect(m_view, SIGNAL(updateCountSig(int)), this, SLOT(doUpdateCount(int)));

    m_timer->setInterval(1000);
    doUpdateCount(0);
}

MainWindow::~MainWindow()
{

}

void MainWindow::doAdd()
{
    int rowCnt = m_view->rowCount();
    for(int i = 0; i <= 50/*rowCnt*/; i++) {
        QStringList rowLst;
#if 0
        row_list <<  QString("file : %1").arg(row_count++)
                  << QString("%1KB").arg(i) << QString::number(0)
                  << QString("%1KB/s").arg(i) << QString("08:08:08")
                  << QString("uploading");
#endif
        rowLst << QString("file : %1").arg(rowCnt++)
               << QString("%1KB").arg(i) << QString::number(0)
               << QString("%1KB/s").arg(i) << QString("00:00:00")
               << QString("uploading");
        m_view->addRow(rowLst);
    }
}

void MainWindow::doClear()
{
    m_timer->stop();
    if (m_view != NULL)
        m_view->CleanView();
}

void MainWindow::doUpdate()
{
    m_timer->start();
}

void MainWindow::doUpdateCount(int count)
{
    m_countLabel->setText(QString("rowcnt : %1").arg(QString::number(count)));
}

void MainWindow::initMainWindow()
{
    this->resize(800,600);

    m_addBtn->setText(tr("添加"));
    m_updateBtn->setText(tr("更新"));
    m_deleteBtn->setText(tr("删除"));
    m_clearBtn->setText(tr("清除"));

    QHBoxLayout *operateLayout = new QHBoxLayout;
    operateLayout->addWidget(m_countLabel);
    operateLayout->addStretch();
    operateLayout->addWidget(m_addBtn);
    operateLayout->addWidget(m_updateBtn);
    operateLayout->addWidget(m_deleteBtn);
    operateLayout->addWidget(m_clearBtn);
    operateLayout->addStretch();
    operateLayout->addSpacing(20);
    operateLayout->setContentsMargins(2, 2, 2, 2);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(m_view);
    mainLayout->addLayout(operateLayout);
    mainLayout->setSpacing(20);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    setLayout(mainLayout);
}
