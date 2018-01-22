#include <QApplication>
#include <QDesktopWidget>
#include <QPushButton>
#include <QLayout>
#include <QFile>
#include <QProcess>
#include <QDebug>

#include "mainwidget.h"
#include "dolmadewidget.h"
#include "recipewidget.h"
#include "ingredientwidget.h"
#include "toolwidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    ws=windowState();
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QList<QPushButton*> b = { new QPushButton(this), new QPushButton(this), new QPushButton(this), new QPushButton(this)};
    QList<QWidget*> w = { new DolmadeWidget(), new RecipeWidget(), new IngredientWidget(), new ToolWidget()};
    QList<QString> iconFN = {":/icons/dolmade.png",":/icons/recipe.png",":/icons/ingredient.png",":/icons/tools.png"};
    QList<QString> iconTT = {"Dolmades","Recipes","Ingredients","Tools"};
    QList<QWidget*>::iterator wit = w.begin();
    QList<QString>::iterator iconFNit = iconFN.begin();
    QList<QString>::iterator iconTTit = iconTT.begin();

    foreach (QPushButton *b, b){
        b->setIcon(QIcon(*iconFNit));
        b->setIconSize(QSize(32,32));
        b->setToolTip(*iconTTit);
        b->setCheckable(true);
        b->setAutoExclusive(true);
        b->setStyleSheet(QString(
            "QPushButton:hover:!pressed:!checked{border: 2px solid gray; background: yellow;}"
            "QPushButton:hover:!pressed:checked{border: 2px solid gray; background: red;}"
        ));
        b->setFlat(true);
        connect(b,SIGNAL(pressed()),this,SLOT(setButtonsExclusive()));
        connect(b,SIGNAL(toggled(bool)),*wit,SLOT(setVisible(bool)));
        mainLayout->addWidget(b);
        wit++;
        iconFNit++;
        iconTTit++;
    }
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
    } else {
        qDebug()<<"show";
        show();
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
