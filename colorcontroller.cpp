#include "colorcontroller.h"
#include <QMessageBox>
ColorController::ColorController(ColorGui* v):view(v),model1(new ColoreRgb()),model2(new ColoreRgb()),result(new ColoreRgb())
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
    connect(view,SIGNAL(btnComplementareClicked(bool)),this,SLOT(ComplementareColore()));
    connect(view,SIGNAL(btnComplementareClicked(bool)),this,SLOT(ChangeResultColor()));
    connect(view,SIGNAL(btnLuminositaClicked(bool)),this,SLOT(LuminositaColore()));
    connect(view,SIGNAL(btnCaldoClicked(bool)),this,SLOT(CaldoColore()));
    connect(view,SIGNAL(btnLabClicked(bool)),this,SLOT(LabColore()));
    connect(view,SIGNAL(btnHslClicked(bool)),this,SLOT(HslColore()));
    connect(view,SIGNAL(btnHexClicked(bool)),this,SLOT(HexColore()));
    connect(view,SIGNAL(btnScalaClicked(bool)),this,SLOT(ScalaColore()));
    connect(view,SIGNAL(btnScalaClicked(bool)),this,SLOT(ChangeResultColor()));
    connect(view,SIGNAL(btnHsl2RgbClicked(bool)),this,SLOT(Hsl2RgbColore()));
    connect(view,SIGNAL(btnHsl2RgbClicked(bool)),this,SLOT(ChangeResultColor()));
    connect(view,SIGNAL(btnUseResultAsOperandoClicked(bool)),this,SLOT(ResultAsOperando()));

    connect(view,SIGNAL(btnRgb2HslClicked(bool)),this,SLOT(Rgb2HslColore()));
    connect(view,SIGNAL(btnRgb2HslClicked(bool)),this,SLOT(ChangeResultColor()));

    connect(view,SIGNAL(colorTypeChanged()),this,SLOT(ChangeColorType()));

    //view->getOperationButtons()->removeRGBSpin();
    //ChangeColorType();

}
ColorController::~ColorController(){

    if(result == model1 || result == model2){
        delete model1;
        delete model2;
    }else
    {
        delete model1;
        delete model2;
        delete result;
    }

}
void ColorController::SommaColori(){
    result =  *model1+ *model2;
}


void ColorController::SaveOperando1(){
    QColor c;
    QPalette p= view->getOperand1Viewer()->palette();

    if(typeid(*model1) == typeid(ColoreRgb)){
        ColoreRgb* colRGB = dynamic_cast<ColoreRgb*>(model1);
        model1 = colRGB;
        colRGB->setR(view->getColor1P1value());
        colRGB->setG(view->getColor1P2value());
        colRGB->setB(view->getColor1P3value());
        c.setRgb(colRGB->getR(),colRGB->getG(),colRGB->getB());
    }else if(typeid(*model1) == typeid(ColoreHsl)){
        ColoreHsl* colHSL = dynamic_cast<ColoreHsl*>(model1);
        model1 = colHSL;
        colHSL->setH(view->getColor1P1value());
        colHSL->setS(view->getColor1P2value());
        colHSL->setL(view->getColor1P3value());
        c.setHsl(colHSL->getH(),colHSL->getS()*2.55,colHSL->getL()*2.55);
    }else if(typeid(*model1) == typeid(ColoreRgba)){
        ColoreRgba* colRgba = dynamic_cast<ColoreRgba*>(model1);
        model1 = colRgba;
        colRgba->setR(view->getColor1P1value());
        colRgba->setG(view->getColor1P2value());
        colRgba->setB(view->getColor1P3value());
        colRgba->setA(static_cast<float>(dynamic_cast<RgbaPicker*>(view->getColorPicker()->getColor1())->getAlphaValue())/255);
        c.setRgb(colRgba->getR(),colRgba->getG(),colRgba->getB(),static_cast<int>(colRgba->getA()*255));
    }
    /*
    model1->setR(view->getColor1Rvalue());
    model1->setG(view->getColor1Gvalue());
    model1->setB(view->getColor1Bvalue());
    */


    p.setColor(QPalette::Window,c);
    view->getOperand1Viewer()->setPalette(p);
}

