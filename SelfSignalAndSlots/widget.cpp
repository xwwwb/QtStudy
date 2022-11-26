#include "widget.h"
#include <QPushButton>
Widget::Widget(QWidget *parent) : QWidget(parent) {
  girl = new GirlFriend(this);
  self = new OneSelf(this);

  this->connect(girl, &GirlFriend::hungry, self, &OneSelf::onHungry);

  QPushButton *hunBtn = new QPushButton("我饿了");
  hunBtn->setParent(this);
  //  connect(hunBtn, &QPushButton::clicked, this, &Widget::onHunBtnClicked);

  // 上面注释的是正常写法
  // 但是信号也可以和信号建立联系
  connect(hunBtn, &QPushButton::clicked, girl, &GirlFriend::hungry);
}

Widget::~Widget() {}

void Widget::onHunBtnClicked() {
  // 发送信号
  // 发送信号一般会在前面加上一个宏 表示这是一个发送信号
  emit girl->hungry();
}

GirlFriend::GirlFriend(QObject *parent) : QObject(parent) {}
OneSelf::OneSelf(QObject *parent) : QObject(parent) {}
void OneSelf::onHungry() { qDebug() << "多喝热水"; }
