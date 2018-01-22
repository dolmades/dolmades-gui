#include "basewidget.h"

#include <QApplication>
#include <QDesktopWidget>

BaseWidget::BaseWidget(QWidget *parent)
{
    setWindowFlags(Qt::WindowStaysOnTopHint);
    setFixedSize(QSize(750, 400));
    setWindowTitle(this->metaObject()->className());
    QRect r = QApplication::desktop()->screenGeometry();
    int x = r.width() - width() - 80;
    int y = (r.height() - height())/2;
    move(x,y);
}
