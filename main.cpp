#include "kalk.h"
#include <QApplication>

#include "vettoregenerico.h"
#include "colore.h"
#include "colorergb.h"

#include <QLabel>
#include <QPushButton>
#include <QColor>
#include <QPalette>
#include <string>

using std::string;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    kalk w;
    QLabel* l= new QLabel(&w);

    VettoreGenerico<int> v,v1;
    const char* s ;

    v.aggiungiElemento(1);
    v.aggiungiElemento(2);
    v.aggiungiElemento(3);
    v1.aggiungiElemento(4);
    v1.aggiungiElemento(5);
    v1.aggiungiElemento(6);
    s=std::to_string(v[0]).c_str();
    v=v+v1;
    v=v-v1;
    l->setText(s);

    //main per pardeep da qua a sotto



    //main per me da qua a sotto
    Colore* myColor = new ColoreRgb(255,255,0);
    ColoreRgb myColor2(0,255,255);
    //myColor2= *( myColor2 + *myColor);
     //myColor2= *( myColor2 - *myColor);
    myColor2= *( myColor2 * *myColor);

    QPushButton btn(&w);
    btn.setGeometry(100,100,50,50);
    QColor c(myColor2.getR(),myColor2.getG(),myColor2.getB());
    /*QPalette p;
    p.setColor(QPalette::Button,c);
    btn.setAutoFillBackground(true);
    btn.setPalette(p);
    btn.update();*/

    QString qss = QString("background-color: %1").arg(c.name());
    btn.setStyleSheet(qss);



    l->setFont(QFont("Times",20));
    l->adjustSize();
    w.show();

    return a.exec();
}

