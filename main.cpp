#include "kalk.h"
#include <QApplication>
#include "vettoregenerico.h"
#include <QLabel>
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
    l->setText("dododod");

    l->setFont(QFont("Times",20));
    l->adjustSize();
    w.show();

    return a.exec();
}
/*
v.aggiungiElemento("ciao");
v.aggiungiElemento("hei");
v.aggiungiElemento("wei");
v1.aggiungiElemento(" come va");
v1.aggiungiElemento(" stai bene");
v1.aggiungiElemento(" dove vai");
if(VettoreGenerico<int>(v)==v)
    l->setText("uguali");
*/
