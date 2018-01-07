#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
using std::string;
using std::ostream;

class Data
{
private:
    int giorno;
    int mese;
    int anno;

public:
    Data(int g=1, int m=1, int a=1900);
    int Giorno() const;
    int Mese() const;
    int Anno() const;
    /*
    void impostaGiorno(int);
    void impostaMese(int);
    void impostaAnno(int);
    void impostaData(int,int,int);
    */
    bool dataValida() const;
    bool annoBisestile(int) const;
    string getRappresentazioneStringa() const;
    bool operator==(const Data&) const;
    bool operator!=(const Data&) const;
    bool operator<(const Data&) const;
    bool operator>(const Data&) const;
};

ostream& operator<<(ostream&, const Data&);

#endif // DATA_H
