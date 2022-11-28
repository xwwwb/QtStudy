#ifndef WIDGET_H
#define WIDGET_H

#include <QDebug>
#include <QWidget>
class GirlFriend : public QObject {
  Q_OBJECT
public:
  GirlFriend(QObject *parent = nullptr);

  // 自定义信号，要在signals下定义信号
  // 信号只是函数的声明 没有实现 也不能实现 Qt框架会在预编译的时候帮我们实现
signals:
  void hungry();
  void hungry_arg(QString name, int money);
};

class OneSelf : public QObject {
  Q_OBJECT
public:
  OneSelf(QObject *parent = nullptr);

  // 自定义槽 写在slots下 需要调用
public slots:
  void onHungry();
  void onHungry_arg(QString name, int money);
};

class Widget : public QWidget {
  Q_OBJECT

public:
  Widget(QWidget *parent = nullptr);
  ~Widget();

private:
  GirlFriend *girl;
  OneSelf *self;
public slots:
  void onHunBtnClicked();
  void ontextChanged(const QString &text);
};

#endif // WIDGET_H
