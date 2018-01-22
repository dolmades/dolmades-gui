#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QPushButton>
#include <QList>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    Qt::WindowStates ws; // needed for working around workspaces bug

public slots:
    void fixPosition();
    void toggle(QSystemTrayIcon::ActivationReason);
    void setButtonsExclusive();
};

#endif
