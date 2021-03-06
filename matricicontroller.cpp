#include "matricicontroller.h"
#include <QMessageBox>
#include <QDebug>

MatriciController::MatriciController(MatriciGUI* view):
    viewMatrici(view), matrice1(new Matrice()), matrice2(new Matrice()), matriceRisultato(new Matrice())
{

    connect(viewMatrici,SIGNAL(btnSommaClicked(bool)),this,SLOT(aggiornaMatrice1()));
    connect(viewMatrici,SIGNAL(btnSommaClicked(bool)),this,SLOT(aggiornaMatrice2()));
    connect(viewMatrici,SIGNAL(btnSommaClicked(bool)),this,SLOT(somma()));

    connect(viewMatrici,SIGNAL(btnDifferenzaClicked(bool)),this,SLOT(aggiornaMatrice1()));
    connect(viewMatrici,SIGNAL(btnDifferenzaClicked(bool)),this,SLOT(aggiornaMatrice2()));
    connect(viewMatrici,SIGNAL(btnDifferenzaClicked(bool)),this,SLOT(sottrazione()));

    connect(viewMatrici,SIGNAL(btnMoltiplicazioneClicked(bool)),this,SLOT(aggiornaMatrice1()));
    connect(viewMatrici,SIGNAL(btnMoltiplicazioneClicked(bool)),this,SLOT(aggiornaMatrice2()));
    connect(viewMatrici,SIGNAL(btnMoltiplicazioneClicked(bool)),this,SLOT(moltiplicazione()));

    connect(viewMatrici,SIGNAL(btnDeterminanteClicked1(bool)),this,SLOT(aggiornaMatrice1()));
    connect(viewMatrici,SIGNAL(btnDeterminanteClicked1(bool)),this,SLOT(determinante1()));

    connect(viewMatrici,SIGNAL(btnMoltiplicazioneScalareClicked1(bool)),this,SLOT(aggiornaMatrice1()));
    connect(viewMatrici,SIGNAL(btnMoltiplicazioneScalareClicked1(bool)),this,SLOT(moltiplicazioneScalare1()));

    connect(viewMatrici,SIGNAL(btnDivisioneScalareClicked1(bool)),this,SLOT(aggiornaMatrice1()));
    connect(viewMatrici,SIGNAL(btnDivisioneScalareClicked1(bool)),this,SLOT(divisioneScalare1()));

    connect(viewMatrici,SIGNAL(btnMatriceCofattoriClicked1(bool)),this,SLOT(aggiornaMatrice1()));
    connect(viewMatrici,SIGNAL(btnMatriceCofattoriClicked1(bool)),this,SLOT(matriceCofattori1()));

    connect(viewMatrici,SIGNAL(btnMatriceInversaClicked1(bool)),this,SLOT(aggiornaMatrice1()));
    connect(viewMatrici,SIGNAL(btnMatriceInversaClicked1(bool)),this,SLOT(matriceInversa1()));

    connect(viewMatrici,SIGNAL(btnMatriceTraspostaClicked1(bool)),this,SLOT(aggiornaMatrice1()));
    connect(viewMatrici,SIGNAL(btnMatriceTraspostaClicked1(bool)),this,SLOT(matriceTrasposta1()));

    connect(viewMatrici,SIGNAL(btnElevaAPotenzaClicked1(bool)),this,SLOT(aggiornaMatrice1()));
    connect(viewMatrici,SIGNAL(btnElevaAPotenzaClicked1(bool)),this,SLOT(elevaAPotenza1()));

    connect(viewMatrici,SIGNAL(btnIsSimmetricaClicked1(bool)),this,SLOT(aggiornaMatrice1()));
    connect(viewMatrici,SIGNAL(btnIsSimmetricaClicked1(bool)),this,SLOT(isSimmetrica1()));

    connect(viewMatrici,SIGNAL(btnIsDiagonaleClicked1(bool)),this,SLOT(aggiornaMatrice1()));
    connect(viewMatrici,SIGNAL(btnIsDiagonaleClicked1(bool)),this,SLOT(isDiagonale1()));

    connect(viewMatrici,SIGNAL(btnIsScalareClicked1(bool)),this,SLOT(aggiornaMatrice1()));
    connect(viewMatrici,SIGNAL(btnIsScalareClicked1(bool)),this,SLOT(isScalare1()));

    connect(viewMatrici,SIGNAL(btnDeterminanteClicked2(bool)),this,SLOT(aggiornaMatrice2()));
    connect(viewMatrici,SIGNAL(btnDeterminanteClicked2(bool)),this,SLOT(determinante2()));

    connect(viewMatrici,SIGNAL(btnMoltiplicazioneScalareClicked2(bool)),this,SLOT(aggiornaMatrice2()));
    connect(viewMatrici,SIGNAL(btnMoltiplicazioneScalareClicked2(bool)),this,SLOT(moltiplicazioneScalare2()));

    connect(viewMatrici,SIGNAL(btnDivisioneScalareClicked2(bool)),this,SLOT(aggiornaMatrice2()));
    connect(viewMatrici,SIGNAL(btnDivisioneScalareClicked2(bool)),this,SLOT(divisioneScalare2()));

    connect(viewMatrici,SIGNAL(btnMatriceCofattoriClicked2(bool)),this,SLOT(aggiornaMatrice2()));
    connect(viewMatrici,SIGNAL(btnMatriceCofattoriClicked2(bool)),this,SLOT(matriceCofattori2()));

    connect(viewMatrici,SIGNAL(btnMatriceInversaClicked2(bool)),this,SLOT(aggiornaMatrice2()));
    connect(viewMatrici,SIGNAL(btnMatriceInversaClicked2(bool)),this,SLOT(matriceInversa2()));

    connect(viewMatrici,SIGNAL(btnMatriceTraspostaClicked2(bool)),this,SLOT(aggiornaMatrice2()));
    connect(viewMatrici,SIGNAL(btnMatriceTraspostaClicked2(bool)),this,SLOT(matriceTrasposta2()));

    connect(viewMatrici,SIGNAL(btnElevaAPotenzaClicked2(bool)),this,SLOT(aggiornaMatrice2()));
    connect(viewMatrici,SIGNAL(btnElevaAPotenzaClicked2(bool)),this,SLOT(elevaAPotenza2()));

    connect(viewMatrici,SIGNAL(btnIsSimmetricaClicked2(bool)),this,SLOT(aggiornaMatrice2()));
    connect(viewMatrici,SIGNAL(btnIsSimmetricaClicked2(bool)),this,SLOT(isSimmetrica2()));

    connect(viewMatrici,SIGNAL(btnIsDiagonaleClicked2(bool)),this,SLOT(aggiornaMatrice2()));
    connect(viewMatrici,SIGNAL(btnIsDiagonaleClicked2(bool)),this,SLOT(isDiagonale2()));

    connect(viewMatrici,SIGNAL(btnIsScalareClicked2(bool)),this,SLOT(aggiornaMatrice2()));
    connect(viewMatrici,SIGNAL(btnIsScalareClicked2(bool)),this,SLOT(isScalare2()));
}

