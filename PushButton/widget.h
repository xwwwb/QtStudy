#ifndef WIDGET_H
#define WIDGET_H

#include <QDebug>
#include <QPushButton>
#include <QWidget>
class Widget : public QWidget {
  Q_OBJECT

public:
  Widget(QWidget *parent = nullptr);
  ~Widget();

public slots:
  void onClicked();
};

class MyPushButton : public QPushButton {
  using QPushButton::QPushButton;

public:
  ~MyPushButton() { qDebug() << "~MyPushButton()"; }
};

#endif // WIDGET_H
