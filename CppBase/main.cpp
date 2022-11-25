#include "main.h"
#include <QCoreApplication>

void Constructor();
void Polymorphism();
int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);
  //  Constructor(); // 构造函数的学习
  Polymorphism();
  return 0;
}

void Constructor() {
  string notebook = "1. 默认构造函数\n"
                    "\t如果没有任何构造函数，编译器会自动提供一个，如果写了构造"
                    "函数，编译器就不会自动提供\n"
                    "2. 有参构造函数\n"
                    "\t用的最多的构造函数\n"
                    "3. 拷贝构造函数\n"
                    "\t拷贝构造函数可以访问对象的私有成员变量，因为封装只针对类"
                    "而不针对类的对象\n"
                    "4. 移动构造函数\n"
                    "\t没听懂...3.5章节的构造函数\n"
                    "5. 委托构造函数\n"
                    "\t构造函数中调用构造函数";
  cout << notebook;
  Animal ani("xwwwb", 18);
  std::cout << ani << std::endl;
  Animal ani2("xwwwwwb", 20);
  Animal ani3 = ani + ani2;
  std::cout << ani3 << std::endl;
  cout << Animal::animalCount() << endl;
  cout << Animal::cnt2 << endl;

  // 以下两种写法都是拷贝构造函数
  Animal ani4(ani2);
  Animal ani5 = ani3;
  cout << ani4 << endl;
  cout << ani5 << endl;

  // 委托构造范例
  Animal cat(2, "Cat");
  cout << cat << endl;
}
void Polymorphism() {
  Dog dog("哈士奇", 2);

  cout << dog << endl;
  dog.getName();

  Dog dog2(4, 2, "边牧");
  dog2.cry();
  cout << dog2 << endl;

  // 父类指针或引用指向子类对象
  // 虚函数重写

  Animal *dog3 = new Dog(2, 10, "柯基");
  Animal *cat = new Animal("Cat", 2);

  dog3->cry();
  show(*dog3);
  show(*cat);
  cout << endl;
  dog.limit();
  delete dog3;
  delete cat;
}