void MatriciController::showMessageBox(QString title, QString text) const{
    QMessageBox msgBox;
    msgBox.setWindowTitle(title);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setFont(QFont("Verdana",14));

    msgBox.setText(text);
    msgBox.exec();
}

void MatriciController::aggiornaLabelRisultato(QString s){
    viewMatrici->getLabelRisultato()->setText(s);
}

void MatriciController::aggiornaMatrice1(){
    delete matrice1;

    QTableWidget* w = viewMatrici->getTableWidget1();
    matrice1 = new Matrice(w->rowCount(),w->columnCount());
    for(unsigned int i=0; i < matrice1->getNumRighe(); ++i){
        for(unsigned int j=0; j < matrice1->getNumColonne(); ++j){
            matrice1->setValore(i,j,w->item(i,j)->text().toDouble());
        }
    }
}

void MatriciController::aggiornaMatrice2(){
    delete matrice2;

    QTableWidget* w = viewMatrici->getTableWidget2();
    matrice2 = new Matrice(w->rowCount(),w->columnCount());
    for(unsigned int i=0; i < matrice2->getNumRighe(); ++i){
        for(unsigned int j=0; j < matrice2->getNumColonne(); ++j){
            matrice2->setValore(i,j,w->item(i,j)->text().toDouble());
        }
    }
}

