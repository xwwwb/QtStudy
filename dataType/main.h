#ifndef MAIN_H
#define MAIN_H
#include <QCoreApplication>
#include <QDate>
#include <QDateTime>
#include <QLine>
#include <QList>
#include <QPoint>
#include <QSize>
#include <QStringList>
#include <QTime>
#include <QVariant>
#include <QtCore>
#include <iostream>
#define cout qDebug()

void QByteArrayStudy();
void QVariantStudy();
void QPointStudy();
void QLineStudy();
void QSizeStudy();
void QRectStudy();
void QDateTimeStudy();
void QListStudy();
void QStringListStudy();

class Animal {
public:
  Animal() {}
  Animal(int age) : age(age) {}
  int age;
};

Q_DECLARE_METATYPE(Animal);
#endif // MAIN_H
