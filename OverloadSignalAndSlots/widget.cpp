//
// Created by xwwwb on 2022/11/28.
//
#include "widget.h"
#include "MyPushButton.h"
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent) {
    // 构造函数
    this->setWindowTitle("信号与槽的重载");
    btn = new MyPushButton();
    btn->setParent(this);
    btn->setText("Touch Me");

    MyPushButton *btn2= new MyPushButton();
    btn2->setParent(this);
    btn2->setText("lambda表达式范例");
    btn2->move(200,200);
    // 这里要用按值捕获 不能用引用捕获非成员变量
    // 因为btn2定义在构造函数里，btn2这个指针会释放
    connect(btn2,&QPushButton::clicked,this,[=](){
        btn2->setText("我会变化");
    });

    // connect(btn, &QPushButton::clicked, this, &Widget::onClicked); // 点击按钮驱使MyPushButton发送信号
    // 把上面的改成lambda表达式
    connect(btn,&QPushButton::clicked,this,[this](){
        emit this->btn->clicked_();
        emit this->btn->clicked_("嗨嗨嗨");
    });
    // 二义性 因为MyPushButton的clicked_()信号有两个重载函数
    // connect(btn,&MyPushButton::clicked_,this,&Widget::onMyClicked); // MyPushButton发送信号驱使Widget接收信号
    // 1. 通过函数指针解决
    //    void (MyPushButton::*fclicked_noarg)() = &MyPushButton::clicked_;
    //    void (Widget::*fonMyclicked_noarg)() = &Widget::onMyClicked;
    //    void (MyPushButton::*fclicked_arg)(const QString&) = &MyPushButton::clicked_;
    //    void (Widget::*fonMyclicked_arg)(const QString&) = &Widget::onMyClicked;
    //    connect(btn,fclicked_noarg,this,fonMyclicked_noarg);
    //    connect(btn,fclicked_arg,this,fonMyclicked_arg);

    // 2. 通过Qt的一个方法解决重载 文档查询QOverload 推荐使用
    connect(btn, QOverload<>::of(&MyPushButton::clicked_), this, QOverload<>::of(&Widget::onMyClicked));
    connect(btn, QOverload<const QString &>::of(&MyPushButton::clicked_), this,
            QOverload<const QString &>::of(&Widget::onMyClicked));

    // 3. Qt4的方法 不推荐使用 宏是强行转换 不会进行错误检查
    //    connect(btn, SIGNAL(clicked_()),this, SLOT(onMyClicked()));
    //    connect(btn, SIGNAL(clicked_(const QString &) ),this, SLOT(onMyClicked(const QString &)));
}

Widget::~Widget() = default;

void Widget::onClicked() {
    emit btn->clicked_();
    emit btn->clicked_("嗨嗨嗨");
}

void Widget::onMyClicked() {
    qDebug() << "onMyClicked";
}

void Widget::onMyClicked(const QString &text) {
    qDebug() << text;
}