void MatriciController::aggiornaTableViewRisultato(){
    QTableWidget* wR = viewMatrici->getTableWidgetRisultato();

    wR->setRowCount(matriceRisultato->getNumRighe());
    wR->setColumnCount(matriceRisultato->getNumColonne());
    for(unsigned int i=0; i < matriceRisultato->getNumRighe(); ++i){
        for(unsigned int j=0; j < matriceRisultato->getNumColonne(); ++j){
            QTableWidgetItem *pCell = wR->item(i, j);
            if(!pCell)
            {
                pCell = new QTableWidgetItem();
                wR->setItem(i, j, pCell);
            }
            pCell->setText(QString::number(matriceRisultato->getValore(i,j)));
            pCell->setTextAlignment(Qt::AlignRight);
        }
    }
    wR->resizeColumnsToContents();
}

void MatriciController::somma(){
    matriceRisultato = (*matrice1) + (*matrice2);
    if(matriceRisultato){
        aggiornaTableViewRisultato();
        showMessageBox("Somma matrici","La matrice (somma) si trova nella matrice Risultato");
        aggiornaLabelRisultato("La matrice (somma) si trova nella matrice Risultato");
    }else{
        showMessageBox("Errore somma matrici","Le matrici devono avere stesse dimensioni");
    }
}

void MatriciController::sottrazione(){
    matriceRisultato = *matrice1 - *matrice2;
    if(matriceRisultato){
        aggiornaTableViewRisultato();
        showMessageBox("Differenza matrici","La matrice (sottrazione) si trova nella matrice Risultato");
        aggiornaLabelRisultato("La matrice (sottrazione) si trova nella matrice Risultato");
    }else{
        showMessageBox("Errore sottrazione matrici","Le matrici devono avere stesse dimensioni");
    }
}

void MatriciController::moltiplicazione(){
    matriceRisultato = *matrice1 * *matrice2;
    if(matriceRisultato){
        aggiornaTableViewRisultato();
        showMessageBox("Moltiplicazione matrici","La matrice (moltiplicazione) si trova nella matrice Risultato");
        aggiornaLabelRisultato("La matrice (moltiplicazione) si trova nella matrice Risultato");
    }
    else{
        showMessageBox("Errore moltiplicazione matrici","Non e' possibile eseguire la moltiplicazione.");
    }
}

void MatriciController::moltiplicazioneScalare1(){
    double d = viewMatrici->getLineEditMatrice1()->text().toDouble();
    matriceRisultato = *matrice1 * d;
    if(matriceRisultato){
        aggiornaTableViewRisultato();
        showMessageBox("Prodotto scalare matrice 1","La matrice dell'operazione (prodotto scalare) si trova nella matrice Risultato");
        aggiornaLabelRisultato("La matrice dell'operazione (prodotto scalare) si trova nella matrice Risultato");
    }
    else{
        showMessageBox("Errore moltiplicazione scalare","Non e' possibile eseguire la moltiplicazione scalare.");
    }
}

void MatriciController::moltiplicazioneScalare2(){
    double d = viewMatrici->getLineEditMatrice2()->text().toDouble();
    matriceRisultato = *matrice2 * d;
    if(matriceRisultato){
        aggiornaTableViewRisultato();
        showMessageBox("Prodotto scalare matrice 2","La matrice dell'operazione (prodotto scalare) si trova nella matrice Risultato");
        aggiornaLabelRisultato("La matrice dell'operazione (prodotto scalare) si trova nella matrice Risultato");
    }
    else{
        showMessageBox("Errore moltiplicazione scalare","Non e' possibile eseguire la moltiplicazione scalare.");
    }
}

void MatriciController::divisioneScalare1(){
    double d = viewMatrici->getLineEditMatrice1()->text().toDouble();
    if(d != 0.0){
        matriceRisultato = (*matrice1/d);
        if(matriceRisultato){
            aggiornaTableViewRisultato();
            showMessageBox("Divisione scalare matrice 1","La matrice dell'operazione (divisione scalare) si trova nella matrice Risultato");
            aggiornaLabelRisultato("La matrice dell'operazione (divisione scalare) si trova nella matrice Risultato");
        }
        else{
            showMessageBox("Errore divisione scalare","Non e' possibile eseguire la divisione scalare.");
        }
    }
    else{
        showMessageBox("Errore divisione per 0","Non e' possibile dividere la matrice per 0.");
    }
}

void MatriciController::divisioneScalare2(){
    double d = viewMatrici->getLineEditMatrice2()->text().toDouble();
    if(d != 0.0){
        matriceRisultato = (*matrice2/d);
        if(matriceRisultato){
            aggiornaTableViewRisultato();
            showMessageBox("Divisione scalare matrice 2","La matrice dell'operazione (divisione scalare) si trova nella matrice Risultato");
            aggiornaLabelRisultato("La matrice dell'operazione (divisione scalare) si trova nella matrice Risultato");
        }
        else{
            showMessageBox("Errore divisione scalare","Non e' possibile eseguire la divisione scalare.");
        }
    }
    else{
        showMessageBox("Errore divisione per 0","Non e' possibile dividere la matrice per 0.");
    }
}

