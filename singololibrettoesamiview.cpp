#include "singololibrettoesamiview.h"

SingoloLibrettoEsamiView::SingoloLibrettoEsamiView(QWidget *parent):
    QWidget(parent)
{
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

QPlainTextEdit* SingoloLibrettoEsamiView::getPlainTextEdit() const{return plainText;}

SingoloLibrettoEsamiView::~SingoloLibrettoEsamiView(){
    delete plainText;
    delete btnAggiungiEsame;
    delete btnRimuoviEsame;
    delete btnEsameMigliore;
    delete btnEsamePiuRecente;
    delete btnEsamePeggiore;
    delete btnEsameMenoRecente;
    delete btnTargetCFU;
    delete btnTotalCFU;
    delete btnMediaAritmetica;
    delete btnMediaPonderata;
    delete btnPercentualeCompletamento;
    delete btnPrevisioneVoto;
    delete btnCFURimanenti;
    delete btnNumEsamiSostenuti;
    delete gridLayout;
}
