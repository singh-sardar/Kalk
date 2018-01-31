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
    bool dataValida() const;
    bool annoBisestile(int) const;
    string getRappresentazioneStringa() const;
    bool operator==(const Data&) const;
    bool operator!=(const Data&) const;
    bool operator<(const Data&) const;
    bool operator>(const Data&) const;
};

#endif // DATA_H
