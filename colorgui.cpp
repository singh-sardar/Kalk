#include "colorgui.h"

ColorGui::ColorGui(QWidget* parent):QWidget(parent),controller(new ColorController(this))
{
    QFont f("Verdana",12);
    lbl = new QLabel("Colore risultante dalla ultima operazione");
    resultLabel = new QLabel("");
    setFont(f);


    layout= new QGridLayout;
    p = new TwoColorPicker;
    op = new colorOperationButtons;
    cb = new QComboBox;

    cb->addItem("Colore RGB");
    cb->addItem("Colore RGBA");
    cb->addItem("Colore HSL");

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

    layout->addWidget(cb,0,0,1,2);
    layout->addWidget(p,1,0,1,2);
    layout->addWidget(saveOperando1,2,0);
    layout->addWidget(saveOperando2,2,1);
    layout->addWidget(operando1,3,0);
    layout->addWidget(operando2,3,1);
    layout->addWidget(op,4,0,1,2);
    layout->addWidget(lbl,5,0,Qt::AlignCenter);
    layout->addWidget(resultLabel,5,1);
    layout->addWidget(result,6,0,1,2);
    layout->addWidget(useResultAsOperando,7,0,1,2);

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


    connect(cb,SIGNAL(currentIndexChanged(int)),this,SLOT(changeColorType(int)));
    connect(cb,SIGNAL(currentIndexChanged(int)),this,SIGNAL(colorTypeChanged()));
    connect(op,SIGNAL(btnRgb2HslClicked(bool)),this,SIGNAL(btnRgb2HslClicked(bool)));

}

void ColorGui::changeColorType(int i){
    switch (i) {
        case 0:
            p->changeColorType(new RgbPicker);
        break;
        case 1:
            p->changeColorType(new RgbaPicker);
        break;
        case 2:
            p->changeColorType(new HslPicker);
        break;
        default:
            break;
    }
}

ColorGui::~ColorGui(){
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
int ColorGui::getColor1P1value()const{return p->getColor1()->getP1value();}
int ColorGui::getColor1P2value()const{return p->getColor1()->getP2value();}
int ColorGui::getColor1P3value()const{return p->getColor1()->getP3value();}
int ColorGui::getColor2P1value()const{return p->getColor2()->getP1value();}
int ColorGui::getColor2P2value()const{return p->getColor2()->getP2value();}
int ColorGui::getColor2P3value()const{return p->getColor2()->getP3value();}
QWidget* ColorGui::getResultViewer()const{return result;}
QWidget* ColorGui::getOperand1Viewer()const{return operando1;}
QWidget* ColorGui::getOperand2Viewer()const{return operando2;}
QLabel* ColorGui::getResultLabel()const{return resultLabel;}
double ColorGui::getHValue()const{return op->getHSpin()->value();}
double ColorGui::getSValue()const{return op->getSSpin()->value();}
double ColorGui::getLValue()const{return op->getLSpin()->value();}

int ColorGui::getRValue()const{return op->getRSpin()->value();}
int ColorGui::getGValue()const{return op->getGSpin()->value();}
int ColorGui::getBValue()const{return op->getBSpin()->value();}

double ColorGui::getFattoreScalaValue()const{return op->getFattoreScalaSpin()->value();}
TwoColorPicker* ColorGui::getColorPicker()const{return p;}
colorOperationButtons* ColorGui::getOperationButtons()const{return op;}
