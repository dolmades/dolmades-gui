#include "basewidget.h"

BaseWidget::BaseWidget(QWidget* parent) : QWidget(parent), ui(new Ui::baseWidget) {
    ui->setupUi(this);
    show();
}

BaseWidget::~BaseWidget() {
    delete ui;
}

void BaseWidget::setWidget(int ix) {
    ui->stackedWidget->setCurrentIndex(ix);
}
