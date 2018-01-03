#include "ricettagui.h"

RicettaGui::RicettaGui(QWidget* parent ):QWidget(parent)
{
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
    ricettaResultNome = new QLineEdit("Nome Ricetta Risultato");


    addIngrediente1 = new QPushButton("Aggiungi Ingrediente");
    addIngrediente2 = new QPushButton("Aggiungi Ingrediente");
    removeIngrediente1 = new QPushButton("Rimuovi Ingrediente");
    removeIngrediente2 = new QPushButton("Rimuovi Ingrediente");
    calorie1 = new QPushButton("Calcola Calorie");
    calorie2= new QPushButton("Calcola Calorie");
    costo1= new QPushButton("Calcola Costo");
    costo2= new QPushButton("Calcola Costo");
    sommaRicette= new QPushButton("Somma le 2 ricette");
    differenzaRicette= new QPushButton("Differenza tra le 2 ricette");
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
    layout->addWidget(ricettaResultNome,0,2);

    layout->addWidget(ricetta1,1,0);
    layout->addWidget(ricetta2,1,1);
    layout->addWidget(ricettaResult,1,2,6,1);
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

}
