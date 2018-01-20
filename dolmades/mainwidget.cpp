#include <QApplication>
#include <QDesktopWidget>
#include <QPushButton>
#include <QLayout>
#include <QDebug>

#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    ws=windowState();
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QVector<QPushButton*> b = { new QPushButton(this), new QPushButton(this), new QPushButton(this), new QPushButton(this)};
    QVector<QString> iconFN = {":/icons/dolmade.png",":/icons/recipe.png",":/icons/ingredient.png",":/icons/tools.png"};
    QVector<QString> iconTT = {"Dolmades","Recipes","Ingredients","Tools"};
    QVector<QString>::iterator iconFNit = iconFN.begin();
    QVector<QString>::iterator iconTTit = iconTT.begin();

    foreach (QPushButton *b, b){
        b->setIcon(QIcon(*iconFNit));
        b->setIconSize(QSize(32,32));
        b->setToolTip(*iconTTit);
        b->setCheckable(true);
        b->setFlat(true);
        mainLayout->addWidget(b);
        iconFNit++;
        iconTTit++;
    }

    fixPosition();
    connect(QApplication::desktop(), SIGNAL(workAreaResized(int)), this, SLOT(fixPosition()));
    setWindowOpacity(50);
}

void MainWidget::fixPosition()
{
    QRect r = QApplication::desktop()->screenGeometry();
    const int w = 40;
    const int h = 80;
    int x = r.width() - w;
    int y = (r.height() - h)/2;
    setGeometry(x, y, w, h);
}

void MainWidget::toggle(QSystemTrayIcon::ActivationReason r)
{
    // workaround bug which puts window in minimzed state
    // when active workspace being switched
    setWindowState(Qt::WindowNoState);
    if (r==QSystemTrayIcon::Trigger) {
    if (isVisible()) {
        qDebug()<<"hide";
        hide();
    } else {
        qDebug()<<"show";
        show();
    }
    qDebug()<<windowState();
    }
}

MainWidget::~MainWidget()
{
}
