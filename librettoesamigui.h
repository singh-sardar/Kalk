#ifndef LIBRETTOESAMIGUI_H
#define LIBRETTOESAMIGUI_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include "esamedialog.h"
#include "singololibrettoesamiview.h"
#include "librettoesamicontroller.h"

class LibrettoEsamiController;
class LibrettoEsamiGUI: public QWidget{
    Q_OBJECT

public:
    LibrettoEsamiGUI(QWidget* parent=0);
    EsameDialog* getEsameDialog() const;
    SingoloLibrettoEsamiView* getLibretto1Viewer() const;
    SingoloLibrettoEsamiView* getLibretto2Viewer() const;
    QString getNomeStudente1() const;
    QString getNomeStudente2() const;
    QString getCognomeStudente1() const;
    QString getCognomeStudente2() const;
    QString getMatricolaStudente1() const;
    QString getMatricolaStudente2() const;
    QString getTargetCFU1() const;
    QString getTargetCFU2() const;

    /*QLineEdit* getLineEditNome1() const;
    QLineEdit* getLineEditNome2() const;
    QLineEdit* getLineEditCognome1() const;
    QLineEdit* getLineEditCognome2() const;
    QLineEdit* getLineEditMatricola1() const;
    QLineEdit* getLineEditMatricola2() const;
    */


private:
    SingoloLibrettoEsamiView* viewLibretto1;
    SingoloLibrettoEsamiView* viewLibretto2;

    QPushButton* btnAggiungiLibretto1AdLibretto2;
    QPushButton* btnAggiungiLibretto2AdLibretto1;
    QPushButton* btnRimuoviLibretto1DaLibretto2;
    QPushButton* btnRimuoviLibretto2DaLibretto1;

    EsameDialog* esameDialog;

    QLineEdit* lineEditNomeStudente1;
    QLineEdit* lineEditCognomeStudente1;
    QLineEdit* lineEditMatricolaStudente1;
    QLineEdit* lineEditNomeStudente2;
    QLineEdit* lineEditCognomeStudente2;
    QLineEdit* lineEditMatricolaStudente2;
    QSpinBox* spinBoxTargetCFU1;
    QSpinBox* spinBoxTargetCFU2;

    QLabel* labelLibretto1;
    QLabel* labelLibretto2;

    /*QPushButton* btnAggiungiEsame1;
    QPushButton* btnRimuoviEsame1;
    QPushButton* btnEsameMigliore1;
    QPushButton* btnEsamePiuRecente1;
    QPushButton* btnEsamePeggiore1;
    QPushButton* btnEsameMenoRecente1;
    QPushButton* btnTargetCFU1;
    QPushButton* btnTotalCFU1;
    QPushButton* btnMediaAritmetica1;
    QPushButton* btnMediaPonderata1;
    QPushButton* btnPercentualeCompletamento1;
    QPushButton* btnPrevisioneVoto1;
    QPushButton* btnCFURimanenti1;
    QPushButton* btnNumEsamiSostenuti1;

    QPushButton* btnAggiungiEsame2;
    QPushButton* btnRimuoviEsame2;
    QPushButton* btnEsameMigliore2;
    QPushButton* btnEsamePiuRecente2;
    QPushButton* btnEsamePeggiore2;
    QPushButton* btnEsameMenoRecente2;
    QPushButton* btnTargetCFU2;
    QPushButton* btnTotalCFU2;
    QPushButton* btnMediaAritmetica2;
    QPushButton* btnMediaPonderata2;
    QPushButton* btnPercentualeCompletamento2;
    QPushButton* btnPrevisioneVoto2;
    QPushButton* btnCFURimanenti2;
    QPushButton* btnNumEsamiSostenuti2;
    */

    QVBoxLayout* vLayout;
    QGridLayout* gridLayout;

    LibrettoEsamiController* librettoController;

signals:
    void btnAggiungiLibretto1AdLibretto2Clicked();
    void btnAggiungiLibretto2AdLibretto1Clicked();
    void btnRimuoviLibretto1DaLibretto2Clicked();
    void btnRimuoviLibretto2DaLibretto1Clicked();

    void nomeStudente1Changed();
    void nomeStudente2Changed();
    void cognomeStudente1Changed();
    void cognomeStudente2Changed();
    void matricolaStudente1Changed();
    void matricolaStudente2Changed();
    void targetCFU1Changed();
    void targetCFU2Changed();

    void btnEsameMiglioreClicked1();
    void btnEsamePiuRecenteClicked1();
    void btnEsamePeggioreClicked1();
    void btnEsameMenoRecenteClicked1();
    void btnAggiungiEsameClicked1();
    void btnRimuoviEsameClicked1();

    void btnEsameMiglioreClicked2();
    void btnEsamePiuRecenteClicked2();
    void btnEsamePeggioreClicked2();
    void btnEsameMenoRecenteClicked2();
    void btnAggiungiEsameClicked2();
    void btnRimuoviEsameClicked2();

    void btnTargetCFUClicked1();
    void btnTotalCFUClicked1();
    void btnMediaAritmeticaClicked1();
    void btnMediaPonderataClicked1();
    void btnPercentualeCompletamentoClicked1();
    void btnPrevisioneVotoClicked1();
    void btnCFURimanentiClicked1();
    void btnNumEsamiSostenutiClicked1();

    void btnTargetCFUClicked2();
    void btnTotalCFUClicked2();
    void btnMediaAritmeticaClicked2();
    void btnMediaPonderataClicked2();
    void btnPercentualeCompletamentoClicked2();
    void btnPrevisioneVotoClicked2();
    void btnCFURimanentiClicked2();
    void btnNumEsamiSostenutiClicked2();

private slots:
    void apriEsameDialog();
};

#endif // LIBRETTOESAMIGUI_H
