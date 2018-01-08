#ifndef MATRICICONTROLLER_H
#define MATRICICONTROLLER_H


#include "matrice.h"
#include <QWidget>
#include <QTableWidget>
#include "tableviewmatrice.h"
#include "matricigui.h"

class MatriciGUI;
class MatriciController: public QObject{
    Q_OBJECT

public:
    MatriciController(MatriciGUI*);
    ~MatriciController();

private:
    MatriciGUI* viewMatrici;
    Matrice* matrice1, *matrice2, *matriceRisultato;
    void aggiornaLabelRisultato(QString);
    void showMessageBox(QString, QString) const;

private slots:
    void aggiornaMatrice1();
    void aggiornaMatrice2();
    void aggiornaTableViewRisultato();

    //Operazioni su due matrici
    void somma();
    void sottrazione();
    void moltiplicazione();

    // Operazioni sulla prima matrice
    void determinante1();
    void matriceInversa1();
    void matriceCofattori1();
    void matriceTrasposta1();
    void moltiplicazioneScalare1();
    void divisioneScalare1();
    void elevaAPotenza1();
    void isSimmetrica1();
    void isDiagonale1();
    void isScalare1();

    //operazioni sulla seconda matrice
    void determinante2();
    void matriceInversa2();
    void matriceCofattori2();
    void matriceTrasposta2();
    void moltiplicazioneScalare2();
    void divisioneScalare2();
    void elevaAPotenza2();
    void isSimmetrica2();
    void isDiagonale2();
    void isScalare2();
};

#endif // MATRICICONTROLLER_H
