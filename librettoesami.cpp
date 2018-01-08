#include "librettoesami.h"

using std::endl;
using std::string;

/*
 * Costruttore
 */
//LibrettoEsami::LibrettoEsami(): VettoreGenerico(){}
LibrettoEsami::LibrettoEsami(string nomeS,string cognomeS, unsigned int matricolaS, unsigned int targCFU):
    nomeStudente(nomeS), cognomeStudente(cognomeS), matricolaStudente(matricolaS > 0?matricolaS:1), targetCFU(targCFU > 0?targCFU:1), totaleCFU(0)
{}

void LibrettoEsami::aggiungiElemento(const Esame& e){
    if(!cerca(e) && (targetCFU-totaleCFU) >= e.getCFU()){
        VettoreGenerico::aggiungiElemento(e);
        totaleCFU += e.getCFU();
    }
}

bool LibrettoEsami::rimuoviElemento(const Esame& e){
    if(cerca(e)){
        totaleCFU -= e.getCFU();
        return VettoreGenerico::rimuoviElemento(e);
    }
    return false;
}

//Ritorna i CFU per completare il percorso di studi
unsigned int LibrettoEsami::getTargetCFU() const{
    return targetCFU;
}

//Ritorna i CFU acquisiti tramite gli esami sostenuti
unsigned int LibrettoEsami::getTotaleCFU() const{
    return totaleCFU;
}

unsigned int LibrettoEsami::getMatricola() const{
    return matricolaStudente;
}

void LibrettoEsami::setMatricola(unsigned int m){
    matricolaStudente = (m > 0 ? m : 1);
}

string LibrettoEsami::getNomeStudente() const{
    return nomeStudente;
}

void LibrettoEsami::setNomeStudente(string n){
    nomeStudente = n;
}

string LibrettoEsami::getCognomeStudente() const{
    return cognomeStudente;
}

string LibrettoEsami::getInfoStudente() const{
    string s = "Nome: ";
    s += nomeStudente;
    s += "\nCognome: ";
    s += cognomeStudente;
    s += "\nMatricola: ";
    s += to_string(matricolaStudente);
    return s;
}

void LibrettoEsami::setCognomeStudente(string c){
    cognomeStudente = c;
}

double LibrettoEsami::percentualeCompletamento() const{
    return (totaleCFU*100)/targetCFU;
}

unsigned int LibrettoEsami::rimanentiCFU() const{
    return targetCFU-totaleCFU;
}

double LibrettoEsami::previsioneVotoLaurea() const{
    return (mediaPonderata()*110)/30;
}

double LibrettoEsami::mediaAritmetica() const{
    if(getSize() > 0){
        unsigned int i=0;
        double votoTemp=0;
        for(; i < getSize(); ++i){
            votoTemp += (this->operator[](i)).getVoto();
        }
        return votoTemp/i;
    }
    return 0;
}

double LibrettoEsami::mediaPonderata() const{
    if(getSize() > 0){
        unsigned int i=0;
        double votoTemp=0;
        for(; i < getSize(); ++i){
            votoTemp += (this->operator [](i).getVoto()) * (this->operator [](i).getCFU());
        }
        return votoTemp/getTotaleCFU();
    }
    return 0;
}

Esame* LibrettoEsami::esameMigliore() const{
    if(getSize() > 0){
        Esame esameTemp, esameMigliore=this->operator [](0);
        unsigned int pesoEsame=esameMigliore.getVoto()*esameMigliore.getCFU();
        for(unsigned int i=0; i < getSize(); ++i){
            esameTemp = this->operator [](i);
            if(esameTemp.getVoto()*esameTemp.getCFU() > pesoEsame){
                esameMigliore = esameTemp;
                pesoEsame = esameMigliore.getVoto()*esameMigliore.getCFU();
            }
        }
        return new Esame(esameMigliore);
    }
    return 0;
}

Esame* LibrettoEsami::esamePeggiore() const{
    if(getSize() > 0){
        Esame esameTemp, esamePeggiore=this->operator [](0);
        unsigned int pesoEsame=esamePeggiore.getVoto()*esamePeggiore.getCFU();
        for(unsigned int i=0; i < getSize(); ++i){
            esameTemp = this->operator [](i);
            if(esameTemp.getVoto()*esameTemp.getCFU() < pesoEsame){
                esamePeggiore = esameTemp;
                pesoEsame = esamePeggiore.getVoto()*esamePeggiore.getCFU();
            }
        }
        return new Esame(esamePeggiore);
    }
    return 0;

}

