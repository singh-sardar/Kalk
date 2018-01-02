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

    layout->addWidget(ricetta1Nome,0,0);
    layout->addWidget(ricetta2Nome,0,1);
    layout->addWidget(ricettaResultNome,0,2);

    layout->addWidget(ricetta1,1,0);
    layout->addWidget(ricetta2,1,1);
    layout->addWidget(ricettaResult,1,2);
    layout->addWidget(addIngrediente1,2,0);
    layout->addWidget(addIngrediente2,2,1);
    layout->addWidget(removeIngrediente1,3,0);
    layout->addWidget(removeIngrediente2,3,1);
    setLayout(layout);

}
