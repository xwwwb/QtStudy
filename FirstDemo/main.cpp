#include "widget.h"

#include <QApplication>

//整行移动代码 command + shift + ⬆️ + ⬇️
//代码格式化 command + i
//alt+enter 快速操作
//修改变量名 并应用到所有 放到变量名上 command+shift+r
//书签功能
//      Command+M 添加标签
//      Command+. 跳转到
// macos下触发系统快捷键 以上不能用

int nothing(){
    int pig =2;
    pig =3;
    pig ++;
    return 0;
}

int main(int argc, char *argv[])
{
    // QApplication类是应用程序类
    // a是对象 应用程序对象有且只有一个
    // 必须把main的参数传给a对象
    QApplication a(argc, argv);

    // 窗口类 Qt提供了一个Qwidget类
    Widget w;
//    w.setWindowTitle("xwwwb的QT项目");
    // 显示窗口
    w.show();

    // a.exec() 应用程序消息循环 相当于while
    return a.exec();
}
