#include "librettoesamicontroller.h"

LibrettoEsamiController::LibrettoEsamiController(LibrettoEsamiGUI* g):
    guiLibretto(g), libretto1(new LibrettoEsami()), libretto2(new LibrettoEsami())
{

    connect(guiLibretto,SIGNAL(btnAggiungiEsameClicked1()),this,SLOT(aggiungiEsameLibretto1()));
    connect(guiLibretto,SIGNAL(btnAggiungiEsameClicked2()),this,SLOT(aggiungiEsameLibretto2()));
    connect(guiLibretto,SIGNAL(btnRimuoviEsameClicked1()),this,SLOT(rimuoviEsameLibretto1()));
    connect(guiLibretto,SIGNAL(btnRimuoviEsameClicked2()),this,SLOT(rimuoviEsameLibretto2()));

    connect(guiLibretto,SIGNAL(btnAggiungiLibretto1AdLibretto2Clicked()),this,SLOT(aggiungiLibretto1AdLibretto2()));
    connect(guiLibretto,SIGNAL(btnAggiungiLibretto2AdLibretto1Clicked()),this,SLOT(aggiungiLibretto2AdLibretto1()));
    connect(guiLibretto,SIGNAL(btnRimuoviLibretto1DaLibretto2Clicked()),this,SLOT(rimuoviLibretto1DalLibretto2()));
    connect(guiLibretto,SIGNAL(btnRimuoviLibretto2DaLibretto1Clicked()),this,SLOT(rimuoviLibretto2DalLibretto1()));

    connect(guiLibretto,SIGNAL(btnEsameMenoRecenteClicked1()),this,SLOT(esameMenoReceneteLibretto1()));
    connect(guiLibretto,SIGNAL(btnEsameMenoRecenteClicked2()),this,SLOT(esameMenoReceneteLibretto2()));
    connect(guiLibretto,SIGNAL(btnEsameMiglioreClicked1()),this,SLOT(esameMiglioreLibretto1()));
    connect(guiLibretto,SIGNAL(btnEsameMiglioreClicked2()),this,SLOT(esameMiglioreLibretto2()));
    connect(guiLibretto,SIGNAL(btnEsamePeggioreClicked1()),this,SLOT(esamePeggioreLibretto1()));
    connect(guiLibretto,SIGNAL(btnEsamePeggioreClicked2()),this,SLOT(esamePeggioreLibretto2()));
    connect(guiLibretto,SIGNAL(btnEsamePiuRecenteClicked1()),this,SLOT(esamePiuRecenteLibretto1()));
    connect(guiLibretto,SIGNAL(btnEsamePiuRecenteClicked2()),this,SLOT(esamePiuRecenteLibretto2()));

    connect(guiLibretto,SIGNAL(cognomeStudente1Changed()),this,SLOT(aggiornaCognomeStudente1()));
    connect(guiLibretto,SIGNAL(cognomeStudente2Changed()),this,SLOT(aggiornaCognomeStudente2()));
    connect(guiLibretto,SIGNAL(nomeStudente1Changed()),this,SLOT(aggiornaNomeStudente1()));
    connect(guiLibretto,SIGNAL(nomeStudente2Changed()),this,SLOT(aggiornaNomeStudente2()));
    connect(guiLibretto,SIGNAL(matricolaStudente1Changed()),this,SLOT(aggiornaMatricolaStudente1()));
    connect(guiLibretto,SIGNAL(matricolaStudente2Changed()),this,SLOT(aggiornaMatricolaStudente2()));

    connect(guiLibretto,SIGNAL(btnCFURimanentiClicked1()),this,SLOT(mostraCFURimanenti1()));
    connect(guiLibretto,SIGNAL(btnTargetCFUClicked1()),this,SLOT(mostraTargetCFU1()));
    connect(guiLibretto,SIGNAL(btnTotalCFUClicked1()),this,SLOT(mostraTotalCFU1()));
    connect(guiLibretto,SIGNAL(btnMediaAritmeticaClicked1()),this,SLOT(mostraMediaAritmetica1()));
    connect(guiLibretto,SIGNAL(btnMediaPonderataClicked1()),this,SLOT(mostraMediaPonderata1()));
    connect(guiLibretto,SIGNAL(btnPercentualeCompletamentoClicked1()),this,SLOT(mostraPercentualeCompletamento1()));
    connect(guiLibretto,SIGNAL(btnPrevisioneVotoClicked1()),this,SLOT(mostraPrevisioneVoto1()));
    connect(guiLibretto,SIGNAL(btnNumEsamiSostenutiClicked1()),this,SLOT(mostraNumEsamiFatti1()));

    connect(guiLibretto,SIGNAL(btnCFURimanentiClicked2()),this,SLOT(mostraCFURimanenti2()));
    connect(guiLibretto,SIGNAL(btnTargetCFUClicked2()),this,SLOT(mostraTargetCFU2()));
    connect(guiLibretto,SIGNAL(btnTotalCFUClicked2()),this,SLOT(mostraTotalCFU2()));
    connect(guiLibretto,SIGNAL(btnMediaAritmeticaClicked2()),this,SLOT(mostraMediaAritmetica2()));
    connect(guiLibretto,SIGNAL(btnMediaPonderataClicked2()),this,SLOT(mostraMediaPonderata2()));
    connect(guiLibretto,SIGNAL(btnPercentualeCompletamentoClicked2()),this,SLOT(mostraPercentualeCompletamento2()));
    connect(guiLibretto,SIGNAL(btnPrevisioneVotoClicked2()),this,SLOT(mostraPrevisioneVoto2()));
    connect(guiLibretto,SIGNAL(btnNumEsamiSostenutiClicked2()),this,SLOT(mostraNumEsamiFatti2()));

    connect(guiLibretto,SIGNAL(targetCFU1Changed()),this,SLOT(aggiornaTargetCFU1()));
    connect(guiLibretto,SIGNAL(targetCFU2Changed()),this,SLOT(aggiornaTargetCFU2()));


    aggiornaCognomeStudente1();
    aggiornaCognomeStudente2();
    aggiornaMatricolaStudente1();
    aggiornaMatricolaStudente2();
    aggiornaNomeStudente1();
    aggiornaNomeStudente2();
}

