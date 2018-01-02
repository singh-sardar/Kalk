#include "coloroperationbuttons.h"

colorOperationButtons::colorOperationButtons(QWidget* parent):QWidget(parent)
{

    lbl1= new QLabel("Operazioni tra 2 Operandi");
    lbl2 = new QLabel("Operazioni su Operando 1");
    QFont f("Verdana",12);
    lbl1->setFont(f);
    lbl2->setFont(f);



    fattoreScala = new QDoubleSpinBox;
    fattoreScala->setMinimum(0.1);
    fattoreScala->setFont(f);

    H = new QDoubleSpinBox;
    H->setRange(0.0,400.0);
    H->setFont(f);
    H->setSuffix(" H");

    S= new QDoubleSpinBox;
    S->setRange(0.0,100.0);
    S->setFont(f);
    S->setSuffix(" S");

    L= new QDoubleSpinBox;;
    L->setRange(0.0,100.0);
    L->setFont(f);
    L->setSuffix(" L");

    layout = new QGridLayout;
    btnSomma = new QPushButton(tr("Somma"));
    btnDifferenza =new QPushButton(tr("Differenza"));
    btnModulazione=new QPushButton(tr("Moluazione"));
    btnDeltaE =new QPushButton(tr("Delta E"));
    btnScala=new QPushButton(tr("Scala di "));
    btnComplementare=new QPushButton(tr("Complementare"));
    btnLuminosita= new QPushButton(tr("Luminosità"));
    btnCaldo= new QPushButton(tr("Colore Caldo/Freddo"));
    btnLab= new QPushButton(tr("Rappresentazione Lab"));
    btnHsl= new QPushButton(tr("Rappresentazione HSL "));
    btnHex= new QPushButton(tr("Rappresentazione HEX "));
    btnHsl2Rgb = new QPushButton(tr("HSL TO RGB"));


    btnSomma->setFont(f);
    btnDifferenza->setFont(f);
    btnModulazione->setFont(f);
    btnDeltaE->setFont(f);
    btnScala->setFont(f);
    btnComplementare->setFont(f);
    btnLuminosita->setFont(f);
    btnCaldo->setFont(f);
    btnLab->setFont(f);
    btnHsl->setFont(f);
    btnHex->setFont(f);
    btnHsl2Rgb->setFont(f);


    layout->addWidget(lbl1,0,0,1,4,Qt::AlignCenter);
    layout->addWidget(btnSomma,1,0);
    layout->addWidget(btnDifferenza,1,1);
    layout->addWidget(btnModulazione,1,2);
    layout->addWidget(btnDeltaE,1,3);
    layout->addWidget(lbl2,2,0,1,4,Qt::AlignCenter);
    layout->addWidget(btnComplementare,3,0);
    layout->addWidget(btnLuminosita,3,1,1,2);
    layout->addWidget(btnCaldo,3,3);
    layout->addWidget(btnLab,4,0);
    layout->addWidget(btnHsl,4,1,1,2);
    layout->addWidget(btnHex,4,3);
    layout->addWidget(btnScala,5,0,1,2);
    layout->addWidget(fattoreScala,5,2,1,2);
    layout->addWidget(btnHsl2Rgb,6,0,1,2);
    QHBoxLayout* l = new QHBoxLayout;
    l->addWidget(H);
    l->addWidget(S);
    l->addWidget(L);
    layout->addLayout(l,6,2,1,2);

    connect(btnSomma,SIGNAL(clicked(bool)),this,SIGNAL(btnSommaClicked(bool)));
    connect(btnDifferenza,SIGNAL(clicked(bool)),this,SIGNAL(btnDifferenzaClicked(bool)));
    connect(btnModulazione,SIGNAL(clicked(bool)),this,SIGNAL(btnModulazioneClicked(bool)));
    connect(btnDeltaE,SIGNAL(clicked(bool)),this,SIGNAL(btnDeltaEClicked(bool)));
    connect(btnScala,SIGNAL(clicked(bool)),this,SIGNAL(btnScalaClicked(bool)));
    connect(btnComplementare,SIGNAL(clicked(bool)),this,SIGNAL(btnComplementareClicked(bool)));
    connect(btnLuminosita,SIGNAL(clicked(bool)),this,SIGNAL(btnLuminositaClicked(bool)));
    connect(btnCaldo,SIGNAL(clicked(bool)),this,SIGNAL(btnCaldoClicked(bool)));
    connect(btnLab,SIGNAL(clicked(bool)),this,SIGNAL(btnLabClicked(bool)));
    connect(btnHsl,SIGNAL(clicked(bool)),this,SIGNAL(btnHslClicked(bool)));
    connect(btnHex,SIGNAL(clicked(bool)),this,SIGNAL(btnHexClicked(bool)));
    connect(btnHsl2Rgb,SIGNAL(clicked(bool)),this,SIGNAL(btnHsl2RgbClicked(bool)));

    setLayout(layout);
}
colorOperationButtons::~colorOperationButtons(){
    delete btnSomma;
    delete btnDifferenza;
    delete btnModulazione;
    delete btnDeltaE;
    delete btnScala;
    delete btnComplementare;
    delete btnLuminosita ;
    delete btnCaldo;
    delete btnLab ;
    delete btnHsl ;
    delete btnHex ;
    delete btnHsl2Rgb;
    delete layout;
    delete fattoreScala;
    delete H;
    delete S;
    delete L;
    delete lbl1;
    delete lbl2;
}
QDoubleSpinBox*  colorOperationButtons::getFattoreScalaSpin()const{return fattoreScala;}
QDoubleSpinBox* colorOperationButtons::getHSpin()const{return H;}
QDoubleSpinBox* colorOperationButtons::getSSpin()const{return S;}
QDoubleSpinBox* colorOperationButtons::getLSpin()const{return L;}
