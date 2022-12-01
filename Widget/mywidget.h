#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class MyWidget : public QWidget {
  Q_OBJECT

public:
  MyWidget(QWidget *parent = nullptr);
  ~MyWidget();
  void setSize();
  void setIcon();
  void widgetSignal();
  void widgetSlots();
  void setCursorShape();
  void setTip();
  void setFlags();
};
#endif // MYWIDGET_H
