#include "mainwidget.h"
#include "containercmd.h"

#include <QApplication>
#include <QSystemTrayIcon>
#include <QIcon>
#include <QMenu>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    QSystemTrayIcon *trayIcon = new QSystemTrayIcon();
    QMenu *menu = new QMenu();
    trayIcon->setIcon(QIcon(":/icons/dolmade_green.png"));
    QAction *helpAction = menu->addAction(QObject::tr("Help"));
    QAction *preferencesAction = menu->addAction(QObject::tr("Preferences"));
    QAction *exitAction = menu->addAction(QObject::tr("Quit"));
    helpAction->setIcon(QIcon::fromTheme("help-browser"));
    preferencesAction->setIcon(QIcon::fromTheme("preferences-desktop-multimedia"));
    exitAction->setIcon(QIcon::fromTheme("application-exit"));

    QObject::connect(exitAction, SIGNAL(triggered()), &a, SLOT(quit()));

    trayIcon->setContextMenu(menu);
    trayIcon->show();
    trayIcon->setToolTip(QObject::tr("Dolmades - windows apps in linux containers"));
    QObject::connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),&w,SLOT(toggle(QSystemTrayIcon::ActivationReason)));

    w.show();

    ContainerCmd containerCmd("/usr/bin/python", ":/udocker/udocker.py", &a);

    containerCmd.exec(QStringList()<<"ps");

    return a.exec();
}
