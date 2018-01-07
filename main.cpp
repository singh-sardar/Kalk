#include "kalk.h"
#include <QApplication>

//include classi logica calcolatrice
#include "vettoregenerico.h"
#include "colore.h"
#include "colorergb.h"
#include "librettoesami.h"
#include "ingrediente.h"
#include "ricetta.h"
//#include "matricealgebrica.h"
#include "matrice.h"



//include for  gui
#include "tworgbpicker.h"
#include "coloroperationbuttons.h"
#include "rgbcolorgui.h"
#include "ricettagui.h"
#include "matricigui.h"
#include "librettoesamigui.h"
#include "tabwidgetgui.h"

//include qt
#include <QLabel>
#include <QPushButton>
#include <QColor>
#include <QPalette>
#include <string>
#include <qtabwidget.h>

using std::string;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    kalk w;
    QLabel* l= new QLabel(&w);

    /*
        VettoreGenerico<int> v,v1;
        VettoreGenerico<int>* v3 = new VettoreGenerico<int>();
    */

    LibrettoEsami le("nome","cognome",12345,180), *le2, le3;
    le2 = new LibrettoEsami("nome","cognome",12345,180);
    le.aggiungiElemento(Esame());
    le.aggiungiElemento(Esame("Analisi","Informatica", "Sartori",12,31));
    le3.aggiungiElemento(Esame("a","b","c",1,18));
    //le2->aggiungiElemento(Esame());
    //le2->aggiungiElemento(Esame("Analisi","Informatica", "Sartori",12,31));
    //le2->aggiungiElemento(Esame("a","b","c",1,18));
    //le = *(le + *le2);
    //le = *(le3 + le);
    //le = *(le + le3);
    //le += le3;
    //cout << le << endl;
    //le = *(le - le3);
    //le -= le3;
    le = *(Esame() + le);
    //le = *(Esame() - le);
    //cout << le << endl;
    //cout << le.mediaPonderata() << endl;
    //cout << le.previsioneVotoLaurea() << endl;
    //cout << le.librettoToString();
    //const char* s ;

    /*
    MatriceAlgebrica m(10), m2(10);
    m[0][0] = 20;
    m2[5][0] = 99;
    m[5][0] = 99;
    m = *(m + m2);
    for(unsigned int i=0; i < m.getSize(); ++i){


        for(int j=0; j < m[i].size(); ++j){
            //m[i][j] = 999;
        }
        vector<int> t = m[i];
        for(int j=0; j < t.size(); ++j){
            cout << t[j] << " ";
        }
        cout << endl;
    }*/

    Matrice m(3,3), m2(3,2), m3(2,2);
    Matrice* mr;
    try {
        int k = 1;
        for(unsigned int i=0; i < m.getNumRighe(); ++i){
            for(unsigned int j=0; j < m.getNumColonne(); ++j){
                m.setValore(i,j,k);
                k++;
            }
        }
        /*
        m.setValore(0,0,1);
        m.setValore(0,1,0);
        m.setValore(0,2,2);
        m.setValore(1,0,0);
        m.setValore(1,1,3);
        m.setValore(1,2,-1);
        */
        m.setValore(0,0,1);
        m.setValore(0,1,0);
        m.setValore(0,2,1);
        m.setValore(1,0,2);
        m.setValore(1,1,-1);
        m.setValore(1,2,3);
        m.setValore(2,0,1);
        m.setValore(2,1,4);
        m.setValore(2,2,2);
        m3.setValore(0,0,1);
        m3.setValore(0,1,2);
        m3.setValore(1,0,2);
        m3.setValore(1,1,3);
        m2.setValore(0,0,4);
        m2.setValore(0,1,1);
        m2.setValore(1,0,-2);
        m2.setValore(1,1,2);
        m2.setValore(2,0,0);
        m2.setValore(2,1,3);


        //cout << m2.getNumRighe();
        /*mr = (m*m2);
        if(mr){
            //m = *mr;
            for(unsigned int i=0; i < m.getNumRighe(); ++i){
                for(int j=0; j < m.getNumColonne(); ++j){
                    cout << m[i].at(j) << " ";
                }
                cout << endl;
            }
            */
            //m = *mr;
            //cout << endl << m.rappresentazioneStringa() << endl;
        /*}


        cout << endl;
        //m = *(m*2);
        //m = *(m/2);
        m = *(m.elevaAPotenza(2));
        for(unsigned int i=0; i < m.getNumRighe(); ++i){
            for(int j=0; j < m.getNumColonne(); ++j){
                //cout << m[i].at(j) << " ";
            }
            cout << endl;
        }

        cout << endl << "Num righe: " << m.getNumRighe() << " Num colonne: " << m.getNumColonne() << endl;
        cout << m.isScalare(2) << endl;
        cout << endl << m.isDiagonale() << endl;

        m3.aggiungiElemento(vector<double>({1,2}));
        m3.aggiungiElemento(vector<double>({2,3}));
        */
        /*
        cout << endl << m.rappresentazioneStringa() << endl;
        cout << endl << m2.rappresentazioneStringa() << endl;
        cout << endl << m.getNumRighe() << " colonne: " << m.getNumColonne() << endl;
        cout << endl << m2.getNumRighe() << " colonne: " << m2.getNumColonne() << endl;
        */
        //m = *(m - m2);
        //        mr = (m+m2);
        //cout << endl << mr->rapprese << endl;
        mr = m-m2;
        if(mr){
            //cout << endl << mr->rappresentazioneStringa() << endl;
        }
        /*vector<double> t = m3.getRiga(0);
        for(unsigned int i = 0; i < t.size(); ++i){
            cout << t[i] << " ";
        }
        */
        //cout << endl << m.rappresentazioneStringa() << endl;
        mr = m.matriceInversa();
        if(mr){
            //cout << endl << m.matriceInversa()->rappresentazioneStringa() << endl;
        }
        //cout << endl << m3.isSimmetrica() << endl;
    }
    catch (const std::out_of_range& e) {
        //cout << "Out of Range error.";
    }

/*
    MatriciGUI* matGUI = new MatriciGUI;
    matGUI->show();


    LibrettoEsamiGUI* lGUI = new LibrettoEsamiGUI;
    lGUI->show();
*/

    TabWidgetGUI widgetGUI;
    widgetGUI.show();

    //main per pardeep fino a qui ---------------------------------------------------------------------------------------


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

    r=*r+r1;
  /*  if(*r == r1){
        l->setText("Uguali");
    }else
        l->setText("Diversi");
*/
   // *r= *r * 2;
    //l->setText(to_string(r->costoRicetta()).c_str());

    l->setText(r->getRicetta().c_str());
/*

    TwoRgbPicker p;
    p.show();
    colorOperationButtons b;
    b.show();

*/

    /*
    RgbColorGui g;
    g.show();
    RicettaGui rgui;
    rgui.show();
    */


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
    /*
    w.show();
    */
    return a.exec();
}

