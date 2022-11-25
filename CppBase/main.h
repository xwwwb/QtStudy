#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
  int age;
  // cnt的初始化遵循C++17之前的写法
  static int cnt;
  // cnt2是C++17之后的声明写法
  inline static int cnt2;

  Animal(const string &name, int age) : age(age), name(name) {
    cnt++;
    cnt2++;
  }

  Animal(int age) : age(age), name("") {
    cout << "这是一个只初始化age的构造函数" << endl;
  }
  Animal(int age, const string &name)
      : Animal(age) // 委托构造后面不能接初始化
  {
    this->name = name;
    cout << "这里是委托构造";
  }

  Animal() : age(0), name("Animal") {}

  Animal(const Animal &other) {
    this->age = other.age;
    this->name = other.name;
  }
  friend ostream &operator<<(ostream &, Animal &);
  Animal operator+(Animal);
  static int animalCount() { return cnt; };
  virtual void cry() const { cout << "I am Animal" << endl; }

  // 可以通过派生类调用这个方法拿到基类私有的name
  void getName() { cout << name << endl; }

private:
  string name;

protected:
  int protectVar;
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

class Dog : public Animal {
  // 使用父类构造函数
  using Animal::Animal;

public:
  Dog(int foot, int age, const string &name) : foot(foot), Animal(name, age) {}
  // 如果派生类在虚函数声明时使用了override描述符，那么该函数必须重载其基类中的同名函数，否则代码将无法通过编译。
  void cry() const override { cout << "汪汪~" << endl; }
  void limit() {
    // Dog身上没age 这里this->age指向了dog的基类中的age
    // protectVar也是一样
    cout << this->age << endl;
    cout << this->protectVar << endl; // 没初始化 不影响
    //  cout << this->name << endl; // 不可访问
    // 流输出调用的是父节点的函数 可以访问name
  }

private:
  int foot;
};

// 这里要给cry函数写上const限定符表示是只读函数 因为我在访问的时候
// 只读的指针只能访问只读的函数
// 如果两个cry没有const限定 这里的ani是只读的 ani就不能使用cry方法
void show(const Animal &ani) { ani.cry(); }

#endif // MAIN_H
