#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QWidget>
#include <QSystemTrayIcon>

namespace Ui {
class baseWidget;
}

class BaseWidget : public QWidget {
    Q_OBJECT
private:
    Ui::baseWidget *ui;
protected:
    void closeEvent(QCloseEvent *);
public:
    explicit BaseWidget(QWidget* = 0);
    ~BaseWidget();
public slots:
    void setWidget(int);
    void fixPosition();
    void onToggle(QSystemTrayIcon::ActivationReason);
};

#endif // BASEWIDGET_H
