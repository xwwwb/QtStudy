#include "main.h"

/*
 * 记录一些Qt基础类
 */

void QByteArrayStudy() {
  qDebug("以下是log的学习");
  qDebug() << "Hello" << 22.22 << 98 << 5.20;
  QString word = "Debug!!!";
  qDebug() << word;
  qInfo() << word;
  qWarning() << word;
  qCritical() << word;
  cout << "奇技淫巧 使用cout替换qDebug";
  // qFatal()<<word; // 不可用<<输出 用C风格输出 会导致直接中断程序

  qDebug("\n以下是QByteArray的基础使用");
  QByteArray arr;
  // noquote是qDebug()下的
  cout.noquote() << arr << "-";
  QByteArray arr1("Hello World", -1);
  QByteArray arr2("Hello World", 6);
  QByteArray arr3(10, 'h');
  cout.noquote() << arr1;
  cout.noquote() << arr2;
  cout.noquote() << arr3;
  cout.noquote() << QByteArray("你");

  qDebug("\n以下是字符串的操作");
  QByteArray str("I love C++!", -1);
  qDebug().noquote() << "原字符串" << str;
  qDebug().noquote() << "appand" << str.append("\nAnd JavaScript");
  qDebug().noquote() << "prepend\n" << str.prepend("I am xwwwb\n");
  qDebug().noquote() << "insert" << str.insert(18, "C/");
  qDebug().noquote() << "remove" << str.remove(24, 20);
  str.chop(10);
  qDebug().noquote() << "chop 从末尾移除" << str;
  str.truncate(5);
  qDebug().noquote() << "truncate从传入位置处截断 只保留前部分" << str;
  str.clear();
  qDebug().noquote() << "clear清空到null" << str;
  qDebug().noquote() << "chop truncate clear无返回值";

  qDebug("\n以下是字符串查找");
  str = "I love C++!";
  qDebug() << "contains" << str.contains("C++");
  qDebug() << "startsWith" << str.startsWith('I');
  qDebug() << "endsWith" << str.endsWith("!");
  qDebug() << "replace 替换" << str.replace("C++", "JavaScript");
  qint8 b;

  qDebug("\n迭代器");
  qDebug() << str.at(2);
  qDebug() << str[2];
  qDebug() << "for循环";
  for (char c : str) {
    qDebug() << c;
  }

  qDebug("\n返回字符个数");
  qDebug() << str.count() << str.length() << str.size();

  qDebug() << str << str.count('a');

  int num = 22;
  QByteArray numToString;
  numToString.setNum(num);
  qDebug() << numToString;
  numToString.setNum(52.220);
  qDebug() << numToString;
  numToString.setNum(52.220, 'E');
  qDebug() << numToString;
  //    return a.exec();
  numToString.number(123456);
  qDebug() << numToString;
  qDebug() << numToString.number(123456);
  // 既然是静态成员函数
  // 应该这样
  qDebug() << QByteArray::number(123321);

  qDebug() << "以下测试字符串转数字";
  QByteArray QByteArrayToInt = "100000000";
  qDebug() << QByteArrayToInt.toInt();
  bool isOK;
  qDebug() << QByteArrayToInt.toShort(&isOK);
  qDebug() << "传入的第一个参数是一个布尔引用 用于保存是否转换成功 "
              "这里大数字转 short失败了"
           << isOK;
}

void QVariantStudy() {
  QVariant v(2);
  QVariant v1("Hello");
  QVariant v2(QByteArray("hello"));
  qDebug() << v << v1 << v2;
  qDebug() << v.toInt();
  qDebug().noquote() << v1.toString();
  qDebug() << v.value<int>();
  qDebug() << v1.typeName();
  qDebug() << v1.type();
  qDebug() << v1.canConvert<int>();

  // 对于自定义类型 需要用宏先注册一下
  QVariant al;
  al.setValue<Animal>(Animal(88));
  auto t = al.value<Animal>();
  qDebug() << t.age;
}

void QPointStudy() {
  QPoint pos(50, 20);
  qDebug() << pos;
  pos.x();
  pos.y();
  // 下面两个返回引用 可修改 上面返回临时变量 不可修改
  pos.rx() = 111;
  pos.ry() = 222;
  qDebug() << pos;
  // 使用setX setY 也可以修改
  pos.setX(123);
  pos.setY(456);
  qDebug() << pos;

  // pos QPoint(123,456)
  QPoint pos_2(23, 16);
  // 曼哈顿距离 100 440
  qDebug() << (pos - pos_2).manhattanLength();
  qDebug() << QPoint::dotProduct(pos, pos_2);
}

void QLineStudy() {
  QLine line1 = QLine(QPoint(1, 2), QPoint(2, 3));

  qDebug() << line1.p1();
  // dx dx 是分量
  qDebug() << line1.dx();

  line1.translate(3, 4);
  qDebug() << line1.p1();
  line1.translate(QPoint(2, 4));
  qDebug() << line1.p1();
  qDebug() << "使用translated会返回偏移后的值"
           << line1.translated(QPoint(2, 3));
  qDebug() << "使用translated不会改变原值" << line1.p1();
}

void QSizeStudy() {
  QSize size(640, 480);
  qDebug() << "boundedTo 返回最小的" << size.boundedTo(QSize(500, 500));
  qDebug() << "expandedTo 返回最大的" << size.expandedTo(QSize(500, 500));

  // 缩放
  QSize s(100, 40);
  qDebug() << s.scaled(10, 10, Qt::AspectRatioMode::IgnoreAspectRatio);
  qDebug() << s.scaled(10, 10, Qt::AspectRatioMode::KeepAspectRatio);
  qDebug() << s.scaled(10, 10, Qt::AspectRatioMode::KeepAspectRatioByExpanding);
}

void QRectStudy() {
  // 草有点懵逼这个
  QRect rect(QPoint(0, 0), QPoint(10, 20));
  qDebug() << rect;
  qDebug() << rect.center();
  qDebug() << rect.left();
  rect.adjust(10, 10, 20, 50);
  qDebug() << rect;
}