void LibrettoEsamiController::showMessageBox(QString title,QString text) const{
    QMessageBox msgBox;
    msgBox.setWindowTitle(title);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setFont(QFont("Verdana",14));

    msgBox.setText(text);
    msgBox.exec();
}

void LibrettoEsamiController::aggiornaLibrettoGUI(LibrettoEsami * lE, QPlainTextEdit * pT){
    pT->setPlainText(lE->getRappresentazioneStringa().c_str());
}

void LibrettoEsamiController::aggiornaCognomeStudente1(){
    libretto1->setCognomeStudente(guiLibretto->getCognomeStudente1().toStdString());
    aggiornaLibrettoGUI(libretto1,guiLibretto->getLibretto1Viewer()->getPlainTextEdit());
}

void LibrettoEsamiController::aggiornaNomeStudente1(){
    libretto1->setNomeStudente(guiLibretto->getNomeStudente1().toStdString());
    aggiornaLibrettoGUI(libretto1,guiLibretto->getLibretto1Viewer()->getPlainTextEdit());
}

void LibrettoEsamiController::aggiornaMatricolaStudente1(){
    libretto1->setMatricola(guiLibretto->getMatricolaStudente1().toUInt());
    aggiornaLibrettoGUI(libretto1,guiLibretto->getLibretto1Viewer()->getPlainTextEdit());
}

void LibrettoEsamiController::aggiornaCognomeStudente2(){
    libretto2->setCognomeStudente(guiLibretto->getCognomeStudente2().toStdString());
    aggiornaLibrettoGUI(libretto2,guiLibretto->getLibretto2Viewer()->getPlainTextEdit());
}

void LibrettoEsamiController::aggiornaNomeStudente2(){
    libretto2->setNomeStudente(guiLibretto->getNomeStudente2().toStdString());
    aggiornaLibrettoGUI(libretto2,guiLibretto->getLibretto2Viewer()->getPlainTextEdit());
}

void LibrettoEsamiController::aggiornaMatricolaStudente2(){
    libretto2->setMatricola(guiLibretto->getMatricolaStudente2().toUInt());
    aggiornaLibrettoGUI(libretto2,guiLibretto->getLibretto2Viewer()->getPlainTextEdit());
}

void LibrettoEsamiController::aggiungiEsameLibretto1(){
    if(guiLibretto->getEsameDialog()->result() == QDialog::Accepted){
        EsameDialog* eD = guiLibretto->getEsameDialog();
        Data d(eD->getSpinBoxGiorno()->text().toInt(),
               eD->getSpinBoxMese()->text().toInt(),
               eD->getSpinBoxAnno()->text().toInt());
        esame = Esame(eD->getLineEditMateria()->text().toStdString(),
                          eD->getLineEditCorso()->text().toStdString(),
                          eD->getLineEditProfessore()->text().toStdString(),
                          d,
                          eD->getSpinBoxCFU()->text().toInt(),
                          eD->getSpinBoxVoto()->text().toInt()
                          );
        libretto1 = *libretto1 + esame;
        aggiornaLibrettoGUI(libretto1,guiLibretto->getLibretto1Viewer()->getPlainTextEdit());
    }
}

