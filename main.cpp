#include "kalk.h"
#include <QApplication>

#include "vettoregenerico.h"
#include "colore.h"
#include "colorergb.h"
#include "librettoesami.h"
#include "ingrediente.h"
#include "ricetta.h"

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
    VettoreGenerico<int>* v3 = new VettoreGenerico<int>();

    LibrettoEsami le("nome","cognome",12345,180), *le2, le3;
    le2 = new LibrettoEsami("nome","cognome",12345,180);
    le.aggiungiElemento(Esame());
    le.aggiungiElemento(Esame(12,31,"Analisi","Informatica", "Sartori"));
    le3.aggiungiElemento(Esame(1,18,"a","b","c"));
    //le2->aggiungiElemento(Esame());
    //le2->aggiungiElemento(Esame(12,31,"Analisi","Informatica", "Sartori"));
    //le2->aggiungiElemento(Esame(1,18,"a","b","c"));
    //le = *(le + *le2);
    //le = *(le3 + le);
    //le = *(le + le3);
    le += le3;
    //cout << le << endl;
    //le = *(le - le3);
    le -= le3;
    le = *(Esame() + le);
    //le = *(Esame() - le);
    //cout << le << endl;
    //cout << le.mediaPonderata() << endl;
    //cout << le.previsioneVotoLaurea() << endl;
    const char* s ;

    v.aggiungiElemento(1);
    v.aggiungiElemento(2);
    v.aggiungiElemento(3);
    v1.aggiungiElemento(4);
    v1.aggiungiElemento(5);
    v1.aggiungiElemento(6);
    s=std::to_string(v[0]).c_str();
    v3=(v + v1);
    v=*(v - v1);
    l->setText(s);

    //main per pardeep da qua a sotto


    //main per me da qua a sotto
    Colore* myColor = new ColoreRgb(255,5,0);
    ColoreRgb myColor2(251,251  ,16);
    double HSL[3]{344,56,12};

    /*uttilizzo delle operazioni della classe
    myColor2= *( myColor2 + *myColor);
    myColor2= *( myColor2 - *myColor);
    myColor2= *( myColor2 * *myColor);
    l->setText(std::to_string(myColor2.DeltaE(*myColor)).c_str());
     myColor2.rgb2hsl(HSL);
     string str= "hsl("+to_string(HSL[0])+","+to_string(HSL[1])+","+to_string(HSL[2])+")";
*/

    int RGB[3];
    Colore::hsl2rgb(HSL,RGB);
    myColor2.setR(RGB[0]);
    myColor2.setG(RGB[1]);
    myColor2.setB(RGB[2]);
    string str= "rgb("+to_string(RGB[0])+","+to_string(RGB[1])+","+to_string(RGB[2])+")\n";
     str+= myColor2.rgb2hex();


/*
    l->setText(str.c_str());
    myColor2 =*(myColor2.complementare());

   myColor2= *myColor2.luminositaColore();
     l->setText(myColor2.schemaColore().c_str());
*/
    Ricetta* r= new Ricetta();
    r->setNomeRicetta("Ricetta di test");
    Ingrediente i("ciao",51,20,40.5), j("ciao",50,20,40.5);
    r->aggiungiElemento(i);
    r->aggiungiElemento(j);
    Ricetta r1;
    r1.aggiungiElemento(j);

    //r=*r-r1;
  /*  if(*r == r1){
        l->setText("Uguali");
    }else
        l->setText("Diversi");
*/
   // *r= *r * 2;
    l->setText(to_string(r->costoRicetta()).c_str());

   // l->setText(r->getRicetta().c_str());


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

