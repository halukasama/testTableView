#include "delegates.h"
#include <QApplication>
ProgressDelegate::ProgressDelegate(QObject *parent)
{

}

ProgressDelegate::~ProgressDelegate()
{

}

void ProgressDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    {
        if(index.column() == 2)
        {

            int progress = index.model ()->data(index, Qt::DisplayRole).toInt ();
            QStyleOptionProgressBarV2 progressBarOption;
            progressBarOption.state = QStyle:: State_Enabled;
            progressBarOption.direction = QApplication::layoutDirection();
            progressBarOption.rect = option.rect;
            progressBarOption.fontMetrics = QApplication::fontMetrics();
            progressBarOption.minimum = 0;
            progressBarOption.maximum = 100;
            progressBarOption.textAlignment = Qt:: AlignCenter;
            progressBarOption.textVisible = true;
            progressBarOption.progress = progress;
            progressBarOption.text = QString("%1%").arg(progressBarOption.progress);
            QApplication::style()->drawControl(QStyle::CE_ProgressBar, &progressBarOption, painter);
        } else {
            return QItemDelegate::paint (painter, option, index);
        }
    }
}


