#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Hello");
}

Widget::~Widget()
{
}

void Widget::doSomething()
{

}