void LibrettoEsamiController::aggiungiEsameLibretto2(){
    if(guiLibretto->getEsameDialog()->result() == QDialog::Accepted){
        EsameDialog* eD = guiLibretto->getEsameDialog();
        Data d(eD->getSpinBoxGiorno()->text().toInt(),
               eD->getSpinBoxMese()->text().toInt(),
               eD->getSpinBoxAnno()->text().toInt());
        esame = Esame(eD->getLineEditMateria()->text().toStdString(),
                          eD->getLineEditCorso()->text().toStdString(),
                          eD->getLineEditProfessore()->text().toStdString(),
                          d,
                          eD->getSpinBoxCFU()->text().toInt(),
                          eD->getSpinBoxVoto()->text().toInt()
                          );
        libretto2 = *libretto2 + esame;
        aggiornaLibrettoGUI(libretto2,guiLibretto->getLibretto2Viewer()->getPlainTextEdit());
    }
}

void LibrettoEsamiController::rimuoviEsameLibretto1(){
    if(guiLibretto->getEsameDialog()->result() == QDialog::Accepted){
        EsameDialog* eD = guiLibretto->getEsameDialog();
        Data d(eD->getSpinBoxGiorno()->text().toInt(),
               eD->getSpinBoxMese()->text().toInt(),
               eD->getSpinBoxAnno()->text().toInt());
        esame = Esame(eD->getLineEditMateria()->text().toStdString(),
                          eD->getLineEditCorso()->text().toStdString(),
                          eD->getLineEditProfessore()->text().toStdString(),
                          d,
                          eD->getSpinBoxCFU()->text().toInt(),
                          eD->getSpinBoxVoto()->text().toInt()
                          );
        libretto1 = *libretto1 - esame;
        aggiornaLibrettoGUI(libretto1,guiLibretto->getLibretto1Viewer()->getPlainTextEdit());
    }
}

void LibrettoEsamiController::rimuoviEsameLibretto2(){
    if(guiLibretto->getEsameDialog()->result() == QDialog::Accepted){
        EsameDialog* eD = guiLibretto->getEsameDialog();
        Data d(eD->getSpinBoxGiorno()->text().toInt(),
               eD->getSpinBoxMese()->text().toInt(),
               eD->getSpinBoxAnno()->text().toInt());
        esame = Esame(eD->getLineEditMateria()->text().toStdString(),
                          eD->getLineEditCorso()->text().toStdString(),
                          eD->getLineEditProfessore()->text().toStdString(),
                          d,
                          eD->getSpinBoxCFU()->text().toInt(),
                          eD->getSpinBoxVoto()->text().toInt()
                          );
        libretto2 = *libretto2 - esame;
        aggiornaLibrettoGUI(libretto2,guiLibretto->getLibretto2Viewer()->getPlainTextEdit());
    }
}

void LibrettoEsamiController::aggiungiLibretto1AdLibretto2(){
    *libretto2 += *libretto1;
    aggiornaLibrettoGUI(libretto2,guiLibretto->getLibretto2Viewer()->getPlainTextEdit());
}

void LibrettoEsamiController::aggiungiLibretto2AdLibretto1(){
    *libretto1 += *libretto2;
    aggiornaLibrettoGUI(libretto1,guiLibretto->getLibretto1Viewer()->getPlainTextEdit());
}

void LibrettoEsamiController::rimuoviLibretto1DalLibretto2(){
    *libretto2 -= *libretto1;
    aggiornaLibrettoGUI(libretto2,guiLibretto->getLibretto2Viewer()->getPlainTextEdit());
}

void LibrettoEsamiController::rimuoviLibretto2DalLibretto1(){
    *libretto1 -= *libretto2;
    aggiornaLibrettoGUI(libretto1,guiLibretto->getLibretto1Viewer()->getPlainTextEdit());
}

void LibrettoEsamiController::esameMenoReceneteLibretto1(){
    Esame* tmp = libretto1->esameMenoRecente();
    if(tmp){
        QString s = libretto1->getInfoStudente().c_str();
        s += "\n - Esame meno recente - \n";
        s += (tmp->getRappresentazioneStringa().c_str());
        showMessageBox("Esame meno recente libretto 1",s);
    }else{
        showMessageBox("Errore","Operazione non disponibile.");
    }
}