Esame* LibrettoEsami::esameMenoRecente() const{
    if(getSize() > 0){
        Esame esameTemp, esameMenoRecente= operator [](0);

        for(unsigned int i=0; i < getSize(); ++i){
            esameTemp = this->operator [](i);
            if(esameTemp.getData() < esameMenoRecente.getData())
                esameMenoRecente = esameTemp;
        }
        return new Esame(esameMenoRecente);
    }
    return 0;

}

Esame* LibrettoEsami::esamePiuRecente() const{
    if(getSize() > 0){
        Esame esameTemp, esamePiuRecente= operator [](0);

        for(unsigned int i=0; i < getSize(); ++i){
            esameTemp = this->operator [](i);
            if(esameTemp.getData() > esamePiuRecente.getData())
                esamePiuRecente = esameTemp;
        }
        return new Esame(esamePiuRecente);
    }
    return 0;
}

LibrettoEsami* LibrettoEsami::operator+(const VettoreGenerico<Esame>& v) const{
    LibrettoEsami* aux = new LibrettoEsami(*this);
    *aux += v;
    /*
    const LibrettoEsami* l = dynamic_cast<const LibrettoEsami*>(&l);
    if(l){
        for(unsigned int i = 0; i < l.getSize(); ++i){
            if(!aux->cerca(l[i]) && (totaleCFU+l[i].getCFU() <= targetCFU)){
                aux->aggiungiElemento(l[i]);
            }
        }
    }*/
    return aux;
}

LibrettoEsami& LibrettoEsami::operator +=(const VettoreGenerico<Esame>& v){
    const LibrettoEsami* l = dynamic_cast<const LibrettoEsami*>(&v);
    if(l){
        for(unsigned int i = 0; i < l->getSize(); ++i){
            if(!cerca(l->operator [](i)) && (totaleCFU+(l->operator [](i)).getCFU() <= targetCFU)){
                aggiungiElemento(l->operator [](i));
            }
        }
    }
    return *this;
}

LibrettoEsami* LibrettoEsami::operator +(const Esame& e) const{
    LibrettoEsami* aux = new LibrettoEsami(*this);
    *aux += e;
    //aux->aggiungiElemento(e);
    return aux;
}
/*
LibrettoEsami* operator+(const Esame& e, const LibrettoEsami& l){
    return l.operator +(e);
}

LibrettoEsami* operator-(const Esame& e, const LibrettoEsami& l){
    return l.operator -(e);
}
*/

LibrettoEsami& LibrettoEsami::operator +=(const Esame& e){
    aggiungiElemento(e);
    return *this;
}

LibrettoEsami* LibrettoEsami::operator -(const Esame& e) const{
    LibrettoEsami* aux = new LibrettoEsami(*this);
    *aux -= e;
    //aux->rimuoviElemento(e);
    return aux;
}

LibrettoEsami& LibrettoEsami::operator -=(const Esame& e){
    rimuoviElemento(e);
    return *this;
}

LibrettoEsami* LibrettoEsami::operator-(const VettoreGenerico<Esame>& v) const{
    LibrettoEsami* aux = new LibrettoEsami(*this);
    *aux -= v;
    /*const LibrettoEsami* l = dynamic_cast<const LibrettoEsami*>(&l);
    if(l){
        for(unsigned int i = 0; i != l.getSize(); ++i){
            aux->rimuoviElemento(l[i]);
        }
    }
    */
    return aux;
}

LibrettoEsami& LibrettoEsami::operator -=(const VettoreGenerico<Esame>& v){
    const LibrettoEsami* l = dynamic_cast<const LibrettoEsami*>(&v);
    if(l){
        for(unsigned int i = 0; i < l->getSize(); ++i){
            if(cerca(l->operator [](i))){
                rimuoviElemento(l->operator [](i));
            }
        }
    }
    return *this;
}
/*
ostream& operator <<(ostream& os, const LibrettoEsami& l){
    os << "\nMatricola studente: " << l.getMatricola() << endl;
    for(unsigned int i=0; i < l.getSize(); ++i){
         os << " - Esame numero " << i+1 << " - " << endl;
         os << l[i];
    }
    os << "\n";
    return os;
}
*/
string LibrettoEsami::getRappresentazioneStringa() const{
    string t;
    t+= "Nome: "+getNomeStudente() + "; Cognome: "+getCognomeStudente()+"; Matricola: "+to_string(getMatricola());
    for(unsigned int i=0; i < getSize(); ++i){
        t += "\n\nEsame " + to_string(i+1) + ":";
        t += (operator [](i)).getRappresentazioneStringa();
    }
    return t;
}
