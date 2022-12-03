#include "mywidget.h"
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QWhatsThis>
MyWidget::MyWidget(QWidget *parent) : QWidget(parent) {
  setSize();
  //  setWindowFlag(Qt::WindowType::FramelessWindowHint);
  setIcon();
  widgetSignal();
  widgetSlots();
  setCursorShape();
  setTip();
  setFlags();
}

MyWidget::~MyWidget() {}

void MyWidget::setSize() {
  // 设置窗口大小 大小可调
  //  resize(1024, 960);

  // 设置固定大小 大小不可调
  //  setFixedSize(640, 480);

  // 设置最大最小尺寸
  setMinimumSize(320, 320);
  setMaximumSize(800, 600);

  // 获取窗口尺寸
  qDebug() << size();

  // 获取窗口矩形
  qDebug() << rect();

  qDebug() << geometry();

  qDebug() << frameGeometry();

  qDebug() << normalGeometry();

  qDebug() << pos();
  // 以上值在构造函数执行后可能结果不同
  QPushButton *btn = new QPushButton("点我查看位置相关");
  btn->move(200, 100);
  btn->setParent(this);

  connect(btn, &QPushButton::clicked, this, [=]() {
    qDebug() << "构造函数执行后的结果";
    // 获取窗口矩形
    qDebug() << rect();

    qDebug() << geometry();

    qDebug() << frameGeometry();

    qDebug() << normalGeometry();

    qDebug() << pos();
  });
}

void MyWidget::setIcon() { setWindowIcon(QIcon("://images/snowBall.png")); }

void MyWidget::widgetSignal() {
  connect(this, &MyWidget::windowTitleChanged, this, [](const QString &text) {
    qDebug() << "修改后的标题： " << text;
  }); // 链接槽和信号

  // 创建一个按钮保证可以触发信号
  QPushButton *btn2 = new QPushButton("点我改变标题");
  btn2->setParent(this);
  btn2->move(200, 200);
  connect(btn2, &QPushButton::clicked, this,
          [this]() { this->setWindowTitle("新的标题"); });
}

void MyWidget::widgetSlots() {
  // QWidget提供的默认槽函数
  QPushButton *btn = new QPushButton("点我关闭窗口");
  btn->setParent(this);
  btn->move(200, 300);
  // 这里要注意了 这个close只是会把窗口隐藏 实际上widget对象还在
  // 但是如果这个窗口是最后一个窗口 那么close会删掉这个窗口
  connect(btn, &QPushButton::clicked, this, &MyWidget::close);

  // 验证一下上面的说法
  // 新建一个窗口
  QWidget *testWidget = new QWidget();
  testWidget->show();
  // QObject有个信号是destroy
  QPushButton *btn2 = new QPushButton("点我关闭第二个窗口");
  btn2->setParent(this);
  btn2->move(200, 400);
  connect(btn2, &QPushButton::clicked, testWidget, &QWidget::close);

  QPushButton *btn3 = new QPushButton("再打开第二个窗口");
  btn3->setParent(this);
  btn3->move(400, 400);
  connect(btn3, &QPushButton::clicked, testWidget, &QWidget::show);

  connect(testWidget, &QObject::destroyed, this,
          []() { qDebug() << "testWidget销毁了"; });
  // 在给默认窗口连接destroy
  connect(this, &QObject::destroyed, this,
          []() { qDebug() << "默认窗口销毁了"; });
}

void MyWidget::setCursorShape() {
  // 设置鼠标样式
  setCursor(QCursor(QPixmap(":/ /images/cursor_two.png")));

  // 这种场景很适合使用static
  static int cursorEnum = 0;
  QPushButton *btn_cursor = new QPushButton("点我切换鼠标样式");
  btn_cursor->setParent(this);
  btn_cursor->move(400, 100);
  connect(btn_cursor, &QPushButton::clicked, this, [=]() {
    setCursor(QCursor(Qt::CursorShape(cursorEnum)));
    cursorEnum = (cursorEnum + 1) % 24;

    // 这里可以用QCursor的静态函数获取鼠标的全局坐标
    qDebug() << QCursor::pos();
    // 并且设置坐标
    // 申请辅助功能权限
    QCursor::setPos(200, 200);
  });
}

void MyWidget::setTip() {
  QPushButton *btn = new QPushButton("鼠标移上来看提示");
  btn->setParent(this);
  btn->move(400, 200);
  btn->setToolTip("这里有提示");
  // 这里的Mac不知道怎么预览
  btn->setWhatsThis("这是长提示");

  // 按下按钮后就可以进入长提示按钮
  // 可是申请屏幕录制很迷
  connect(btn, &QPushButton::clicked, this,
          []() { QWhatsThis::enterWhatsThisMode(); });
}

void MyWidget::setFlags() {
  // 设置窗口标志
  qDebug() << windowFlags();
  // mac不能用
  setWindowFlag(Qt::WindowType::WindowCloseButtonHint, false);
  // Windows下使用这个会进入
  // WhatsThisMode
  setWindowFlag(Qt::WindowType::WindowContextHelpButtonHint, true);

  // setWindowsFlags可以设置多个
  //  setWindowFlags(Qt::WindowType::WindowMinMaxButtonsHint |
  //                 Qt::WindowContextHelpButtonHint);
  // 上面的写法不是+= 而是= 要用下面的写法
  setWindowFlags(windowFlags() | Qt::WindowType::WindowMinMaxButtonsHint |
                 Qt::WindowContextHelpButtonHint);

  // 分不清这俩
  qDebug() << "Qt::WindowStates()" << Qt::WindowStates();
  qDebug() << "this->windowState()" << this->windowState();

  // 设置windows状态
  static int num = 0;
  QPushButton *btn = new QPushButton("点我切换窗口状态");
  btn->setParent(this);
  btn->move(400, 300);
  QLabel *stateDesc = new QLabel("点击切换状态按钮查看结果");
  stateDesc->setParent(this);
  stateDesc->move(600, 300);

  connect(btn, &QPushButton::clicked, this, [=]() {
    setWindowState(Qt::WindowState(num));
    num = (num + 1) % 5;
    stateDesc->setText(QString::number(num));
    qDebug() << this->windowState(); // 这里结果不变化 不理解
  });

  QPushButton *btn_2 = new QPushButton("用异或运算符实现窗口控制");
  btn_2->setParent(this);
  btn_2->move(200, 500);

  QWidget *w = new QWidget();
  w->setWindowTitle("用于被控制状态");
  w->show();

  connect(btn_2, &QPushButton::clicked, w, [=]() {
    w->setWindowState(w->windowState() ^ Qt::WindowState::WindowMinimized);
  });

  /*
   *    0 0000
   *    1 0001
   *  ^ ------
   *    1 0001
   *
   *    1 0001
   *    1 0001
   *  ^ ------
   *    0 0000
   *
   */

  // 为了恢复和激活最小化窗口 同时保持其最大化和全屏状态 使用以下方法 一脸懵逼
  w->setWindowState((w->windowState() & ~Qt::WindowMinimized) |
                    Qt::WindowActive);

  w->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);
  connect(w, &QObject::destroyed, this, []() {
    qDebug() << "这个窗口关闭的时候会销毁，而别的窗口只有在全部窗口都关闭的时候"
                "才会销毁 因为设置了窗口属性";
  });

  this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
  this->setAttribute(Qt::WA_TranslucentBackground); // 设置透明窗口
}
