#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QSystemTrayIcon>
#include <QPushButton>
#include <QList>

#include "basewidget.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    Qt::WindowStates ws; // needed for working around workspaces bug
    BaseWidget* baseWidget;

public slots:
    void fixPosition();
    void onToggle(QSystemTrayIcon::ActivationReason);
    //void showEvent(QShowEvent *);
};

#endif
