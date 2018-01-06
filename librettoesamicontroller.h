#ifndef LIBRETTOESAMICONTROLLER_H
#define LIBRETTOESAMICONTROLLER_H

#include <QObject>
#include <QMessageBox>
#include "librettoesamigui.h"
#include "librettoesami.h"
#include "esame.h"
#include "data.h"

using std::to_string;

class LibrettoEsamiGUI;
class LibrettoEsamiController: public QWidget{

    Q_OBJECT

public:
    LibrettoEsamiController(LibrettoEsamiGUI* g);
    ~LibrettoEsamiController();

private:
    LibrettoEsamiGUI* guiLibretto;
    LibrettoEsami* libretto1, *libretto2;
    Esame* esame;
    void aggiornaLibrettoGUI(LibrettoEsami*, QPlainTextEdit*);
    void showMessageBox(QString, QString) const;

private slots:
    void aggiungiEsameLibretto1();
    void aggiungiEsameLibretto2();
    void rimuoviEsameLibretto1();
    void rimuoviEsameLibretto2();

    void aggiungiLibretto1AdLibretto2();
    void aggiungiLibretto2AdLibretto1();
    void rimuoviLibretto1DalLibretto2();
    void rimuoviLibretto2DalLibretto1();

    void esameMiglioreLibretto1();
    void esamePeggioreLibretto1();
    void esamePiuRecenteLibretto1();
    void esameMenoReceneteLibretto1();

    void esameMiglioreLibretto2();
    void esamePeggioreLibretto2();
    void esamePiuRecenteLibretto2();
    void esameMenoReceneteLibretto2();

    /*
    void aggiornaLabelLibretto1();
    void aggiornaLabelLibretto2();
    */

    void aggiornaNomeStudente1();
    void aggiornaNomeStudente2();
    void aggiornaCognomeStudente1();
    void aggiornaCognomeStudente2();
    void aggiornaMatricolaStudente1();
    void aggiornaMatricolaStudente2();
    void aggiornaTargetCFU1();
    void aggiornaTargetCFU2();

    void mostraTargetCFU1();
    void mostraTotalCFU1();
    void mostraNumEsamiFatti1();
    void mostraMediaAritmetica1();
    void mostraMediaPonderata1();
    void mostraPrevisioneVoto1();
    void mostraPercentualeCompletamento1();
    void mostraCFURimanenti1();

    void mostraTargetCFU2();
    void mostraTotalCFU2();
    void mostraNumEsamiFatti2();
    void mostraMediaAritmetica2();
    void mostraMediaPonderata2();
    void mostraPrevisioneVoto2();
    void mostraPercentualeCompletamento2();
    void mostraCFURimanenti2();
};

#endif // LIBRETTOESAMICONTROLLER_H
