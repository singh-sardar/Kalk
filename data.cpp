#include "data.h"
#include <iostream>
#include <string>
using std::string;
using std::ostream;

Data::Data(int g, int m, int a) : giorno((g >= 0 || g <= 31) ? g : 1), mese((m >= 1 || m <=12) ? m : 1), anno((a >= 1900) ? a : 1900) {
    if(!dataValida()){
        g=1;
        m=1;
        a=1900;
    }
}

int Data::Giorno() const{
    return giorno;
}

int Data::Mese() const{
    return mese;
}

int Data::Anno() const{
    return anno;
}
/*
void Data::impostaGiorno(int g=1){
    if(g >= 0 || g <= 31)
        giorno = g;
}

void Data::impostaMese(int m=1){
    if(m <= 0 || m >= 13)
        mese = m;
}

void Data::impostaAnno(int a=1900){
    if(a <= 0)
        anno = a;
}
*/
/*
void Data::impostaData(int g=1, int m=1, int a=1900){
    impostaGiorno(g);
    impostaMese(m);
    impostaAnno(a);
}
*/
bool Data::annoBisestile(int anno) const{
    if(anno >= 0)
        return ((anno % 4 == 0) && (anno % 100 != 0)) || (anno % 400 == 0);
    else
        return false;
}

bool Data::dataValida() const{
    if(giorno==31 && (mese == 2 || mese == 4 || mese ==6 || mese==9||mese==11))
        return false;
    else if(giorno == 30 && mese == 2)
        return false;
    else if(mese==2 && giorno==29 && !annoBisestile(anno))
        return false;

    return true; // Data valida
}

bool Data::operator==(const Data& d) const{
    return giorno==d.giorno && mese==d.mese && anno==d.anno;
}

bool Data::operator!=(const Data& d) const{
    return !(*this == d);
}

bool Data::operator<(const Data& d) const{
    if(anno<d.anno) return true;
    if((anno==d.anno) && (mese<d.mese)) return true;
    if((anno==d.anno) && (mese==d.mese) &&(giorno<d.giorno)) return true;
    return false;
}

bool Data::operator>(const Data& d) const{
    return !(*this < d);
}

string Data::getRappresentazioneStringa() const{
    string s;
    s = std::to_string(giorno) + "/" + std::to_string(mese) + "/" + std::to_string(anno);
    return s;
}
/*
ostream& operator<<(ostream& os, const Data& d){
    return os<<d.Giorno()<<"/"<<d.Mese()<<"/"<<d.Anno();
}
*/
