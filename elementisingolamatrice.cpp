#include "elementisingolamatrice.h"

ElementiSingolaMatrice::ElementiSingolaMatrice(QWidget *parent):
    QWidget(parent)
{
    btnDeterminante = new QPushButton(tr("Determinante"));
    btnMatriceCofattori = new QPushButton(tr("Matrice cofattori"));
    btnMatriceInversa = new QPushButton(tr("Matrice inversa"));
    btnMatriceTrasposta = new QPushButton(tr("Matrice trasposta"));
    btnMoltiplicazioneScalare = new QPushButton(tr("Moltipl. Scalare"));
    btnDivisioneScalare = new QPushButton(tr("Divis. scalare"));
    btnElevaAPotenza = new QPushButton(tr("Eleva"));
    btnIsDiagonale = new QPushButton(tr("Verifica Diagonale"));
    btnIsScalare = new QPushButton(tr("Verifica Scalare"));
    btnIsSimmetrica = new QPushButton(tr("Verifica simmetrica"));
    inputNumerici = new QLineEdit;
    labelInputNumerici = new QLabel("Input numerico: ");
    QFont f("Verdana",14);
    f.setBold(false);
    labelInputNumerici->setFont(f);

    btnElevaAPotenza->setEnabled(false);
    btnIsScalare->setEnabled(false);
    btnMoltiplicazioneScalare->setEnabled(false);
    btnDivisioneScalare->setEnabled(false);

    gridLayout = new QGridLayout;
    gridLayout->addWidget(btnDeterminante,0,0);
    gridLayout->addWidget(btnMatriceCofattori,0,1);
    gridLayout->addWidget(btnMatriceInversa,1,0);
    gridLayout->addWidget(btnMatriceTrasposta,1,1);
    gridLayout->addWidget(btnMoltiplicazioneScalare,2,0);
    gridLayout->addWidget(btnDivisioneScalare,2,1);
    gridLayout->addWidget(btnElevaAPotenza,3,0);
    gridLayout->addWidget(btnIsDiagonale,3,1);
    gridLayout->addWidget(btnIsScalare,4,0);
    gridLayout->addWidget(btnIsSimmetrica,4,1);
    gridLayout->addWidget(labelInputNumerici,5,0);
    gridLayout->addWidget(inputNumerici,5,1);

    setLayout(gridLayout);

    connect(btnDeterminante,SIGNAL(clicked(bool)),this,SIGNAL(btnDeterminanteClicked(bool)));
    connect(btnMatriceCofattori,SIGNAL(clicked(bool)),this,SIGNAL(btnMatriceCofattoriClicked(bool)));
    connect(btnMatriceInversa,SIGNAL(clicked(bool)),this,SIGNAL(btnMatriceInversaClicked(bool)));
    connect(btnMatriceTrasposta,SIGNAL(clicked(bool)),this,SIGNAL(btnMatriceTraspostaClicked(bool)));
    connect(btnMoltiplicazioneScalare,SIGNAL(clicked(bool)),this,SIGNAL(btnMoltiplicazioneScalareClicked(bool)));
    connect(btnDivisioneScalare,SIGNAL(clicked(bool)),this,SIGNAL(btnDivisioneScalareClicked(bool)));
    connect(btnElevaAPotenza,SIGNAL(clicked(bool)),this,SIGNAL(btnElevaAPotenzaClicked(bool)));
    connect(btnIsDiagonale,SIGNAL(clicked(bool)),this,SIGNAL(btnIsDiagonaleClicked(bool)));
    connect(btnIsScalare,SIGNAL(clicked(bool)),this,SIGNAL(btnIsScalareClicked(bool)));
    connect(btnIsSimmetrica,SIGNAL(clicked(bool)),this,SIGNAL(btnIsSimmetricaClicked(bool)));
    connect(inputNumerici,SIGNAL(textChanged(QString)),this,SLOT(inputNumericoChanged(QString)));
}

QLabel* ElementiSingolaMatrice::getLabelInputNumerici() const{
    return labelInputNumerici;
}


QLineEdit* ElementiSingolaMatrice::getLineEditNumerici() const{
    return inputNumerici;
}

void ElementiSingolaMatrice::inputNumericoChanged(QString s)
{
    if(!s.isEmpty()){
        btnIsScalare->setEnabled(true);
        btnMoltiplicazioneScalare->setEnabled(true);
        btnDivisioneScalare->setEnabled(true);
        btnElevaAPotenza->setEnabled(true);
    }else{
        btnIsScalare->setEnabled(false);
        btnMoltiplicazioneScalare->setEnabled(false);
        btnDivisioneScalare->setEnabled(false);
        btnElevaAPotenza->setEnabled(false);
    }
}

ElementiSingolaMatrice::~ElementiSingolaMatrice(){
    delete btnMatriceCofattori;
    delete btnMatriceInversa;
    delete btnMatriceTrasposta;
    delete btnDeterminante;
    delete btnElevaAPotenza;
    delete btnDivisioneScalare;
    delete btnIsSimmetrica;
    delete btnIsDiagonale;
    delete btnIsScalare;
    delete btnMoltiplicazioneScalare;
    delete gridLayout;
    delete labelInputNumerici;
    delete inputNumerici;
}
