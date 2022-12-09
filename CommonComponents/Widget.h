//
// Created by 徐文博 on 2022/12/3.
//

#ifndef COMMONCOMPONENTS_WIDGET_H
#define COMMONCOMPONENTS_WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QToolButton>
#include <QLabel>
class Widget :public QWidget{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void createPushButton();
    void createToolButton();
    void createQLabel();

};


#endif //COMMONCOMPONENTS_WIDGET_H
