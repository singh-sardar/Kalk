#include "colorcontroller.h"
#include <QMessageBox>
ColorController::ColorController(RgbColorGui* v):view(v),model1(new ColoreRgb()),model2(new ColoreRgb()),result(new ColoreRgb())
{
    connect(view,SIGNAL(btnSaveOperando1Clicked(bool)),this,SLOT(SaveOperando1()));
    connect(view,SIGNAL(btnSaveOperando2Clicked(bool)),this,SLOT(SaveOperando2()));
    connect(view,SIGNAL(btnSommaClicked(bool)),this,SLOT(SommaColori()));
    connect(view,SIGNAL(btnSommaClicked(bool)),this,SLOT(ChangeResultColor()));
    connect(view,SIGNAL(btnDifferenzaClicked(bool)),this,SLOT(DifferenzaColori()));
    connect(view,SIGNAL(btnDifferenzaClicked(bool)),this,SLOT(ChangeResultColor()));
    connect(view,SIGNAL(btnModulazioneClicked(bool)),this,SLOT(ModulazioneColori()));
    connect(view,SIGNAL(btnModulazioneClicked(bool)),this,SLOT(ChangeResultColor()));
    connect(view,SIGNAL(btnDeltaEClicked(bool)),this,SLOT(DeltaEColori()));
    connect(view,SIGNAL(btnDeltaEClicked(bool)),this,SLOT(ChangeResultColor()));
    connect(view,SIGNAL(btnLabClicked(bool)),this,SLOT(LabColore()));
    connect(view,SIGNAL(btnHslClicked(bool)),this,SLOT(HslColore()));
    connect(view,SIGNAL(btnHexClicked(bool)),this,SLOT(HexColore()));
     connect(view,SIGNAL(btnCaldoClicked(bool)),this,SLOT(CaldoColore()));
     connect(view,SIGNAL(btnComplementareClicked(bool)),this,SLOT(ComplementareColore()));
     connect(view,SIGNAL(btnComplementareClicked(bool)),this,SLOT(ChangeResultColor()));
    connect(view,SIGNAL(btnLuminositaClicked(bool)),this,SLOT(LuminositaColore()));

}
void ColorController::SommaColori(){
    result =  *model1+ *model2;
}


void ColorController::SaveOperando1(){
    model1->setR(view->getColor1Rvalue());
    model1->setG(view->getColor1Gvalue());
    model1->setB(view->getColor1Bvalue());


    QColor* c = new QColor;
    QPalette p= view->getOperand1Viewer()->palette();

    c->setRgb(model1->getR(),model1->getG(),model1->getB());
    p.setColor(QPalette::Window,*c);
    view->getOperand1Viewer()->setPalette(p);
}

void ColorController::SaveOperando2(){

    model2->setR(view->getColor2Rvalue());
    model2->setG(view->getColor2Gvalue());
    model2->setB(view->getColor2Bvalue());


    QColor* c = new QColor;
    QPalette p= view->getOperand2Viewer()->palette();

    c->setRgb(model2->getR(),model2->getG(),model2->getB());
    p.setColor(QPalette::Window,*c);
    view->getOperand2Viewer()->setPalette(p);
}
void ColorController::showMessageBox(QString title,QString text){
    QMessageBox msgBox;
    msgBox.setWindowTitle(title);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setFont(QFont("Verdana",14));

    msgBox.setText(text);
    msgBox.exec();
}

void ColorController::ChangeResultColor(){
    updateOneOperandResult(result->schemaColore().c_str());
}
void ColorController::updateOneOperandResult(QString s){
    QColor* c = new QColor;
    QPalette p= view->getResultViewer()->palette();

    c->setRgb(result->getR(),result->getG(),result->getB());
    p.setColor(QPalette::Window,*c);
    view->getResultViewer()->setPalette(p);
    view->getResultLabel()->setText(s);
}















void ColorController::DifferenzaColori(){
    result = *model1 - *model2;
}
void ColorController::ModulazioneColori(){
    result = *model1 * *model2;
}
void ColorController::DeltaEColori(){

    QString s= "I due colori differisco di ";
    s+=to_string(model1->DeltaE(*model2)).c_str();
    s+=" %";
    showMessageBox("DELTA E Cie76 ",s);

}

void ColorController::ComplementareColore(){
    result = model1->complementare();
}
void ColorController::LuminositaColore(){
    result = model1->luminositaColore();
    if(result->getR()<130)
        showMessageBox("Luminosità colore","L'operando 1 è un colore SCURO.\n Per cui ti conviene mettere il testo in sovraimpressione in BIANCO");
    else
        showMessageBox("Luminosità colore","L'operando 1 è un colore CHIARO.\n Per cui ti conviene mettere il testo in sovraimpressione in NERO");

    QString s= "Luminosita Colore ";
    s+= result->schemaColore().c_str();

    updateOneOperandResult(s);
}
void ColorController::CaldoColore(){
    QString s="Il colore ";
    s+=model1->schemaColore().c_str();
    s+= " è ";
    if(model1->coloreCaldo())
        s+="un colore caldo.";
    else
        s+="un colore freddo";

    showMessageBox("Colore Caldo/Freddo",s);
    result= model1;
    updateOneOperandResult(s);


}
void ColorController::LabColore(){
    double LAB[3];
    model1->rgb2lab(LAB);
    QString s= model1->schemaColore().c_str();
    s+=" ==> LAB(";
    s+=to_string(LAB[0]).c_str();
    s+=",";
    s+=to_string(LAB[1]).c_str();
    s+=",";
    s+=to_string(LAB[2]).c_str();
    s+=")";
    showMessageBox("Rappresentazione LAB",s);
    result= model1;
    updateOneOperandResult(s);

}
void ColorController::HslColore(){
    double HSL[3];
    model1->rgb2hsl(HSL);
    QString s= model1->schemaColore().c_str();
    s+=" ==> HSL(";
    s+=to_string(HSL[0]).c_str();
    s+=",";
    s+=to_string(HSL[1]).c_str();
    s+=",";
    s+=to_string(HSL[2]).c_str();
    s+=")";
    showMessageBox("Rappresentazione HSL",s);
    result= model1;
    updateOneOperandResult(s);


}
void ColorController::HexColore(){
    QString s= model1->schemaColore().c_str();
    s+=" ==> HEX(";
    s+=model1->rgb2hex().c_str();
    s+=")";
    showMessageBox("Rappresentazione HEX",s);
    result= model1;
    updateOneOperandResult(s);
}
void ColorController::Hsl2RgbColore(){}
void ColorController::ScalaColore(){}
