#include "rgbcolorgui.h"

RgbColorGui::RgbColorGui(QWidget* parent):QWidget(parent),controller(new ColorController(this))
{
    QFont f("Verdana",12);
    QLabel* lbl = new QLabel("Colore risultante dalla ultima operazione");
    lbl->setFont(f);

    layout= new QGridLayout;
    p = new TwoRgbPicker;
    op = new colorOperationButtons;


    saveOperando1 = new QPushButton("Salva Colore 1 come Operando 1");
    saveOperando2 = new QPushButton("Salva Colore 2 come Operando 2");
    saveOperando1->setFont(f);
    saveOperando2->setFont(f);


    operando1= new QWidget;
    operando1->setMinimumSize(300,50);
    operando1->setAutoFillBackground(true);

    operando2 = new QWidget;
    operando2->setMinimumSize(300,50);
    operando2->setAutoFillBackground(true);

    result= new QWidget;
    result->setMinimumSize(600,100);
    result->setAutoFillBackground(true);




    layout->addWidget(p,0,0,1,2);
    layout->addWidget(saveOperando1,1,0);
    layout->addWidget(saveOperando2,1,1);
    layout->addWidget(operando1,2,0);
    layout->addWidget(operando2,2,1);
    layout->addWidget(op,3,0,1,2);
    layout->addWidget(lbl,4,0,1,2,Qt::AlignCenter);
    layout->addWidget(result,5,0,1,2);

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
    /*connect(btnDifferenza,SIGNAL(clicked(bool)),this,SIGNAL(btnDifferenzaClicked(bool)));
    connect(btnModulazione,SIGNAL(clicked(bool)),this,SIGNAL(btnModulazioneClicked(bool)));
    connect(btnDeltaE,SIGNAL(clicked(bool)),this,SIGNAL(btnDeltaEClicked(bool)));
    connect(btnScala,SIGNAL(clicked(bool)),this,SIGNAL(btnScalaClicked(bool)));
    connect(btnComplementare,SIGNAL(clicked(bool)),this,SIGNAL(btnComplementareClicked(bool)));
    connect(btnLuminosita,SIGNAL(clicked(bool)),this,SIGNAL(btnLuminositaClicked(bool)));
    connect(btnCaldo,SIGNAL(clicked(bool)),this,SIGNAL(btnCaldoClicked(bool)));
    connect(btnLab,SIGNAL(clicked(bool)),this,SIGNAL(btnLabClicked(bool)));
    connect(btnHsl,SIGNAL(clicked(bool)),this,SIGNAL(btnHslClicked(bool)));
    connect(btnHex,SIGNAL(clicked(bool)),this,SIGNAL(btnHexClicked(bool)));
    connect(btnHsl2Rgb,SIGNAL(clicked(bool)),this,SIGNAL(btnHsl2RgbClicked(bool)));*/




}