void MatriciController::determinante1(){
    if((matrice1->getNumRighe()==matrice1->getNumColonne())){
        showMessageBox("Determinante matrice 1",QString("Determinante matrice 1: ")+QString::number(matrice1->determinante()));
        aggiornaLabelRisultato(QString("Determinante matrice 1: ")+QString::number(matrice1->determinante()));
    }else{
        showMessageBox("Errore determinante matrice 1","La matrice 1 deve essere quadrata.");
    }
}

void MatriciController::determinante2(){
    if((matrice2->getNumRighe()==matrice2->getNumColonne())){
        showMessageBox("Determinante matrice 2",QString("Determinante matrice 2: ")+QString::number(matrice2->determinante()));
        aggiornaLabelRisultato(QString("Determinante matrice 2: ")+QString::number(matrice2->determinante()));
    }else{
        showMessageBox("Errore determinante matrice 2","La matrice 2 deve essere quadrata.");
    }
}

void MatriciController::matriceInversa1(){
    matriceRisultato = matrice1->matriceInversa();
    if(matriceRisultato){
        aggiornaTableViewRisultato();
        showMessageBox("Matrice inversa 1","La matrice inversa si trova nella matrice Risultato");
        aggiornaLabelRisultato("La matrice inversa si trova nella matrice Risultato");
    }
    else{
        showMessageBox("Errore matrice inversa 1","La matrice 1 deve essere quadrata oppure determinante e' 0.");
    }
}

void MatriciController::matriceInversa2(){
    matriceRisultato = matrice2->matriceInversa();
    if(matriceRisultato){
        aggiornaTableViewRisultato();
        showMessageBox("Matrice inversa 2","La matrice inversa si trova nella matrice Risultato");
        aggiornaLabelRisultato("La matrice inversa si trova nella matrice Risultato");
    }
    else{
        showMessageBox("Errore matrice inversa 2","La matrice 2 deve essere quadrata oppure determinante e' 0.");
    }
}

void MatriciController::matriceTrasposta1(){
    matriceRisultato = matrice1->matriceTrasposta();
    if(matriceRisultato){
        aggiornaTableViewRisultato();
        showMessageBox("Matrice trasposta 1","La matrice trasposta si trova nella matrice Risultato");
        aggiornaLabelRisultato("La matrice trasposta si trova nella matrice Risultato");
    }
    else{
        showMessageBox("Errore matrice trasposta 1","Non e' possibile trovare la matrice trasposta.");
    }
}

void MatriciController::matriceTrasposta2(){
    matriceRisultato = matrice2->matriceTrasposta();
    if(matriceRisultato){
        aggiornaTableViewRisultato();
        showMessageBox("Matrice trasposta 2","La matrice trasposta si trova nella matrice Risultato");
        aggiornaLabelRisultato("La matrice trasposta si trova nella matrice Risultato");
    }
    else{
        showMessageBox("Errore matrice trasposta 2","Non e' possibile trovare la matrice trasposta.");
    }
}

void MatriciController::matriceCofattori1(){
    matriceRisultato = matrice1->matriceCofattore();
    if(matriceRisultato){
        aggiornaTableViewRisultato();
        showMessageBox("Matrice dei cofattori 1","La matrice dei cofattori si trova nella matrice Risultato");
        aggiornaLabelRisultato("La matrice dei cofattori si trova nella matrice Risultato");
    }
    else{
        showMessageBox("Errore matrice dei cofattori 1","Non e' possibile trovare la matrice dei cofattori oppure determinante e' 0.");
    }
}

void MatriciController::matriceCofattori2(){
    matriceRisultato = matrice2->matriceCofattore();
    if(matriceRisultato){
        aggiornaTableViewRisultato();
        showMessageBox("Matrice dei cofattori 2","La matrice dei cofattori si trova nella matrice Risultato");
        aggiornaLabelRisultato("La matrice dei cofattori si trova nella matrice Risultato");
    }
    else{
        showMessageBox("Errore matrice dei cofattori 2","Non e' possibile trovare la matrice dei cofattori oppure determinante e' 0.");
    }
}

