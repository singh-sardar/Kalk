#include "rgbcolorgui.h"

RgbColorGui::RgbColorGui(QWidget* parent):QWidget(parent),controller(new ColorController(this))
{
    QFont f("Verdana",12);
     lbl = new QLabel("Colore risultante dalla ultima operazione");
    resultLabel = new QLabel("");
    setFont(f);


    layout= new QGridLayout;
    p = new TwoRgbPicker;
    op = new colorOperationButtons;


    saveOperando1 = new QPushButton("Salva Colore 1 come Operando 1");
    saveOperando2 = new QPushButton("Salva Colore 2 come Operando 2");
    useResultAsOperando= new QPushButton("Usa ultimo risultato come Operando 1");

    useResultAsOperando->setFont(f);


    operando1= new QWidget;
    operando1->setMinimumSize(300,50);
    operando1->setAutoFillBackground(true);

    operando2 = new QWidget;
    operando2->setMinimumSize(300,50);
    operando2->setAutoFillBackground(true);

    result= new QWidget;
    result->setMinimumSize(600,75);
    result->setAutoFillBackground(true);




    layout->addWidget(p,0,0,1,2);
    layout->addWidget(saveOperando1,1,0);
    layout->addWidget(saveOperando2,1,1);
    layout->addWidget(operando1,2,0);
    layout->addWidget(operando2,2,1);
    layout->addWidget(op,3,0,1,2);
    layout->addWidget(lbl,4,0,Qt::AlignCenter);
    layout->addWidget(resultLabel,4,1);
    layout->addWidget(result,5,0,1,2);
    layout->addWidget(useResultAsOperando,6,0,1,2);

    QColor* c = new QColor;
    c->setRgb(0,0,0);
    QPalette p= operando1->palette();
    p.setColor(QPalette::Window,*c);
    operando1->setPalette(p);

    c->setRgb(0,0,0);
    p.setColor(QPalette::Window,*c);
    operando2->setPalette(p);

    c->setRgb(0,0,0);
    p.setColor(QPalette::Window,*c);
    result->setPalette(p);

    setLayout(layout);





    connect(op,SIGNAL(btnSommaClicked(bool)),this,SIGNAL(btnSommaClicked(bool)));
    connect(op,SIGNAL(btnDifferenzaClicked(bool)),this,SIGNAL(btnDifferenzaClicked(bool)));
    connect(op,SIGNAL(btnModulazioneClicked(bool)),this,SIGNAL(btnModulazioneClicked(bool)));
    connect(op,SIGNAL(btnDeltaEClicked(bool)),this,SIGNAL(btnDeltaEClicked(bool)));
    connect(op,SIGNAL(btnScalaClicked(bool)),this,SIGNAL(btnScalaClicked(bool)));
    connect(op,SIGNAL(btnComplementareClicked(bool)),this,SIGNAL(btnComplementareClicked(bool)));
    connect(op,SIGNAL(btnLuminositaClicked(bool)),this,SIGNAL(btnLuminositaClicked(bool)));
    connect(op,SIGNAL(btnCaldoClicked(bool)),this,SIGNAL(btnCaldoClicked(bool)));
    connect(op,SIGNAL(btnLabClicked(bool)),this,SIGNAL(btnLabClicked(bool)));
    connect(op,SIGNAL(btnHslClicked(bool)),this,SIGNAL(btnHslClicked(bool)));
    connect(op,SIGNAL(btnHexClicked(bool)),this,SIGNAL(btnHexClicked(bool)));
    connect(op,SIGNAL(btnHsl2RgbClicked(bool)),this,SIGNAL(btnHsl2RgbClicked(bool)));

    connect(saveOperando1,SIGNAL(clicked(bool)),this,SIGNAL(btnSaveOperando1Clicked(bool)));
    connect(saveOperando2,SIGNAL(clicked(bool)),this,SIGNAL(btnSaveOperando2Clicked(bool)));
    connect(useResultAsOperando,SIGNAL(clicked(bool)),this,SIGNAL(btnUseResultAsOperandoClicked(bool)));




}

RgbColorGui::~RgbColorGui(){
    delete layout;
    delete p;
    delete op;
    delete saveOperando1;
    delete saveOperando2;
    delete useResultAsOperando;
    delete operando1;
    delete operando2 ;
    delete result;
    delete controller;
    delete resultLabel;
    delete lbl;
}
int RgbColorGui::getColor1Rvalue()const{return p->getColor1()->getRvalue();}
int RgbColorGui::getColor1Gvalue()const{return p->getColor1()->getGvalue();}
int RgbColorGui::getColor1Bvalue()const{return p->getColor1()->getBvalue();}
int RgbColorGui::getColor2Rvalue()const{return p->getColor2()->getRvalue();}
int RgbColorGui::getColor2Gvalue()const{return p->getColor2()->getGvalue();}
int RgbColorGui::getColor2Bvalue()const{return p->getColor2()->getBvalue();}
QWidget* RgbColorGui::getResultViewer()const{return result;}
QWidget* RgbColorGui::getOperand1Viewer()const{return operando1;}
QWidget* RgbColorGui::getOperand2Viewer()const{return operando2;}
QLabel* RgbColorGui::getResultLabel()const{return resultLabel;}
double RgbColorGui::getHValue()const{return op->getHSpin()->value();}
double RgbColorGui::getSValue()const{return op->getSSpin()->value();}
double RgbColorGui::getLValue()const{return op->getLSpin()->value();}
double RgbColorGui::getFattoreScalaValue()const{return op->getFattoreScalaSpin()->value();}
