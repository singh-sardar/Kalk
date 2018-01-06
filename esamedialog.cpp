#include "esamedialog.h"

EsameDialog::EsameDialog(QWidget *parent):
    QDialog(parent)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    QFont f("Verdana",12);

    setWindowTitle("Dati Esame");
    layout = new QGridLayout;

    ok = new QPushButton("OK");
    cancel= new QPushButton("Annulla");

    lblCFU = new QLabel("CFU");
    lblNomeCorso = new QLabel("Corso");
    lblNomeMateria = new QLabel("Materia");
    lblNomeProfessore = new QLabel("Professore");
    lblVoto = new QLabel("Voto");
    lblGiorno = new QLabel("Giorno");
    lblMese = new QLabel("Mese");
    lblAnno = new QLabel("Anno");

    lineEditNomeMateria = new QLineEdit("Nome materia");
    lineEditNomeCorso = new QLineEdit("Nome corso");
    lineEditNomeProfessore = new QLineEdit("Nome professore");

    spinGiorno = new QSpinBox;
    spinMese = new QSpinBox;
    spinAnno = new QSpinBox;
    spinVoto = new QSpinBox;
    spinCFU = new QSpinBox;

    spinCFU->setMinimum(1);
    spinVoto->setMinimum(18);
    spinGiorno->setRange(1,31);
    spinMese->setRange(1,12);
    spinAnno->setMinimum(2000);

    layout->addWidget(lblNomeMateria,0,0);
    layout->addWidget(lineEditNomeMateria,1,0);
    layout->addWidget(lblNomeCorso,0,1);
    layout->addWidget(lineEditNomeCorso,1,1);
    layout->addWidget(lblNomeProfessore,0,2);
    layout->addWidget(lineEditNomeProfessore,1,2);
    layout->addWidget(lblVoto,2,0);
    layout->addWidget(spinVoto,3,0);
    layout->addWidget(lblCFU,2,1);
    layout->addWidget(spinCFU,3,1);
    layout->addWidget(lblGiorno,4,0);
    layout->addWidget(spinGiorno,5,0);
    layout->addWidget(lblMese,4,1);
    layout->addWidget(spinMese,5,1);
    layout->addWidget(lblAnno,4,2);
    layout->addWidget(spinAnno,5,2);
    layout->addWidget(ok,6,0,1,3);
    layout->addWidget(cancel,7,0,1,3);

    setFont(f);

    setLayout(layout);
    connect(ok,SIGNAL(clicked(bool)),this,SLOT(btnOK()));
    connect(cancel,SIGNAL(clicked(bool)),this,SLOT(btnCancel()));
}

void EsameDialog::btnOK(){
    done(QDialog::Accepted);
}

void EsameDialog::btnCancel(){
    done(QDialog::Rejected);
}

QLineEdit* EsameDialog::getLineEditCorso() const{
    return lineEditNomeCorso;
}

QLineEdit* EsameDialog::getLineEditMateria() const{
    return lineEditNomeMateria;
}

QLineEdit* EsameDialog::getLineEditProfessore() const{
    return lineEditNomeProfessore;
}

QSpinBox* EsameDialog::getSpinBoxGiorno() const{
    return spinGiorno;
}

QSpinBox* EsameDialog::getSpinBoxMese() const{
    return spinMese;
}

QSpinBox* EsameDialog::getSpinBoxAnno() const{
    return spinAnno;
}

QSpinBox* EsameDialog::getSpinBoxVoto() const{
    return spinVoto;
}

QSpinBox* EsameDialog::getSpinBoxCFU() const{
    return spinCFU;
}

EsameDialog::~EsameDialog(){
    delete lineEditNomeMateria;
    delete lineEditNomeCorso;
    delete lineEditNomeProfessore;
    delete spinGiorno;
    delete spinMese;
    delete spinAnno;
    delete spinVoto;
    delete spinCFU;
    delete layout;
    delete ok;
    delete cancel;
    delete lblNomeMateria;
    delete lblNomeCorso;
    delete lblNomeProfessore;
    delete lblGiorno;
    delete lblMese;
    delete lblAnno;
    delete lblVoto;
    delete lblCFU;
}
