#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
  // cnt的初始化遵循C++17之前的写法
  static int cnt;
  // cnt2是C++17之后的声明写法
  inline static int cnt2;

  Animal(const string &name, int age) : age(age), name(name) {
    cnt++;
    cnt2++;
  }

  friend ostream &operator<<(ostream &, Animal &);
  Animal operator+(Animal);
  static int animalCount() { return cnt; };

private:
  int age;
  string name;
};

ostream &operator<<(ostream &out, Animal &animal) {
  out << "名字是：" << animal.name << "年龄是：" << animal.age;
  return out;
}

Animal Animal::operator+(Animal a) {
  return Animal(this->name, this->age + a.age);
}

// 静态成员变量只在类里面声明 没有内存空间
// 如果不存在其他的初始化语句，在创建第一个对象时，所有的静态数据都会被初始化为零。
int Animal::cnt;
// int Animal::cnt = 0;

#endif // MAIN_H
