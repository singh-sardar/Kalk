#include "librettoesamigui.h"

LibrettoEsamiGUI::LibrettoEsamiGUI(QWidget *parent): QWidget(parent){

    esameDialog = new EsameDialog;
    esameDialog->setModal(true);
    QFont f("Verdana",12);
    QFont f2("Verdana",14);
    f2.setBold(false);

    viewLibretto1 = new SingoloLibrettoEsamiView;
    viewLibretto2 = new SingoloLibrettoEsamiView;

    lineEditNomeStudente1 = new QLineEdit("Nome studente");
    lineEditCognomeStudente1 = new QLineEdit("Cognome studente");
    lineEditMatricolaStudente1 = new QLineEdit("Matricola studente");
    lineEditNomeStudente2 = new QLineEdit("Nome studente");
    lineEditCognomeStudente2 = new QLineEdit("Cognome studente");
    lineEditMatricolaStudente2 = new QLineEdit("Matricola studente");

    vLayout1 = new QVBoxLayout;
    vLayout2 = new QVBoxLayout;
    gL1 = new QGridLayout;
    gL2 = new QGridLayout;

    spinBoxTargetCFU1 = new QSpinBox;
    spinBoxTargetCFU2 = new QSpinBox;
    spinBoxTargetCFU1->setRange(1,1000);
    spinBoxTargetCFU1->setSuffix(" Target CFU");
    spinBoxTargetCFU2->setRange(1,1000);
    spinBoxTargetCFU2->setSuffix(" Target CFU");
    spinBoxTargetCFU1->setAlignment(Qt::AlignRight);
    spinBoxTargetCFU2->setAlignment(Qt::AlignRight);

    btnAggiungiLibretto1AdLibretto2 = new QPushButton("Aggiungi libretto 1\n a libretto 2");
    btnAggiungiLibretto2AdLibretto1 = new QPushButton("Aggiungi libretto 2\n a libretto 1");
    btnRimuoviLibretto1DaLibretto2 = new QPushButton("Rimuovi libretto 1\n da libretto 2");
    btnRimuoviLibretto2DaLibretto1 = new QPushButton("Rimuovi libretto 2\n da libretto 1");

    labelLibretto1 = new QLabel("Libretto 1");
    labelLibretto1->setFont(f2);
    labelLibretto2 = new QLabel("Libretto 2");
    labelLibretto2->setFont(f2);
    vLayout1->addWidget(labelLibretto1,0,Qt::AlignCenter);
    vLayout2->addWidget(labelLibretto2,0,Qt::AlignCenter);
    gL1->addWidget(lineEditNomeStudente1,0,0);
    gL1->addWidget(lineEditCognomeStudente1,0,1);
    gL1->addWidget(lineEditMatricolaStudente1,1,0);
    gL1->addWidget(spinBoxTargetCFU1,1,1);
    vLayout1->addLayout(gL1);
    vLayout1->addWidget(viewLibretto1);
    gL2->addWidget(lineEditNomeStudente2,0,0);
    gL2->addWidget(lineEditCognomeStudente2,0,1);
    gL2->addWidget(lineEditMatricolaStudente2,1,0);
    gL2->addWidget(spinBoxTargetCFU2,1,1);
    vLayout2->addLayout(gL2);
    vLayout2->addWidget(viewLibretto2);

    setFont(f);

    gridLayout = new QGridLayout;
    vLayout = new QVBoxLayout;
    vLayout->addWidget(btnAggiungiLibretto1AdLibretto2);
    vLayout->addWidget(btnAggiungiLibretto2AdLibretto1);
    vLayout->addWidget(btnRimuoviLibretto1DaLibretto2);
    vLayout->addWidget(btnRimuoviLibretto2DaLibretto1);

    gridLayout->addLayout(vLayout1,0,0);
    gridLayout->addLayout(vLayout,0,1);
    gridLayout->addLayout(vLayout2,0,2);

    setLayout(gridLayout);

    connect(viewLibretto1,SIGNAL(btnAggiungiEsameClicked()),this,SLOT(apriEsameDialog()));
    connect(viewLibretto1,SIGNAL(btnRimuoviEsameClicked()),this,SLOT(apriEsameDialog()));
    connect(viewLibretto2,SIGNAL(btnAggiungiEsameClicked()),this,SLOT(apriEsameDialog()));
    connect(viewLibretto2,SIGNAL(btnRimuoviEsameClicked()),this,SLOT(apriEsameDialog()));

    connect(viewLibretto1,SIGNAL(btnAggiungiEsameClicked()),this,SIGNAL(btnAggiungiEsameClicked1()));
    connect(viewLibretto1,SIGNAL(btnRimuoviEsameClicked()),this,SIGNAL(btnRimuoviEsameClicked1()));
    connect(viewLibretto1,SIGNAL(btnEsameMenoRecenteClicked()),this,SIGNAL(btnEsameMenoRecenteClicked1()));
    connect(viewLibretto1,SIGNAL(btnEsameMiglioreClicked()),this,SIGNAL(btnEsameMiglioreClicked1()));
    connect(viewLibretto1,SIGNAL(btnEsamePeggioreClicked()),this,SIGNAL(btnEsamePeggioreClicked1()));
    connect(viewLibretto1,SIGNAL(btnEsamePiuRecenteClicked()),this,SIGNAL(btnEsamePiuRecenteClicked1()));

    connect(viewLibretto2,SIGNAL(btnAggiungiEsameClicked()),this,SIGNAL(btnAggiungiEsameClicked2()));
    connect(viewLibretto2,SIGNAL(btnRimuoviEsameClicked()),this,SIGNAL(btnRimuoviEsameClicked2()));
    connect(viewLibretto2,SIGNAL(btnEsameMenoRecenteClicked()),this,SIGNAL(btnEsameMenoRecenteClicked2()));
    connect(viewLibretto2,SIGNAL(btnEsameMiglioreClicked()),this,SIGNAL(btnEsameMiglioreClicked2()));
    connect(viewLibretto2,SIGNAL(btnEsamePeggioreClicked()),this,SIGNAL(btnEsamePeggioreClicked2()));
    connect(viewLibretto2,SIGNAL(btnEsamePiuRecenteClicked()),this,SIGNAL(btnEsamePiuRecenteClicked2()));

    connect(btnAggiungiLibretto1AdLibretto2,SIGNAL(clicked(bool)),this,SIGNAL(btnAggiungiLibretto1AdLibretto2Clicked()));
    connect(btnAggiungiLibretto2AdLibretto1,SIGNAL(clicked(bool)),this,SIGNAL(btnAggiungiLibretto2AdLibretto1Clicked()));
    connect(btnRimuoviLibretto1DaLibretto2,SIGNAL(clicked(bool)),this,SIGNAL(btnRimuoviLibretto1DaLibretto2Clicked()));
    connect(btnRimuoviLibretto2DaLibretto1,SIGNAL(clicked(bool)),this,SIGNAL(btnRimuoviLibretto2DaLibretto1Clicked()));

    connect(viewLibretto1,SIGNAL(btnCFURimanentiClicked()),this,SIGNAL(btnCFURimanentiClicked1()));
    connect(viewLibretto1,SIGNAL(btnTargetCFUClicked()),this,SIGNAL(btnTargetCFUClicked1()));
    connect(viewLibretto1,SIGNAL(btnTotalCFUClicked()),this,SIGNAL(btnTotalCFUClicked1()));
    connect(viewLibretto1,SIGNAL(btnMediaAritmeticaClicked()),this,SIGNAL(btnMediaAritmeticaClicked1()));
    connect(viewLibretto1,SIGNAL(btnMediaPonderataClicked()),this,SIGNAL(btnMediaPonderataClicked1()));
    connect(viewLibretto1,SIGNAL(btnPercentualeCompletamentoClicked()),this,SIGNAL(btnPercentualeCompletamentoClicked1()));
    connect(viewLibretto1,SIGNAL(btnPrevisioneVotoClicked()),this,SIGNAL(btnPrevisioneVotoClicked1()));
    connect(viewLibretto1,SIGNAL(btnNumEsamiSostenutiClicked()),this,SIGNAL(btnNumEsamiSostenutiClicked1()));

    connect(viewLibretto2,SIGNAL(btnCFURimanentiClicked()),this,SIGNAL(btnCFURimanentiClicked2()));
    connect(viewLibretto2,SIGNAL(btnTargetCFUClicked()),this,SIGNAL(btnTargetCFUClicked2()));
    connect(viewLibretto2,SIGNAL(btnTotalCFUClicked()),this,SIGNAL(btnTotalCFUClicked2()));
    connect(viewLibretto2,SIGNAL(btnMediaAritmeticaClicked()),this,SIGNAL(btnMediaAritmeticaClicked2()));
    connect(viewLibretto2,SIGNAL(btnMediaPonderataClicked()),this,SIGNAL(btnMediaPonderataClicked2()));
    connect(viewLibretto2,SIGNAL(btnPercentualeCompletamentoClicked()),this,SIGNAL(btnPercentualeCompletamentoClicked2()));
    connect(viewLibretto2,SIGNAL(btnPrevisioneVotoClicked()),this,SIGNAL(btnPrevisioneVotoClicked2()));
    connect(viewLibretto2,SIGNAL(btnNumEsamiSostenutiClicked()),this,SIGNAL(btnNumEsamiSostenutiClicked2()));

    connect(lineEditNomeStudente1,SIGNAL(textChanged(QString)),this,SIGNAL(nomeStudente1Changed()));
    connect(lineEditNomeStudente2,SIGNAL(textChanged(QString)),this,SIGNAL(nomeStudente2Changed()));
    connect(lineEditCognomeStudente1,SIGNAL(textChanged(QString)),this,SIGNAL(cognomeStudente1Changed()));
    connect(lineEditCognomeStudente2,SIGNAL(textChanged(QString)),this,SIGNAL(cognomeStudente2Changed()));
    connect(lineEditMatricolaStudente1,SIGNAL(textChanged(QString)),this,SIGNAL(matricolaStudente1Changed()));
    connect(lineEditMatricolaStudente2,SIGNAL(textChanged(QString)),this,SIGNAL(matricolaStudente2Changed()));
    connect(spinBoxTargetCFU1,SIGNAL(valueChanged(int)),this,SIGNAL(targetCFU1Changed()));
    connect(spinBoxTargetCFU2,SIGNAL(valueChanged(int)),this,SIGNAL(targetCFU2Changed()));

    librettoController = new LibrettoEsamiController(this);
}