void ColorController::SaveOperando2(){
    QColor c;
    QPalette p= view->getOperand2Viewer()->palette();

    if(typeid(*model2) == typeid(ColoreRgb)){
        ColoreRgb* colRGB = dynamic_cast<ColoreRgb*>(model2);
        model2 = colRGB;
        colRGB->setR(view->getColor2P1value());
        colRGB->setG(view->getColor2P2value());
        colRGB->setB(view->getColor2P3value());
        c.setRgb(colRGB->getR(),colRGB->getG(),colRGB->getB());
    }else if(typeid(*model2) == typeid(ColoreHsl)){
        ColoreHsl* colHSL = dynamic_cast<ColoreHsl*>(model2);
        model2 = colHSL;
        colHSL->setH(view->getColor2P1value());
        colHSL->setS(view->getColor2P2value());
        colHSL->setL(view->getColor2P3value());
        c.setHsl(colHSL->getH(),colHSL->getS()*2.55,colHSL->getL()*2.55);
    }else if(typeid(*model2) == typeid(ColoreRgba)){
        ColoreRgba* colRgba = dynamic_cast<ColoreRgba*>(model2);
        model2 = colRgba;
        colRgba->setR(view->getColor2P1value());
        colRgba->setG(view->getColor2P2value());
        colRgba->setB(view->getColor2P3value());
        colRgba->setA(static_cast<float>(dynamic_cast<RgbaPicker*>(view->getColorPicker()->getColor2())->getAlphaValue())/255);
        c.setRgb(colRgba->getR(),colRgba->getG(),colRgba->getB(),static_cast<int>(colRgba->getA()*255));
    }
    /*
    model2->setR(view->getColor2Rvalue());
    model2->setG(view->getColor2Gvalue());
    model2->setB(view->getColor2Bvalue());
    */

    p.setColor(QPalette::Window,c);
    view->getOperand2Viewer()->setPalette(p);
}
void ColorController::showMessageBox(QString title,QString text)const{
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
    QColor c;
    QPalette p= view->getResultViewer()->palette();

    if(typeid(*result) == typeid(ColoreRgb)){
        ColoreRgb* temp = dynamic_cast<ColoreRgb*>(result);
        c.setRgb(temp->getR(),temp->getG(),temp->getB());
    }else if(typeid(*result) == typeid(ColoreRgba)){
        ColoreRgba* temp = dynamic_cast<ColoreRgba*>(result);
        c.setRgb(temp->getR(),temp->getG(),temp->getB(),static_cast<int>(temp->getA()*255));
    }else if(typeid(*result) == typeid(ColoreHsl)){
        ColoreHsl* temp = dynamic_cast<ColoreHsl*>(result);
        c.setHsl(temp->getH(),temp->getS(),temp->getL());
    }

    p.setColor(QPalette::Window,c);
    view->getResultViewer()->setPalette(p);
    view->getResultLabel()->setText(s);
}
void ColorController::ResultAsOperando(){
    //*model1 = *result;
    model1 = result;
    QColor c;
    QPalette p= view->getOperand1Viewer()->palette();

    if(typeid(*model1) == typeid(ColoreRgb)){
        ColoreRgb* temp = dynamic_cast<ColoreRgb*>(model1);
        c.setRgb(temp->getR(),temp->getG(),temp->getB());
    }else if(typeid(*model1) == typeid(ColoreRgba)){
        ColoreRgba* temp=dynamic_cast<ColoreRgba*>(model1);
        c.setRgb(temp->getR(),temp->getG(),temp->getB(),static_cast<int>(temp->getA()*255));
    }else if(typeid(*model1) == typeid(ColoreHsl)){
        ColoreHsl* temp = dynamic_cast<ColoreHsl*>(model1);
        c.setHsl(temp->getH(),temp->getS(),temp->getL());
    }

    //c.setRgb(model1->getR(),model1->getG(),model1->getB());
    p.setColor(QPalette::Window,c);
    view->getOperand1Viewer()->setPalette(p);
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
    result = model1->grayScale();
    if(result->getLuminosita()<51)
        showMessageBox("Luminosita colore","L'operando 1 e' un colore SCURO.\n Per cui ti conviene mettere il testo in sovraimpressione in BIANCO");
    else
        showMessageBox("Luminosita colore","L'operando 1 e' un colore CHIARO.\n Per cui ti conviene mettere il testo in sovraimpressione in NERO");

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
   // model1->rgb2lab(LAB);
    model1->ToLab(LAB);
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
   // model1->rgb2hsl(HSL);
    if(dynamic_cast<ColoreRgb*>(model1)){
        ColoreRgb* temp = dynamic_cast<ColoreRgb*>(model1);
        temp->ToHsl(HSL);
    }
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
   // s+=model1->rgb2hex().c_str();
    s+=model1->ToHex().c_str();
    s+=")";
    showMessageBox("Rappresentazione HEX",s);
    result= model1;
    updateOneOperandResult(s);
}
void ColorController::Hsl2RgbColore(){
    double HSL[3];
    HSL[0] = view->getHValue();
    HSL[1] = view->getSValue();
    HSL[2] = view->getLValue();
    int RGB[3];
    Colore::hsl2rgb(HSL,RGB);

    if(dynamic_cast<ColoreRgb*>(model1)){
        delete result;
        result = new ColoreRgb;
        ColoreRgb* t = dynamic_cast<ColoreRgb*>(result);
        t->modificaColore(RGB[0],RGB[1],RGB[2]);
    }

}
void ColorController::ScalaColore(){
    result = *model1 * view->getFattoreScalaValue();
}


void ColorController::Rgb2HslColore(){
    int RGB[3];
    RGB[0] = view->getRValue();
    RGB[1] = view->getGValue();
    RGB[2] = view->getBValue();

    double HSL[3];
    Colore::rgb2hsl(RGB,HSL);

    if(dynamic_cast<ColoreHsl*>(model1)){
        delete result;
        result = new ColoreHsl;
        ColoreHsl* t = dynamic_cast<ColoreHsl*>(result);
        t->modificaColore(HSL[0],HSL[1],HSL[2]);
    }
}

void ColorController::ChangeColorType(){
    if(model1)
        delete model1;
    if(model2)
        delete model2;

    if(typeid(*(view->getColorPicker()->getColor1())) == typeid(RgbPicker)){

        model1 = new ColoreRgb;
        model2 = new ColoreRgb;

        //view->getOperationButtons()->removeRgb2Hsl();
        view->getOperationButtons()->addHsl2Rgb();

    }else if(typeid(*(view->getColorPicker()->getColor1())) == typeid(HslPicker)){

        model1 = new ColoreHsl;
        model2 = new ColoreHsl;

        //view->getOperationButtons()->removeHsl2Rgb();
        view->getOperationButtons()->addRgb2Hsl();

    }else if(typeid(*(view->getColorPicker()->getColor1())) == typeid(RgbaPicker)){

        model1 = new ColoreRgba;
        model2 = new ColoreRgba;
        view->getOperationButtons()->addHsl2Rgb();
    }
}
