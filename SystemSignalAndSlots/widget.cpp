#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);

  // 信号与槽 松散耦合关系，谁关心谁就去处理
  // 信号与槽可以属于不同对象，也可以属于相同对象
  // 使用QObject::connect建立信号与槽的关联
  // 这里的clicked和close都是系统定义好的 所以叫系统信号与槽
  QPushButton *btn = new QPushButton("Touch Me", this);
  this->connect(btn, &QAbstractButton::clicked, this, &Widget::close);
}

Widget::~Widget() { delete ui; }
