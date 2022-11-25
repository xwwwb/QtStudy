#include "main.h"
#include <QCoreApplication>
int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  Animal ani("xwwwb", 18);
  std::cout << ani << std::endl;
  Animal ani2("xwwwwwb", 20);
  Animal ani3 = ani + ani2;
  std::cout << ani3 << std::endl;
  cout << Animal::animalCount() << endl;
  cout << Animal::cnt2 << endl;
  return 0;
}