void LibrettoEsamiController::esameMenoReceneteLibretto2(){
    Esame* tmp = libretto2->esameMenoRecente();
    if(tmp){
        QString s = libretto2->getInfoStudente().c_str();
        s += "\n - Esame meno recente - \n";
        s += (tmp->getRappresentazioneStringa().c_str());
        showMessageBox("Esame meno recente libretto 2",s);
    }else{
        showMessageBox("Errore","Operazione non disponibile.");
    }
}

void LibrettoEsamiController::esamePiuRecenteLibretto1(){
    Esame* tmp = libretto1->esamePiuRecente();
    if(tmp){
        QString s = libretto1->getInfoStudente().c_str();
        s += "\n - Esame piu recente - \n";
        s += (tmp->getRappresentazioneStringa().c_str());
        showMessageBox("Esame piu recente libretto 1",s);
    }else{
        showMessageBox("Errore","Operazione non disponibile.");
    }
}

void LibrettoEsamiController::esamePiuRecenteLibretto2(){
    Esame* tmp = libretto2->esamePiuRecente();
    if(tmp){
        QString s = libretto2->getInfoStudente().c_str();
        s += "\n - Esame piu recente - \n";
        s += (tmp->getRappresentazioneStringa().c_str());
        showMessageBox("Esame piu recente libretto 2",s);
    }else{
        showMessageBox("Errore","Operazione non disponibile.");
    }
}

void LibrettoEsamiController::esameMiglioreLibretto1(){
    Esame* tmp = libretto1->esameMigliore();
    if(tmp){
        QString s = libretto1->getInfoStudente().c_str();
        s += "\n - Esame migliore - \n";
        s += (tmp->getRappresentazioneStringa().c_str());
        showMessageBox("Esame migliore libretto 1",s);
    }else{
        showMessageBox("Errore","Operazione non disponibile.");
    }
}

void LibrettoEsamiController::esamePeggioreLibretto1(){
    Esame* tmp = libretto1->esamePeggiore();
    if(tmp){
        QString s = libretto1->getInfoStudente().c_str();
        s += "\n - Esame peggiore - \n";
        s += (tmp->getRappresentazioneStringa().c_str());
        showMessageBox("Esame peggiore libretto 1",s);
    }else{
        showMessageBox("Errore","Operazione non disponibile.");
    }
}

void LibrettoEsamiController::esamePeggioreLibretto2(){
    Esame* tmp = libretto2->esamePeggiore();
    if(tmp){
        QString s = libretto2->getInfoStudente().c_str();
        s += "\n - Esame peggiore - \n";
        s += (tmp->getRappresentazioneStringa().c_str());
        showMessageBox("Esame peggiore libretto 2",s);
    }else{
        showMessageBox("Errore","Operazione non disponibile.");
    }
}

void LibrettoEsamiController::esameMiglioreLibretto2(){
    Esame* tmp = libretto2->esameMigliore();
    if(tmp){
        QString s = libretto2->getInfoStudente().c_str();
        s += "\n - Esame migliore - \n";
        s += tmp->getRappresentazioneStringa().c_str();
        showMessageBox("Esame migliore libretto 2",s);
    }else{
        showMessageBox("Errore","Operazione non disponibile.");
    }
}

void LibrettoEsamiController::aggiornaTargetCFU1(){
    delete libretto1;
    libretto1 = new LibrettoEsami(guiLibretto->getNomeStudente1().toStdString(),
                                  guiLibretto->getCognomeStudente1().toStdString(),
                                  guiLibretto->getMatricolaStudente1().toUInt(),
                                  guiLibretto->getTargetCFU1()
                                  );
    aggiornaLibrettoGUI(libretto1,guiLibretto->getLibretto1Viewer()->getPlainTextEdit());
}

void LibrettoEsamiController::aggiornaTargetCFU2(){
    delete libretto2;
    libretto2 = new LibrettoEsami(guiLibretto->getNomeStudente2().toStdString(),
                                  guiLibretto->getCognomeStudente2().toStdString(),
                                  guiLibretto->getMatricolaStudente2().toUInt(),
                                  guiLibretto->getTargetCFU2()
                                  );
    aggiornaLibrettoGUI(libretto2,guiLibretto->getLibretto2Viewer()->getPlainTextEdit());
}

void LibrettoEsamiController::mostraTargetCFU1(){
    QString s = libretto1->getInfoStudente().c_str();
    s += "\n\n - Target CFU - \n";
    s += to_string(libretto1->getTargetCFU()).c_str();
    showMessageBox("Target CFU libretto 1",s);
}

void LibrettoEsamiController::mostraTotalCFU1(){
    QString s = libretto1->getInfoStudente().c_str();
    s += "\n\n - Totale CFU - \n";
    s += to_string(libretto1->getTotaleCFU()).c_str();
    showMessageBox("Totale CFU libretto 1",s);
}

