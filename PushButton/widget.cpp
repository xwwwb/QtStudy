#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent) {
  QPushButton *btn = new QPushButton();
  //  btn->show(); // 显示控件widget
  // 如果没有设置父对象那么他将是一个独立的窗口

  // 设置父对象显示按钮
  btn->setParent(this);
  btn->setText("第一个按钮");
  // 如果同时使用.show和setParent 就会很奇怪 按钮的位置会很奇怪

  // 使用构造函数的方式设置父对象，会使窗口以子控件的大小进行调整
  // 如果把btn注释掉 就会看出来
  QPushButton *btn2 = new MyPushButton("第二个按钮", this);
  btn2->move(100, 0);

  this->resize(640, 480);
  this->setWindowTitle("大家的窗口");

  // 等程序运行时就会执行析构函数，因为btn3在栈区，执行完构造函数会立刻销毁
  MyPushButton btn3("栈区", this);

  connect(btn2, &QPushButton::clicked, this, &Widget::onClicked);
}

Widget::~Widget() {}

void Widget::onClicked() { qDebug() << "被点击了"; }
