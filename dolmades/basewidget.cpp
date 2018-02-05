#include <QDesktopWidget>
#include <QDebug>
#include "basewidget.h"

BaseWidget::BaseWidget(QWidget* parent) : QWidget(parent), ui(new Ui::baseWidget) {
    ui->setupUi(this);
    setWindowFlags(Qt::Tool);
    connect(QApplication::desktop(), SIGNAL(workAreaResized(int)), this, SLOT(fixPosition()));
    fixPosition();
}

BaseWidget::~BaseWidget() {
    delete ui;
}

void BaseWidget::setWidget(int ix) {
    ui->stackedWidget->setCurrentIndex(ix);
    show();
}

void BaseWidget::fixPosition()
{
    QRect r = QApplication::desktop()->screenGeometry();
    const int w = 500;
    const int h = 460;
    int x = r.width() - w - 70;
    int y = (r.height() - h)/2;
    setGeometry(x, y, w, h);
    qDebug() << x;
    qDebug() << y;
}
