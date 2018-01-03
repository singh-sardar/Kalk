#ifndef RICETTACONTROLLER_H
#define RICETTACONTROLLER_H

#include "ricettagui.h"
#include <QObject>
#include "ricetta.h"

class RicettaController:public QObject
{
public:
    RicettaController(RicettaGui* v);
private:
    RicettaGui* view;
    Ricetta* model1,*model2,*result;


};

#endif // RICETTACONTROLLER_H