void LibrettoEsamiGUI::apriEsameDialog(){
    esameDialog->exec();
}

EsameDialog* LibrettoEsamiGUI::getEsameDialog() const{
    return esameDialog;
}

SingoloLibrettoEsamiView* LibrettoEsamiGUI::getLibretto1Viewer() const{
    return viewLibretto1;
}

SingoloLibrettoEsamiView* LibrettoEsamiGUI::getLibretto2Viewer() const{
    return viewLibretto2;
}

QString LibrettoEsamiGUI::getNomeStudente1() const{
    return lineEditNomeStudente1->text();
}

QString LibrettoEsamiGUI::getNomeStudente2() const{
    return lineEditNomeStudente2->text();
}

QString LibrettoEsamiGUI::getCognomeStudente1() const{
    return lineEditCognomeStudente1->text();
}

QString LibrettoEsamiGUI::getCognomeStudente2() const{
    return lineEditCognomeStudente2->text();
}

QString LibrettoEsamiGUI::getMatricolaStudente1() const{
    return lineEditMatricolaStudente1->text();
}

QString LibrettoEsamiGUI::getMatricolaStudente2() const{
    return lineEditMatricolaStudente2->text();
}

int LibrettoEsamiGUI::getTargetCFU1() const{
    return spinBoxTargetCFU1->value();
}

int LibrettoEsamiGUI::getTargetCFU2() const{
    return spinBoxTargetCFU2->value();
}

LibrettoEsamiGUI::~LibrettoEsamiGUI(){
    delete viewLibretto1;
    delete viewLibretto2;

    delete btnAggiungiLibretto1AdLibretto2;
    delete btnAggiungiLibretto2AdLibretto1;
    delete btnRimuoviLibretto1DaLibretto2;
    delete btnRimuoviLibretto2DaLibretto1;

    delete esameDialog;

    delete lineEditNomeStudente1;
    delete lineEditCognomeStudente1;
    delete lineEditMatricolaStudente1;
    delete lineEditNomeStudente2;
    delete lineEditCognomeStudente2;
    delete lineEditMatricolaStudente2;
    delete spinBoxTargetCFU1;
    delete spinBoxTargetCFU2;

    delete labelLibretto1;
    delete labelLibretto2;
    delete gL1;
    delete gL2;
    delete vLayout1;
    delete vLayout2;
    delete vLayout;
    delete gridLayout;

    delete librettoController;
}
