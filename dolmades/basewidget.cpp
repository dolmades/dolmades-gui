#include <QDesktopWidget>
#include <QDebug>
#include <QCloseEvent>

#include "basewidget.h"

BaseWidget::BaseWidget(QWidget* parent) : QWidget(parent), ui(new Ui::baseWidget) {
    ui->setupUi(this);
    setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint);
    connect(QApplication::desktop(), SIGNAL(workAreaResized(int)), this, SLOT(fixPosition()));
    fixPosition();
    show();
}

BaseWidget::~BaseWidget() {
    delete ui;
}

void BaseWidget::setWidget(int ix) {
    ui->stackedWidget->setCurrentIndex(ix);
}

void BaseWidget::fixPosition()
{
    QRect r = QApplication::desktop()->screenGeometry();
    const int w = 500;
    const int h = 460;
    int x = r.width() - w - 85;
    int y = (r.height() - h)/2;
    resize(w,h);
    move(x,y);
}

void BaseWidget::onToggle(QSystemTrayIcon::ActivationReason r)
{
    // workaround bug which puts window in minimized state
    // when active workspace being switched
    setWindowState(Qt::WindowNoState);
    if (r==QSystemTrayIcon::Trigger) {
        if (isVisible()) {
            hide();
        } else {
            show();
        }
    }
}

void BaseWidget::closeEvent(QCloseEvent* e) {
    e->ignore();
}
