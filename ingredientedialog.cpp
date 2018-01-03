#include "ingredientedialog.h"

IngredienteDialog::IngredienteDialog(QWidget* parent):  QDialog(parent)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    QFont f("Verdana",12);
    setFont(f);
    setWindowTitle("Dati Ingrediente");
    layout = new QGridLayout;
    ok = new QPushButton("OK");
    cancel= new QPushButton("Annulla");
    lblNome = new QLabel("Nome Ingrediente");
    lblQuantita = new QLabel("Quantita Ingrediente");
    lblCalorie = new QLabel("Calorie Ingrediente");
    lblCosto = new QLabel("Costo Ingrediente");

    editNome = new QLineEdit("Nome Ingrediente");
    spinQuantita = new QDoubleSpinBox;
    spinQuantita->setMinimum(0.0);
    spinQuantita->setSuffix(" g");
    spinCalorie  = new QDoubleSpinBox;
    spinCalorie->setMinimum(0.0);
    spinCalorie->setSuffix(" x 100 g");
    spinCosto = new QDoubleSpinBox;
    spinCosto->setMinimum(0.0);
    spinCosto->setSuffix(" al g");

    layout->addWidget(lblNome,0,0);
    layout->addWidget(editNome,0,1);
    layout->addWidget(lblQuantita,1,0);
    layout->addWidget(spinQuantita,1,1);
    layout->addWidget(lblCalorie,2,0);
    layout->addWidget(spinCalorie,2,1);
    layout->addWidget(lblCosto,3,0);
    layout->addWidget(spinCosto,3,1);
    layout->addWidget(ok,4,0);
    layout->addWidget(cancel,4,1);

    setLayout(layout);
    connect(ok,SIGNAL(clicked(bool)),this,SLOT(btnOK()));
    connect(cancel,SIGNAL(clicked(bool)),this,SLOT(btnCancel()));

}
IngredienteDialog::~IngredienteDialog(){
    delete layout;
    delete ok;
    delete cancel;

    delete lblNome;
    delete lblQuantita;
    delete lblCalorie;
    delete lblCosto;

    delete editNome;
    delete spinQuantita;
    delete spinCalorie;
    delete spinCosto;

}
QLineEdit* IngredienteDialog::getNomeIngrediente()const{return editNome;}
QDoubleSpinBox* IngredienteDialog::getQuantitaIngrediente()const{return spinQuantita;}
QDoubleSpinBox* IngredienteDialog::getCalorieIngrediente()const{return spinCalorie;}
QDoubleSpinBox* IngredienteDialog::getCostoIngrediente()const{return spinCosto;}
void IngredienteDialog::btnOK(){
    done(QDialog::Accepted);
}
void IngredienteDialog::btnCancel(){
    done(QDialog::Rejected);
}
