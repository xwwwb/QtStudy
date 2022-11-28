#include "widget.h"
#include <QLineEdit>
#include <QPushButton>
Widget::Widget(QWidget *parent) : QWidget(parent) {
  girl = new GirlFriend(this);
  self = new OneSelf(this);

  /*
   * 信号与槽参数匹配问题
   * 1. 信号返回值是void 参数可以任意指定
   * 2. 槽返回值也是void 参数可以任意指定
   * 3. 建立关联的信号与槽参数必须满足以下条件
   *    1. 信号的参数一般和槽函数一样
   *    2. 信号的参数可以比槽的参数个数多
   *    3. 槽函数的默认参数不能被忽略，信号必须一一传参
   */

  this->connect(girl, &GirlFriend::hungry, self, &OneSelf::onHungry);
  this->connect(girl, &GirlFriend::hungry_arg, self, &OneSelf::onHungry_arg);
  QPushButton *hunBtn = new QPushButton("我饿了");
  hunBtn->setParent(this);
  connect(hunBtn, &QPushButton::clicked, this, &Widget::onHunBtnClicked);

  //  信号也可以和信号建立联系
  //  connect(hunBtn, &QPushButton::clicked, girl, &GirlFriend::hungry);

  QLineEdit *edit = new QLineEdit();
  edit->setParent(this);
  edit->move(200, 200);
  connect(edit, &QLineEdit::textChanged, this, &Widget::ontextChanged);
}

Widget::~Widget() {}

void Widget::onHunBtnClicked() {
  // 发送信号
  // 发送信号一般会在前面加上一个宏 表示这是一个发送信号
  emit girl->hungry();
  emit girl->hungry_arg("牛排", 200);
}

GirlFriend::GirlFriend(QObject *parent) : QObject(parent) {}
OneSelf::OneSelf(QObject *parent) : QObject(parent) {}
void OneSelf::onHungry() { qDebug() << "多喝热水"; }

void OneSelf::onHungry_arg(QString name, int money) {

  qDebug() << "去吃" << name << "给你" << money << "元";
}

void Widget::ontextChanged(const QString &text) { qDebug() << text; }
