//
// Created by 徐文博 on 2022/12/3.
//

#include "Widget.h"
#include <QDebug>
#include <QMenu>
#include <QMovie>
Widget::Widget(QWidget *parent) : QWidget(parent) {
    setWindowTitle("学习常见控件");
    resize(640, 480);
    createPushButton();
    createToolButton();
    createQLabel();
}

void Widget::createPushButton() {
    auto *btn = new QPushButton("按钮", this);
    connect(btn, &QAbstractButton::clicked, this, [=](bool checked) {
        qDebug() << "clicked" << checked;
    });
    connect(btn, &QAbstractButton::pressed, this, [=]() {
        qDebug() << "pressed";
    });
    connect(btn, &QAbstractButton::released, this, [=]() {
        qDebug() << "released";
    });
    connect(btn, &QAbstractButton::toggled, this, [=](bool checked) {
        qDebug() << "toggled" << checked;
    });

    // 设置按钮可以选中
    btn->setCheckable(true);
    // 设置默认选中
    btn->setChecked(true);

    // 设置大小
    btn->resize(64, 64);

    // 设置按钮图标 图片路径要基于可执行文件的路径
    btn->setIcon(QIcon("../user.png"));
    // 设置图标大小
    btn->setIconSize(QSize(32, 32));

    auto *btn2 = new QPushButton("点我延时点击第一个按钮", this);
    btn2->move(100, 0);
    connect(btn2, &QAbstractButton::clicked, this, [=]() {
        qDebug() << "延时点击第一个按钮";
        // 老师的版本这里可以传时间 我这个版本 默认100ms
        btn->animateClick();
    });

    auto *btn3 = new QPushButton("点我直接点击第一个按钮", this);
    btn3->move(400, 0);
    connect(btn3, &QAbstractButton::clicked, this, [=]() {
        qDebug() << "直接点击第一个按钮";
        btn->click();
    });


    // 设置为默认按钮 在页面enter可以被点击
    // 不能用很奇怪
    auto *btn4 = new QPushButton("默认按钮，扁平按钮", this);
    btn4->move(0, 100);

    btn4->setDefault(true);

    btn4->setFlat(true);

    // 设置菜单按钮
    QMenu *menu = new QMenu();
    QAction *menu1Act = menu->addAction("菜单1");
    QAction *menu2Act = menu->addAction("菜单2");
    QAction *menu3Act = menu->addAction("菜单3 可被选择");
    menu3Act->setCheckable(true);

    connect(menu1Act, &QAction::triggered, this, [=]() {
        qDebug() << "菜单1被点击";
    });
    connect(menu2Act, &QAction::triggered, this, [=]() {
        qDebug() << "菜单2被点击";
    });
    connect(menu3Act, &QAction::toggled, this, [=](bool checked) {
        qDebug() << "菜单3" << checked;
    });


    auto *btn5 = new QPushButton("菜单按钮", this);
    btn5->move(0, 200);
    btn5->setMenu(menu);

    // menu自己的信号也可以用
    connect(menu, &QMenu::triggered, this, [=](QAction *item) {
        btn5->setText(item->text());
    });
}

void Widget::createToolButton() {
    // 默认无文字
    QToolButton *toolBtn = new QToolButton(this);
    toolBtn->move(200, 200);
// 这里的路径要填相对于运行文件的路径
    toolBtn->setIcon(QIcon("../user.png"));
    toolBtn->setMinimumSize(200, 200);
    toolBtn->setIconSize(QSize(64, 64));

    // 设置箭头
    // 覆盖掉了上面设置的图标
    toolBtn->setArrowType(Qt::RightArrow);

    // 设置toolButton样式
    toolBtn->setText("ToolButton");
    // 貌似setIconSize就失效了
    toolBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
}

void Widget::createQLabel(){
    QLabel  *label = new QLabel("Label",this);
    label->move(120 ,300);
    label->setStyleSheet("background-color:green");
    label->setAlignment(Qt::AlignCenter);

    // 设置图片标签
    QLabel *label2 = new QLabel(this);
    label2->move(120, 400);
    label2->setPixmap(QPixmap("../user.png").scaled(64,64));

    // 内容自动缩放
    QLabel *label3 = new QLabel(this);
    label3->move(500, 200);
    label3->setPixmap(QPixmap("../user.png"));
    label3->setScaledContents(true);
    label3->setFixedSize(64,64);

    // 显示GIF
    QLabel *label4 = new QLabel(this);
    label4->move(500, 300);
    label4->setScaledContents(true);
    QMovie *movie = new QMovie("../giphy.gif");
    movie->setScaledSize(QSize(64,64));
    label4->setMovie(movie);
    movie->start();

    // 超链接
    QLabel *label5 = new QLabel(this);
    label5->move(500,200);
    label5->setText("<a href=\"https://www.google.com\">点我</a>");
    connect(label5,&QLabel::linkActivated,this,[=](QString link){
        qDebug() << "超链接被点击" << link;
    });
    label5->setOpenExternalLinks(true);
}


Widget::~Widget() = default;