//
// Created by xwwwb on 2022/11/28.
//

#ifndef OVERLOADSIGNALANDSLOTS_WIDGET_H
#define OVERLOADSIGNALANDSLOTS_WIDGET_H

#include <QWidget>
class MyPushButton;
class Widget :public QWidget{
    Q_OBJECT
public:
    Widget(QWidget *parent=nullptr);
    ~Widget();
public slots:
    void onClicked();
    void onMyClicked();
    void onMyClicked(const QString&);

private:
    MyPushButton *btn;
};

#endif //OVERLOADSIGNALANDSLOTS_WIDGET_H