void MatriciController::elevaAPotenza1(){
    double d = viewMatrici->getLineEditMatrice1()->text().toDouble();
    matriceRisultato = matrice1->elevaAPotenza(d);
    if(matriceRisultato){
        aggiornaTableViewRisultato();
        showMessageBox("Elevamento a potenza matrice 1","La matrice dell'operazione (elevamento a potenza) si trova nella matrice Risultato");
        aggiornaLabelRisultato("La matrice dell'operazione (elevamento a potenza) si trova nella matrice Risultato");
    }
    else{
        showMessageBox("Errore matrice 1","Non e' possibile eseguire l'elevazione a potenza.");
    }
}

void MatriciController::elevaAPotenza2(){
    double d = viewMatrici->getLineEditMatrice2()->text().toDouble();
    matriceRisultato = matrice2->elevaAPotenza(d);
    if(matriceRisultato){
        aggiornaTableViewRisultato();
        showMessageBox("Elevamento a potenza matrice 2","La matrice dell'operazione (elevamento a potenza) si trova nella matrice Risultato");
        aggiornaLabelRisultato("La matrice dell'operazione (elevamento a potenza) si trova nella matrice Risultato");
    }
    else{
        showMessageBox("Errore matrice 2","Non e' possibile eseguire l'elevazione a potenza.");
    }
}

void MatriciController::isDiagonale1(){
    if(matrice1->isDiagonale()){
        showMessageBox("Matrice 1 diagonale",QString("La matrice 1 e' diagonale."));
        aggiornaLabelRisultato(QString("La matrice 1 e' diagonale."));
    }else{
        showMessageBox("Matrice 1 diagonale",QString("La matrice 1 non e' diagonale."));
        aggiornaLabelRisultato(QString("La matrice 1 non e' diagonale."));
    }
}

void MatriciController::isDiagonale2(){
    if(matrice2->isDiagonale()){
        showMessageBox("Matrice 2 diagonale",QString("La matrice 2 e' diagonale."));
        aggiornaLabelRisultato(QString("La matrice 2 e' diagonale."));
    }else{
        showMessageBox("Matrice 2 diagonale",QString("La matrice 2 non e' diagonale."));
        aggiornaLabelRisultato(QString("La matrice 2 non e' diagonale."));
    }
}

void MatriciController::isSimmetrica1(){
    if(matrice1->isSimmetrica()){
        showMessageBox("Matrice 1 simmetrica",QString("La matrice 1 e' simmetrica."));
        aggiornaLabelRisultato(QString("La matrice 1 e' simmetrica."));
    }else{
        showMessageBox("Matrice 1 simmetrica",QString("La matrice 1 non e' simmetrica."));
        aggiornaLabelRisultato(QString("La matrice 1 non e' simmetrica."));
    }
}

void MatriciController::isSimmetrica2(){
    if(matrice2->isSimmetrica()){
        showMessageBox("Matrice 2 simmetrica",QString("La matrice 2 e' simmetrica."));
        aggiornaLabelRisultato(QString("La matrice 2 e' simmetrica."));
    }else{
        showMessageBox("Matrice 2 simmetrica",QString("La matrice 2 non e' simmetrica."));
        aggiornaLabelRisultato(QString("La matrice 2 non e' simmetrica."));
    }
}

void MatriciController::isScalare1(){
    if(matrice1->isScalare(viewMatrici->getLineEditMatrice1()->text().toDouble())){
        showMessageBox("Matrice 1 scalare",QString("La matrice 1 e' scalare."));
        aggiornaLabelRisultato(QString("La matrice 1 e' scalare."));
    }else{
        showMessageBox("Matrice 1 scalare",QString("La matrice 1 non e' scalare."));
        aggiornaLabelRisultato(QString("La matrice 1 non e' scalare."));
    }
}

void MatriciController::isScalare2(){
    if(matrice2->isScalare(viewMatrici->getLineEditMatrice2()->text().toDouble())){
        showMessageBox("Matrice 2 scalare",QString("La matrice 2 e' scalare."));
        aggiornaLabelRisultato(QString("La matrice 2 e' scalare."));
    }else{
        showMessageBox("Matrice 2 scalare",QString("La matrice 2 non e' scalare."));
        aggiornaLabelRisultato(QString("La matrice 2 non e' scalare."));
    }
}

MatriciController::~MatriciController(){
    delete matrice1;
    delete matrice2;
    delete matriceRisultato;
}
