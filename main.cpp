#include "kalk.h"
#include <QApplication>
#include "vettoregenerico.h"
#include <QLabel>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    kalk w;
    QLabel* l= new QLabel(&w);

    VettoreGenerico<char*> v;
    char* s ;
    v.aggiungiElemento("ciao");
    v.aggiungiElemento("hei");
    v.aggiungiElemento("wei");

     s=v.popBackElemento();
     l->setText(s);

    /*if(v.rimuoviElemento("wei")){


         l->setText("Si");
    }
    else
        l->setText("No");*/


    l->setFont(QFont("Times",20));
    l->adjustSize();
    w.show();

    return a.exec();
}
