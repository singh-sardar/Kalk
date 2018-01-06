#ifndef SINGOLOLIBRETTOESAMIVIEW_H
#define SINGOLOLIBRETTOESAMIVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

class SingoloLibrettoEsamiView: public QWidget{
    Q_OBJECT

public:
    SingoloLibrettoEsamiView(QWidget* parent=0);
    QPlainTextEdit* getPlainTextEdit() const;

private:
    /*QLabel* labelTargetCFU;
    QLabel* labelTargetCFUContent;
    QLabel* labelTotalCFU;
    QLabel* labelTotalCFUContent;
    QLabel* labelMediaAritmetica;
    QLabel* labelMediaAritmeticaContent;
    QLabel* labelMediaPonderata;
    QLabel* labelMediaPonderataContent;
    QLabel* labelPercentualeCompletamento;
    QLabel* labelPercentualeCompletamentoContent;
    QLabel* labelPrevisioneVoto;
    QLabel* labelPrevisioneVotoContent;
    QLabel* labelCFURimanenti;
    QLabel* labelCFURimanentiContent;
    QLabel* labelEsamiSostenuti;
    QLabel* labelEsamiSostenutiContent;*/
    QPlainTextEdit* plainText;

    QPushButton* btnAggiungiEsame;
    QPushButton* btnRimuoviEsame;
    QPushButton* btnEsameMigliore;
    QPushButton* btnEsamePiuRecente;
    QPushButton* btnEsamePeggiore;
    QPushButton* btnEsameMenoRecente;
    QPushButton* btnTargetCFU;
    QPushButton* btnTotalCFU;
    QPushButton* btnMediaAritmetica;
    QPushButton* btnMediaPonderata;
    QPushButton* btnPercentualeCompletamento;
    QPushButton* btnPrevisioneVoto;
    QPushButton* btnCFURimanenti;
    QPushButton* btnNumEsamiSostenuti;

    QGridLayout* gridLayout;

signals:
    void btnEsameMiglioreClicked();
    void btnEsamePiuRecenteClicked();
    void btnEsamePeggioreClicked();
    void btnEsameMenoRecenteClicked();
    void btnAggiungiEsameClicked();
    void btnRimuoviEsameClicked();
    void btnTargetCFUClicked();
    void btnTotalCFUClicked();
    void btnMediaAritmeticaClicked();
    void btnMediaPonderataClicked();
    void btnPercentualeCompletamentoClicked();
    void btnPrevisioneVotoClicked();
    void btnCFURimanentiClicked();
    void btnNumEsamiSostenutiClicked();
};

#endif // SINGOLOLIBRETTOESAMIVIEW_H
