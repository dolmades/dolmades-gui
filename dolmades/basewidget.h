#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QWidget>
#include "ui_basewidget.h"

class BaseWidget : public QWidget {
    Q_OBJECT
private:
    Ui::baseWidget *ui;
public:
    explicit BaseWidget(QWidget* = 0);
    ~BaseWidget();
public slots:
    void setWidget(int);
    void fixPosition();
};

#endif // BASEWIDGET_H
