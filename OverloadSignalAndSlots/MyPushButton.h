//
// Created by xwwwb on 2022/11/28.
//

#ifndef OVERLOADSIGNALANDSLOTS_MYPUSHBUTTON_H
#define OVERLOADSIGNALANDSLOTS_MYPUSHBUTTON_H

#include <QPushButton>
#include <QWidget>
class MyPushButton:public QPushButton {
Q_OBJECT
public:
    MyPushButton(QWidget *parent=nullptr);
signals:
    void clicked_();
    void clicked_(const QString &);
};


#endif //OVERLOADSIGNALANDSLOTS_MYPUSHBUTTON_H
