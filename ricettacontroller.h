#ifndef RICETTACONTROLLER_H
#define RICETTACONTROLLER_H

#include "ricettagui.h"
#include <QObject>
#include "ricetta.h"
#include "ingrediente.h"
#include <QMessageBox>
class RicettaGui;
class RicettaController:public QObject
{
    Q_OBJECT
public:
    RicettaController(RicettaGui* v);
    ~RicettaController();
private:
    RicettaGui* view;
    Ricetta* model1,*model2,*result;
    Ingrediente* ing;
    void UpdateRicettaView(Ricetta*,QPlainTextEdit*);
    void showMessageBox(QString ,QString )const;
private slots:
    void AddIngredienteModel1();
    void AddIngredienteModel2();
    void RemoveIngredienteModel1();
    void RemoveIngredienteModel2();
    void CostoModel1();
    void CostoModel2();
    void CalorieModel1();
    void CalorieModel2();
    void ProporzionaModel1();
    void ProporzionaModel2();
    void Somma();
    void Differenza();
    void useAsModel1();
    void useAsModel2();
    void UpdateNomeRicetta1();
    void UpdateNomeRicetta2();


};

#endif // RICETTACONTROLLER_H
