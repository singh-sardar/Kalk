#include "matricigui.h"

MatriciGUI::MatriciGUI(QWidget *parent): QWidget(parent), controllerMatrici(new MatriciController(this))
{
    gridLayout = new QGridLayout;
    verticalLayout = new QVBoxLayout;
    verticalLayoutMatriceRisultato = new QVBoxLayout;
    tableWidget1 = new TableViewMatrice(this,"Matrice 1");
    tableWidget2 = new TableViewMatrice(this,"Matrice 2");
    controlliWidget1 = new ElementiSingolaMatrice;
    controlliWidget2 = new ElementiSingolaMatrice;
    btnSomma = new QPushButton("+");
    btnDifferenza = new QPushButton("-");
    btnMoltiplicazione = new QPushButton("*");


    QFont f("Verdana",12);
    f.setBold(false);
    labelMatriceRisultato = new QLabel(tr("Matrice Risultato"));
    labelMatriceRisultato->setFont(f);
    labelRisultato = new QLabel(tr("Ultimo risultato: "));
    labelRisultato->setFont(f);

    tableWidgetRisultato = new QTableWidget(1,1);
    tableWidgetRisultato->setGeometry(0,0,350,350);
    //tableWidgetRisultato->setMinimumSize(350,350);
    tableWidgetRisultato->setShowGrid(true);
    tableWidgetRisultato->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidgetRisultato->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidgetRisultato->resizeColumnsToContents();

    verticalLayout->addWidget(btnSomma);
    verticalLayout->addWidget(btnDifferenza);
    verticalLayout->addWidget(btnMoltiplicazione);
    verticalLayoutMatriceRisultato->addWidget(labelMatriceRisultato);
    verticalLayoutMatriceRisultato->addWidget(tableWidgetRisultato);
    gridLayout->addWidget(tableWidget1,0,0);
    gridLayout->addLayout(verticalLayout,0,1);
    gridLayout->addWidget(tableWidget2,0,2);
    gridLayout->addLayout(verticalLayoutMatriceRisultato,0,3);
    gridLayout->addWidget(controlliWidget1,1,0);
    gridLayout->addWidget(controlliWidget2,1,2);
    gridLayout->addWidget(labelRisultato,2,0,1,3,Qt::AlignCenter);

    setLayout(gridLayout);

    connect(btnSomma,SIGNAL(clicked(bool)),this,SIGNAL(btnSommaClicked(bool)));
    connect(btnDifferenza,SIGNAL(clicked(bool)),this,SIGNAL(btnDifferenzaClicked(bool)));
    connect(btnMoltiplicazione,SIGNAL(clicked(bool)),this,SIGNAL(btnMoltiplicazioneClicked(bool)));

    connect(controlliWidget1,SIGNAL(btnDeterminanteClicked(bool)),this,SIGNAL(btnDeterminanteClicked1(bool)));
    connect(controlliWidget1,SIGNAL(btnDivisioneScalareClicked(bool)),this,SIGNAL(btnDivisioneScalareClicked1(bool)));
    connect(controlliWidget1,SIGNAL(btnElevaAPotenzaClicked(bool)),this,SIGNAL(btnElevaAPotenzaClicked1(bool)));
    connect(controlliWidget1,SIGNAL(btnIsDiagonaleClicked(bool)),this,SIGNAL(btnIsDiagonaleClicked1(bool)));
    connect(controlliWidget1,SIGNAL(btnIsScalareClicked(bool)),this,SIGNAL(btnIsScalareClicked1(bool)));
    connect(controlliWidget1,SIGNAL(btnIsSimmetricaClicked(bool)),this,SIGNAL(btnIsSimmetricaClicked1(bool)));
    connect(controlliWidget1,SIGNAL(btnMatriceCofattoriClicked(bool)),this,SIGNAL(btnMatriceCofattoriClicked1(bool)));
    connect(controlliWidget1,SIGNAL(btnMatriceInversaClicked(bool)),this,SIGNAL(btnMatriceInversaClicked1(bool)));
    connect(controlliWidget1,SIGNAL(btnMatriceTraspostaClicked(bool)),this,SIGNAL(btnMatriceTraspostaClicked1(bool)));
    connect(controlliWidget1,SIGNAL(btnMoltiplicazioneScalareClicked(bool)),this, SIGNAL(btnMoltiplicazioneScalareClicked1(bool)));

    connect(controlliWidget2,SIGNAL(btnDeterminanteClicked(bool)),this,SIGNAL(btnDeterminanteClicked2(bool)));
    connect(controlliWidget2,SIGNAL(btnDivisioneScalareClicked(bool)),this,SIGNAL(btnDivisioneScalareClicked2(bool)));
    connect(controlliWidget2,SIGNAL(btnElevaAPotenzaClicked(bool)),this,SIGNAL(btnElevaAPotenzaClicked2(bool)));
    connect(controlliWidget2,SIGNAL(btnIsDiagonaleClicked(bool)),this,SIGNAL(btnIsDiagonaleClicked2(bool)));
    connect(controlliWidget2,SIGNAL(btnIsScalareClicked(bool)),this,SIGNAL(btnIsScalareClicked2(bool)));
    connect(controlliWidget2,SIGNAL(btnIsSimmetricaClicked(bool)),this,SIGNAL(btnIsSimmetricaClicked2(bool)));
    connect(controlliWidget2,SIGNAL(btnMatriceCofattoriClicked(bool)),this,SIGNAL(btnMatriceCofattoriClicked2(bool)));
    connect(controlliWidget2,SIGNAL(btnMatriceInversaClicked(bool)),this,SIGNAL(btnMatriceInversaClicked2(bool)));
    connect(controlliWidget2,SIGNAL(btnMatriceTraspostaClicked(bool)),this,SIGNAL(btnMatriceTraspostaClicked2(bool)));
    connect(controlliWidget2,SIGNAL(btnMoltiplicazioneScalareClicked(bool)),this, SIGNAL(btnMoltiplicazioneScalareClicked2(bool)));
}

QLabel* MatriciGUI::getLabelRisultato() const{
    return labelRisultato;
}

QLineEdit* MatriciGUI::getLineEditMatrice1() const{
    return controlliWidget1->getLineEditNumerici();
}

QLineEdit* MatriciGUI::getLineEditMatrice2() const{
    return controlliWidget2->getLineEditNumerici();
}

QTableWidget* MatriciGUI::getTableWidget1() const{
    return tableWidget1->getTableWidget();
}

QTableWidget* MatriciGUI::getTableWidget2() const{
    return tableWidget2->getTableWidget();
}

QTableWidget* MatriciGUI::getTableWidgetRisultato() const{
    return tableWidgetRisultato;
}

MatriciGUI::~MatriciGUI(){
     delete tableWidget1;
     delete tableWidget2;
     delete tableWidgetRisultato;
     delete controlliWidget1;
     delete controlliWidget2;
     delete btnSomma;
     delete btnDifferenza;
     delete btnMoltiplicazione;
     delete gridLayout;
     delete controllerMatrici;
     /*if(verticalLayout){
        delete verticalLayout;
     }
     if(verticalLayoutMatriceRisultato){
        delete verticalLayoutMatriceRisultato;
     }*/
     delete labelRisultato;
     delete labelMatriceRisultato;
}
