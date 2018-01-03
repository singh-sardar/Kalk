#include "ricettagui.h"

RicettaGui::RicettaGui(QWidget* parent ):QWidget(parent)
{

    ingDialog = new IngredienteDialog;
     ingDialog->setModal(true);
    QFont f("Verdana",12);
    layout = new QGridLayout;
    ricetta1 = new QPlainTextEdit;
    ricetta1->setReadOnly(true);
    ricetta2 = new QPlainTextEdit;
    ricetta2->setReadOnly(true);
    ricettaResult = new QPlainTextEdit;
    ricettaResult->setReadOnly(true);
    setFont(f);

    ricetta1Nome = new QLineEdit("Nome Ricetta 1");
    ricetta2Nome = new QLineEdit("Nome Ricetta 2");


    addIngrediente1 = new QPushButton("Aggiungi Ingrediente");
    addIngrediente2 = new QPushButton("Aggiungi Ingrediente");
    removeIngrediente1 = new QPushButton("Rimuovi Ingrediente");
    removeIngrediente2 = new QPushButton("Rimuovi Ingrediente");
    calorie1 = new QPushButton("Calcola Calorie");
    calorie2= new QPushButton("Calcola Calorie");
    costo1= new QPushButton("Calcola Costo");
    costo2= new QPushButton("Calcola Costo");
    sommaRicette= new QPushButton("Somma le quantita degli ingredienti di ricetta B a ricetta A");
    differenzaRicette= new QPushButton("Sottrai le quantita degli ingredienti di ricetta B da ricetta A");
    proporziona1= new QPushButton("Proporziona\n ricetta  per ");
    proporziona2 = new QPushButton("Proporziona\n ricetta  per ");
    useResultAsRicetta1 =new QPushButton("Usa come Ricetta 1");
    useResultAsRicetta2 = new QPushButton("Usa come Ricetta 2");


    prop1 = new QSpinBox;
    prop2= new QSpinBox;
    prop1->setSuffix(" Persone");
    prop2->setSuffix(" Persone");


    l1 = new QHBoxLayout;
    l1->addWidget(proporziona1);
    l1->addWidget(prop1);
    l1->addWidget(proporziona2);
    l1->addWidget(prop2);

    layout->addWidget(ricetta1Nome,0,0);
    layout->addWidget(ricetta2Nome,0,1);


    layout->addWidget(ricetta1,1,0);
    layout->addWidget(ricetta2,1,1);
    layout->addWidget(ricettaResult,0,2,7,1);
    layout->addWidget(addIngrediente1,2,0);
    layout->addWidget(addIngrediente2,2,1);
    layout->addWidget(removeIngrediente1,3,0);
    layout->addWidget(removeIngrediente2,3,1);
    layout->addWidget(costo1,4,0);
    layout->addWidget(costo2,4,1);
    layout->addWidget(calorie1,5,0);
    layout->addWidget(calorie2,5,1);
    layout->addLayout(l1,6,0,1,2);
    layout->addWidget(sommaRicette,7,0,1,2);
    layout->addWidget(useResultAsRicetta1,7,2);
    layout->addWidget(differenzaRicette,8,0,1,2);
    layout->addWidget(useResultAsRicetta2,8,2);


    setLayout(layout);

    connect(addIngrediente1,SIGNAL(clicked(bool)),this,SLOT(showDialogIngrediente()));
    connect(addIngrediente2,SIGNAL(clicked(bool)),this,SLOT(showDialogIngrediente()));
    connect(removeIngrediente1,SIGNAL(clicked(bool)),this,SLOT(showDialogIngrediente()));
    connect(removeIngrediente2,SIGNAL(clicked(bool)),this,SLOT(showDialogIngrediente()));


    connect(addIngrediente1,SIGNAL(clicked(bool)),this,SIGNAL(btnAddIngrediente1Clicked()));
    connect(addIngrediente2,SIGNAL(clicked(bool)),this,SIGNAL(btnAddIngrediente2Clicked()));
    connect(removeIngrediente1,SIGNAL(clicked(bool)),this,SIGNAL(btnRemoveIngrediente1Clicked()));
    connect(removeIngrediente2,SIGNAL(clicked(bool)),this,SIGNAL(btnRemoveIngrediente2Clicked()));
    connect(costo1,SIGNAL(clicked(bool)),this,SIGNAL(btnCosto1Clicked()));
    connect(costo2,SIGNAL(clicked(bool)),this,SIGNAL(btnCosto2Clicked()));
    connect(calorie1,SIGNAL(clicked(bool)),this,SIGNAL(btnCalorie1Clicked()));
    connect(calorie2,SIGNAL(clicked(bool)),this,SIGNAL(btnCalorie2Clicked()));
    connect(proporziona1,SIGNAL(clicked(bool)),this,SIGNAL(btnProporziona1Clicked()));
    connect(proporziona2,SIGNAL(clicked(bool)),this,SIGNAL(btnProporziona2Clicked()));
    connect(sommaRicette,SIGNAL(clicked(bool)),this,SIGNAL(btnSommaClicked()));
    connect(differenzaRicette,SIGNAL(clicked(bool)),this,SIGNAL(btnDifferenzaClicked()));
    connect(useResultAsRicetta1,SIGNAL(clicked(bool)),this,SIGNAL(btnUseAsRicetta1Clicked()));
    connect(useResultAsRicetta2,SIGNAL(clicked(bool)),this,SIGNAL(btnUseAsRicetta2Clicked()));
    connect(ricetta1Nome,SIGNAL(textChanged(QString)),this,SIGNAL(Ricetta1NameChanged()));
    connect(ricetta2Nome,SIGNAL(textChanged(QString)),this,SIGNAL(Ricetta2NameChanged()));
     Controller= new RicettaController(this);

}
RicettaGui::~RicettaGui(){
    delete l1;
    delete ricetta1;
    delete ricetta2;
    delete ricettaResult;
    delete ricetta1Nome;
    delete ricetta2Nome;
    delete addIngrediente1;
    delete addIngrediente2;
    delete removeIngrediente1;
    delete removeIngrediente2;
    delete calorie1;
    delete calorie2;
    delete costo1;
    delete costo2;
    delete sommaRicette;
    delete differenzaRicette;
    delete proporziona1;
    delete proporziona2;
    delete layout;
    delete useResultAsRicetta1;
    delete useResultAsRicetta2;
    delete prop1;
    delete prop2;
    delete ingDialog;
    delete Controller;
}
IngredienteDialog* RicettaGui::getIngredienteDialog()const{return ingDialog;}
void RicettaGui::showDialogIngrediente(){
 ingDialog->exec();
}
QPlainTextEdit* RicettaGui::getRicetta1Viewer()const{return ricetta1;}
QPlainTextEdit* RicettaGui::getRicetta2Viewer()const{return ricetta2;}
QPlainTextEdit* RicettaGui::getResultViewer()const{return ricettaResult;}
QString RicettaGui::getNomeRicetta1()const{return ricetta1Nome->text();}
QString RicettaGui::getNomeRicetta2()const{return ricetta2Nome->text();}
int RicettaGui::getPropRicetta1Value()const{return prop1->value();}
int RicettaGui::getPropRicetta2Value()const{return prop2->value();}
QLineEdit* RicettaGui::getLineEdit1Nome()const{return ricetta1Nome;}
QLineEdit* RicettaGui::getLineEdit2Nome()const{return ricetta2Nome;}
