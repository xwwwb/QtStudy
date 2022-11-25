#include "main.h"

void QDateTimeStudy() {
  QDate date = QDate::currentDate();
  qDebug() << date;
  qDebug() << date.toString("yy-yyyy-M-MM-MMM-MMMM-d-dd-ddd-dddd");
  QTime time = QTime::currentTime();
  qDebug() << time;
  qDebug() << time.toString("hh-m-s-zzz ap,AP");
  qDebug() << date.toString("yyyy/MM/dd") + time.toString(" hh:mm:ss ap zzz");
  qDebug() << QString("%1 %2")
                  .arg(date.toString("yyyy/MM/dd"))
                  .arg(time.toString("hh:mm:ss ap zzz"));
  QDateTime datatime = QDateTime::currentDateTime();
  qDebug() << datatime.toString("yyyy/MM/dd hh:mm:ss ap zzz");

  QElapsedTimer timer;
  timer.start();
  for (int i = 0; i < 10000000; i++) {
  }
  qDebug() << timer.elapsed();
}

void QListStudy() {
  QList<int> number;
  for (int i = 0; i < 20; i++) {
    number.push_back(i);
  }
  qDebug() << number;

  // 如何迭代

  // 取下标
  printf("取下标\n");
  for (int i = 0; i < number.size(); i++) {
    printf("%d ", number[i]);
  }
  printf("\n");

  // 范围for
  printf("范围for\n");
  for (int num : number) {
    printf("%d ", num);
  }
  printf("\n");

  // Qt提供了foreach
  printf("Qt foreach宏\n");
  foreach (int t, number) {
    printf("%d ", t);
  }
  printf("\n");

  // C++ 标准foreach 不能用 老师用的vs可以用
  //  for each (int t in number) {
  //    printf("%d", t);
  //  }

  // java风格迭代器
  printf("Java风格迭代器\n");
  QListIterator<int> it(number);
  while (it.hasNext()) {
    printf("%d ", it.next());
  }
  printf("\n");

  // C++ 风格迭代器
  printf("C++风格迭代器\n");
  for (QList<int>::Iterator it = number.begin(); it != number.end(); it++) {
    printf("%d ", *it);
  }

  // 支持流插入
  QList<int> list;
  list << 1 << 2 << 3 << 4;
  qDebug() << list;

  // 可以用value取值
  qDebug() << list.value(0);
  // 可以传入默认值当下标越界的时候可以访问默认值
  qDebug() << list.value(20, 99);

  // 查找 返回的下标
  qDebug() << list.indexOf(3);

  // 第二个参数代表从哪里开始找 找不到返回-1
  qDebug() << list.indexOf(3, 3);

  // 反向查找
  qDebug() << list.lastIndexOf(1);
}

void QStringListStudy() {
  QStringList list;
  list.append(QString("I love you！"));
  list.append(QString("xwwwb"));
  list << "hello world";
  qDebug() << list;

  // 查找是否包含以及忽略大小写
  qDebug() << list.contains("Xwwwb");
  qDebug() << list.contains("Xwwwb", Qt::CaseSensitivity::CaseInsensitive);

  // 查找
  QStringList filterResult = list.filter("w");
  for (QStringList::Iterator it = filterResult.begin();
       it != filterResult.end(); it++) {
    qDebug().noquote() << *it;
  }

  // join
  QString join = list.join(QString("---"));
  qDebug() << join;

  // replace
  list.replaceInStrings(QString("xwwwb"), QString("xwwwwwwb"));
  qDebug() << list;

  // sort
  list.sort(Qt::CaseSensitivity::CaseSensitive);
  qDebug() << list;
}
