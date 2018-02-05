#include <QApplication>
#include <QDesktopWidget>
#include <QPushButton>
#include <QButtonGroup>
#include <QLayout>
#include <QFile>
#include <QProcess>
#include <QDebug>
#include <QSignalMapper>
#include <QStackedWidget>

#include "basewidget.h"
#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent), baseWidget(new BaseWidget())
{
    setAttribute(Qt::WA_AlwaysShowToolTips);
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::Tool);
    ws=windowState();
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QList<QString> iconFN = {":/icons/dolmade.png",":/icons/recipe.png",":/icons/ingredient.png",":/icons/tools.png",":/icons/help.png",":/icons/preferences.png"};
    QList<QString> iconTT = {"Dolmades","Recipes","Ingredients","Tools","Help","Preferences"};
    QList<QString>::iterator iconFNit = iconFN.begin();
    QList<QString>::iterator iconTTit = iconTT.begin();

    QButtonGroup *bg = new QButtonGroup(this);
    bg->setExclusive(true);

    for (int bid=0; bid<iconFN.size();bid++) {
        QPushButton *b = new QPushButton(this);
        b->setIcon(QIcon(*iconFNit));
        b->setIconSize(QSize(32,32));
        b->setToolTip(*iconTTit);
        b->setCheckable(true);
        b->setChecked((bid == 0));
        b->setStyleSheet(QString(
            "QPushButton:hover:!pressed:!checked{border: 2px solid gray; background: yellow;}"
            "QPushButton:hover:!pressed:checked{border: 2px solid gray; background: red;}"
        ));
        b->setFlat(true);
        bg->addButton(b,bid);
        mainLayout->addWidget(b);
        iconFNit++;
        iconTTit++;
    }
    connect(bg, SIGNAL(buttonClicked(int)), baseWidget, SLOT(setWidget(int)));
    connect(QApplication::desktop(), SIGNAL(workAreaResized(int)), this, SLOT(fixPosition()));
    fixPosition();
}

void MainWidget::fixPosition()
{
    QRect r = QApplication::desktop()->screenGeometry();
    const int w = 60;
    const int h = 200;
    int x = r.width() - w;
    int y = (r.height() - h)/2;
    resize(w,h);
    move(x,y);
}

void MainWidget::onToggle(QSystemTrayIcon::ActivationReason r)
{
    // workaround bug which puts window in minimized state
    // when active workspace being switched
    setWindowState(Qt::WindowNoState);
    baseWidget->setWindowState(Qt::WindowNoState);
    if (r==QSystemTrayIcon::Trigger) {
        if (isVisible()) {
            hide();
            baseWidget->hide();
        } else {
            show();
            baseWidget->show();
        }
    }
}
/*
void MainWidget::showEvent(QShowEvent *e) {
    QWidget::showEvent(e);
    baseWidget->show();
}
*/
MainWidget::~MainWidget()
{
}
