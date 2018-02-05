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
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    ws=windowState();
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QList<QPushButton*> b = { new QPushButton(this), new QPushButton(this), new QPushButton(this), new QPushButton(this)};
    QList<QString> iconFN = {":/icons/dolmade.png",":/icons/recipe.png",":/icons/ingredient.png",":/icons/tools.png"};
    QList<QString> iconTT = {"Dolmades","Recipes","Ingredients","Tools"};
    QList<QString>::iterator iconFNit = iconFN.begin();
    QList<QString>::iterator iconTTit = iconTT.begin();

    QButtonGroup *bg = new QButtonGroup(this);
    int bid = 0;
    bg->setExclusive(true);
    foreach (QPushButton *b, b){
        b->setIcon(QIcon(*iconFNit));
        b->setIconSize(QSize(32,32));
        b->setToolTip(*iconTTit);
        b->setCheckable(true);
        //b->setAutoExclusive(true);
        b->setStyleSheet(QString(
            "QPushButton:hover:!pressed:!checked{border: 2px solid gray; background: yellow;}"
            "QPushButton:hover:!pressed:checked{border: 2px solid gray; background: red;}"
        ));
        b->setFlat(true);
        bg->addButton(b,bid);
        connect(b,SIGNAL(toggled(bool)),baseWidget,SLOT(setVisible(bool)));
        connect(b,SIGNAL(pressed()),this,SLOT(setButtonsExclusive()));
        mainLayout->addWidget(b);
        iconFNit++;
        iconTTit++;
        bid++;
    }
    connect(bg, SIGNAL(buttonClicked(int)), baseWidget, SLOT(setWidget(int)));
    fixPosition();
    connect(QApplication::desktop(), SIGNAL(workAreaResized(int)), this, SLOT(fixPosition()));
}

void MainWidget::fixPosition()
{
    QRect r = QApplication::desktop()->screenGeometry();
    const int w = 60;
    const int h = 160;
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
        baseWidget->hide();
    } else {
        qDebug()<<"show";
        show();
        // TODO show only if one button is toggled
    }
    qDebug()<<windowState();
    }
}

void MainWidget::setButtonsExclusive()
{
    QAbstractButton* button = static_cast<QAbstractButton*>(sender());
    button->setAutoExclusive(!button->isChecked());
}

MainWidget::~MainWidget()
{
}
