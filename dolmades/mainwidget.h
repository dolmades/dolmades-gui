#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QSystemTrayIcon>

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
};

#endif // MAINWINDOW_H