void LibrettoEsamiController::mostraNumEsamiFatti1(){
    QString s = libretto1->getInfoStudente().c_str();
    s += "\n\n - Numero esami sostenuti - \n";
    s += to_string(libretto1->getSize()).c_str();
    showMessageBox("Numero esami sostenuti libretto 1",s);
}

void LibrettoEsamiController::mostraMediaAritmetica1(){
    QString s = libretto1->getInfoStudente().c_str();
    s += "\n\n - Media aritmetica - \n";
    s += to_string(libretto1->mediaAritmetica()).c_str();
    showMessageBox("Media aritmetica libretto 1",s);
}

void LibrettoEsamiController::mostraMediaPonderata1(){
    QString s = libretto1->getInfoStudente().c_str();
    s += "\n\n - Media ponderata - \n";
    s += to_string(libretto1->mediaPonderata()).c_str();
    showMessageBox("Media ponderata libretto 1",s);
}

void LibrettoEsamiController::mostraPrevisioneVoto1(){
    QString s = libretto1->getInfoStudente().c_str();
    s += "\n\n - Voto laurea - \n";
    s += to_string(libretto1->previsioneVotoLaurea()).c_str();
    showMessageBox("Voto laurea libretto 1",s);
}

void LibrettoEsamiController::mostraPercentualeCompletamento1(){
    QString s = libretto1->getInfoStudente().c_str();
    s += "\n\n - Percentuale completamento - \n";
    s += to_string(libretto1->percentualeCompletamento()).c_str();
    s+=" %";
    showMessageBox("Percentuale completamento libretto 1",s);
}

void LibrettoEsamiController::mostraCFURimanenti1(){
    QString s = libretto1->getInfoStudente().c_str();
    s += "\n\n - CFU rimanenti - \n";
    s += to_string(libretto1->rimanentiCFU()).c_str();
    showMessageBox("CFU rimanenti libretto 1",s);
}


void LibrettoEsamiController::mostraTargetCFU2(){
    QString s = libretto2->getInfoStudente().c_str();
    s += "\n\n - Target CFU - \n";
    s += to_string(libretto2->getTargetCFU()).c_str();
    showMessageBox("Target CFU libretto 2",s);
}

void LibrettoEsamiController::mostraTotalCFU2(){
    QString s = libretto2->getInfoStudente().c_str();
    s += "\n\n - Totale CFU - \n";
    s += to_string(libretto2->getTotaleCFU()).c_str();
    showMessageBox("Totale CFU libretto 2",s);
}

void LibrettoEsamiController::mostraNumEsamiFatti2(){
    QString s = libretto2->getInfoStudente().c_str();
    s += "\n\n - Numero esami sostenuti - \n";
    s += to_string(libretto2->getSize()).c_str();
    showMessageBox("Numero esami sostenuti libretto 2",s);
}

void LibrettoEsamiController::mostraMediaAritmetica2(){
    QString s = libretto2->getInfoStudente().c_str();
    s += "\n\n - Media aritmetica - \n";
    s += to_string(libretto2->mediaAritmetica()).c_str();
    showMessageBox("Media aritmetica libretto 2",s);
}

void LibrettoEsamiController::mostraMediaPonderata2(){
    QString s = libretto2->getInfoStudente().c_str();
    s += "\n\n - Media ponderata - \n";
    s += to_string(libretto2->mediaPonderata()).c_str();
    showMessageBox("Media ponderata libretto 2",s);
}

void LibrettoEsamiController::mostraPrevisioneVoto2(){
    QString s = libretto2->getInfoStudente().c_str();
    s += "\n\n - Voto laurea - \n";
    s += to_string(libretto2->previsioneVotoLaurea()).c_str();
    showMessageBox("Voto laurea libretto 2",s);
}

void LibrettoEsamiController::mostraPercentualeCompletamento2(){
    QString s = libretto2->getInfoStudente().c_str();
    s += "\n\n - Percentuale completamento - \n";
    s += to_string(libretto2->percentualeCompletamento()).c_str();
    s+=" %";
    showMessageBox("Percentuale completamento libretto 2",s);
}

void LibrettoEsamiController::mostraCFURimanenti2(){
    QString s = libretto2->getInfoStudente().c_str();
    s += "\n\n - CFU rimanenti - \n";
    s += to_string(libretto2->rimanentiCFU()).c_str();
    showMessageBox("CFU rimanenti libretto 2",s);
}

LibrettoEsamiController::~LibrettoEsamiController(){
    delete libretto1;
    delete libretto2;
}
