#include <QFont>
#include <QTableWidget>
#include <QWidget>
#include <QHeaderView>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "tableviewmatrice.h"

TableViewMatrice::TableViewMatrice(QWidget* parent, QString lblMatrice, int righe, int colonne, int maxRighe, int maxColonne):
    QWidget(parent)
{
    tableWidget = new QTableWidget(righe,colonne,this);
    tableWidget->setGeometry(0,0,350,350);
    tableWidget->setMinimumSize(350,350);
    //tableWidget->setMaximumSize(350,350);
    tableWidget->setShowGrid(true);

    /*
    QHeaderView* header = tableWidget->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    */

    tableWidget->setEditTriggers(QAbstractItemView::AllEditTriggers);
    tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    verticalLayout= new QVBoxLayout;
    hLPerRighe = new QHBoxLayout;
    hLPerColonne = new QHBoxLayout;

    QFont f("Verdana",14);
    f.setBold(false);
    labelSpinBoxRighe = new QLabel;
    labelSpinBoxColonne = new QLabel;
    labelMatrice = new QLabel;
    labelMatrice->setFont(f);
    labelSpinBoxRighe->setFont(f);
    labelSpinBoxColonne->setFont(f);
    labelMatrice->setText(lblMatrice);
    labelSpinBoxRighe->setText("Numero righe: ");
    labelSpinBoxColonne->setText("Numero colonne: ");

    verticalLayout->addWidget(labelMatrice);
    verticalLayout->addWidget(tableWidget);

    spinBoxRighe = new QSpinBox();
    spinBoxColonne = new QSpinBox();
    spinBoxRighe->setFont(f);
    spinBoxColonne->setFont(f);
    spinBoxRighe->setRange(1,maxRighe);
    spinBoxColonne->setRange(1,maxColonne);
    spinBoxRighe->setValue(righe);
    spinBoxColonne->setValue(colonne);

    hLPerRighe->addWidget(labelSpinBoxRighe);
    hLPerRighe->addWidget(spinBoxRighe);
    hLPerColonne->addWidget(labelSpinBoxColonne);
    hLPerColonne->addWidget(spinBoxColonne);

    verticalLayout->addLayout(hLPerRighe);
    verticalLayout->addLayout(hLPerColonne);

    setLayout(verticalLayout);
    impostaCelle();

    connect(spinBoxRighe,SIGNAL(valueChanged(int)),this,SLOT(modificaNumRighe()));
    connect(spinBoxColonne,SIGNAL(valueChanged(int)),this,SLOT(modificaNumColonne()));
    connect(spinBoxRighe,SIGNAL(valueChanged(int)),this,SLOT(impostaCelle()));
    connect(spinBoxColonne,SIGNAL(valueChanged(int)),this,SLOT(impostaCelle()));
}

QTableWidget* TableViewMatrice::getTableWidget() const{
    return tableWidget;
}

QLabel* TableViewMatrice::getLableMatrice() const{
    return labelMatrice;
}

void TableViewMatrice::modificaNumRighe(){
    tableWidget->clear();
    tableWidget->setRowCount(spinBoxRighe->value());
}

void TableViewMatrice::modificaNumColonne(){
    tableWidget->clear();
    tableWidget->setColumnCount(spinBoxColonne->value());
}

void TableViewMatrice::impostaCelle(){
    for(int i=0; i < tableWidget->rowCount(); ++i){
        for(int j=0; j < tableWidget->columnCount(); ++j){

            QTableWidgetItem *pCell = tableWidget->item(i, j);

            if(!pCell)
            {
                pCell = new QTableWidgetItem();
                pCell->setTextAlignment(Qt::AlignRight);
                tableWidget->setItem(i, j, pCell);
            }
            pCell->setText(QString("0"));
        }
    }

    tableWidget->resizeColumnsToContents();
}

TableViewMatrice::~TableViewMatrice(){
    delete tableWidget;
    delete spinBoxRighe;
    delete spinBoxColonne;
    delete labelMatrice;
    delete labelSpinBoxRighe;
    delete labelSpinBoxColonne;
    delete verticalLayout;
    delete hLPerRighe;
    delete hLPerColonne;
}

