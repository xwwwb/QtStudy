#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT  //要使用信号与槽机制 必须包含宏

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void doSomething();
};
#endif // WIDGET_H
