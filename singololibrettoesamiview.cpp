#include "singololibrettoesamiview.h"

SingoloLibrettoEsamiView::SingoloLibrettoEsamiView(QWidget *parent):
    QWidget(parent)
{
    /*labelTargetCFU = new QLabel("Target CFU: ");
    labelTargetCFUContent = new QLabel;
    labelTotalCFU = new QLabel("Totale CFU");
    labelTotalCFUContent = new QLabel;
    labelMediaAritmetica = new QLabel("Media aritmetica: ");
    labelMediaAritmeticaContent = new QLabel;
    labelMediaPonderata = new QLabel("Media ponderata: ");
    labelMediaPonderataContent = new QLabel;
    labelPercentualeCompletamento = new QLabel("Percentuale completamento: ");
    labelPercentualeCompletamentoContent = new QLabel;
    labelPrevisioneVoto = new QLabel("Previsione voto laurea: ");
    labelPrevisioneVotoContent = new QLabel;
    labelCFURimanenti = new QLabel("CFU rimanenti: ");
    labelCFURimanentiContent = new QLabel;
    labelEsamiSostenuti = new QLabel("Num. esami sostenuti: ");
    labelEsamiSostenutiContent = new QLabel;*/

    plainText = new QPlainTextEdit;
    plainText->setReadOnly(true);

    gridLayout = new QGridLayout;

    btnCFURimanenti = new QPushButton("CFU rimanenti");
    btnNumEsamiSostenuti = new QPushButton("Num. esami sostenuti");
    btnMediaAritmetica = new QPushButton("Media aritmetica");
    btnMediaPonderata = new QPushButton("Media ponderata");
    btnTargetCFU = new QPushButton("Target CFU");
    btnTotalCFU = new QPushButton("CFU acquisiti");
    btnPercentualeCompletamento = new QPushButton("Percentuale completamento");
    btnPrevisioneVoto = new QPushButton("Voto di laurea");

    btnEsameMenoRecente = new QPushButton("Esame meno recente");
    btnEsamePiuRecente = new QPushButton("Esame più recente");
    btnEsameMigliore = new QPushButton("Esame migliore");
    btnEsamePeggiore = new QPushButton("Esame peggiore");
    btnAggiungiEsame = new QPushButton("Aggiungi esame");
    btnRimuoviEsame = new QPushButton("Rimuovi esame");

    gridLayout->addWidget(plainText,0,0,1,2);
    gridLayout->addWidget(btnAggiungiEsame,1,0);
    gridLayout->addWidget(btnRimuoviEsame,1,1);
    gridLayout->addWidget(btnEsameMenoRecente,2,0);
    gridLayout->addWidget(btnEsamePiuRecente,2,1);
    gridLayout->addWidget(btnEsamePeggiore,3,0);
    gridLayout->addWidget(btnEsameMigliore,3,1);
    gridLayout->addWidget(btnCFURimanenti,4,0);
    gridLayout->addWidget(btnNumEsamiSostenuti,4,1);
    gridLayout->addWidget(btnMediaAritmetica,5,0);
    gridLayout->addWidget(btnMediaPonderata,5,1);
    gridLayout->addWidget(btnTargetCFU,6,0);
    gridLayout->addWidget(btnTotalCFU,6,1);
    gridLayout->addWidget(btnPercentualeCompletamento,7,0);
    gridLayout->addWidget(btnPrevisioneVoto,7,1);

    setLayout(gridLayout);

    connect(btnEsameMenoRecente,SIGNAL(clicked(bool)),this,SIGNAL(btnEsameMenoRecenteClicked()));
    connect(btnEsamePiuRecente,SIGNAL(clicked(bool)),this,SIGNAL(btnEsamePiuRecenteClicked()));
    connect(btnEsamePeggiore,SIGNAL(clicked(bool)),this,SIGNAL(btnEsamePeggioreClicked()));
    connect(btnEsameMigliore,SIGNAL(clicked(bool)),this,SIGNAL(btnEsameMiglioreClicked()));
    connect(btnAggiungiEsame,SIGNAL(clicked(bool)),this,SIGNAL(btnAggiungiEsameClicked()));
    connect(btnRimuoviEsame,SIGNAL(clicked(bool)),this,SIGNAL(btnRimuoviEsameClicked()));
    connect(btnCFURimanenti,SIGNAL(clicked(bool)),this,SIGNAL(btnCFURimanentiClicked()));
    connect(btnNumEsamiSostenuti,SIGNAL(clicked(bool)),this,SIGNAL(btnNumEsamiSostenutiClicked()));
    connect(btnMediaAritmetica,SIGNAL(clicked(bool)),this,SIGNAL(btnMediaAritmeticaClicked()));
    connect(btnMediaPonderata,SIGNAL(clicked(bool)),this,SIGNAL(btnMediaPonderataClicked()));
    connect(btnTargetCFU,SIGNAL(clicked(bool)),this,SIGNAL(btnTargetCFUClicked()));
    connect(btnTotalCFU,SIGNAL(clicked(bool)),this,SIGNAL(btnTotalCFUClicked()));
    connect(btnPercentualeCompletamento,SIGNAL(clicked(bool)),this,SIGNAL(btnPercentualeCompletamentoClicked()));
    connect(btnPrevisioneVoto,SIGNAL(clicked(bool)),this,SIGNAL(btnPrevisioneVotoClicked()));
}

/*
QLabel* SingoloLibrettoEsamiView::getLabelCFURimanenti() const{return labelCFURimanentiContent;}
QLabel* SingoloLibrettoEsamiView::getLabelTotalCFU() const{return labelTotalCFUContent;}
QLabel* SingoloLibrettoEsamiView::getLabelMediaAritmetica() const{return labelMediaAritmeticaContent;}
QLabel* SingoloLibrettoEsamiView::getLabelMediaPonderata() const{return labelMediaPonderataContent;}
QLabel* SingoloLibrettoEsamiView::getLabelPercentualeCompletamento() const{return labelPercentualeCompletamentoContent;}
QLabel* SingoloLibrettoEsamiView::getLabelPrevisioneVotoLaurea() const{return labelPrevisioneVotoContent;}
QLabel* SingoloLibrettoEsamiView::getLabelEsamiSostenuti() const{return labelEsamiSostenutiContent;}
QLabel* SingoloLibrettoEsamiView::getLabelTargetCFU() const{return labelTargetCFUContent;}
*/
QPlainTextEdit* SingoloLibrettoEsamiView::getPlainTextEdit() const{return plainText;}
