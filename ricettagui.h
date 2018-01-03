#ifndef RICETTAGUI_H
#define RICETTAGUI_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSpinBox>
class RicettaGui:public QWidget
{
public:
    RicettaGui(QWidget* parent = 0);

private:

    QPlainTextEdit* ricetta1;
    QPlainTextEdit* ricetta2;
    QPlainTextEdit* ricettaResult;
    QLineEdit *ricetta1Nome;
    QLineEdit *ricetta2Nome;
    QLineEdit *ricettaResultNome;
    QPushButton* addIngrediente1;
    QPushButton* addIngrediente2;
    QPushButton* removeIngrediente1;
    QPushButton* removeIngrediente2;
    QPushButton* calorie1;
    QPushButton* calorie2;
    QPushButton* costo1;
    QPushButton* costo2;
    QPushButton* sommaRicette;
    QPushButton* differenzaRicette;
    QPushButton* proporziona1;
    QPushButton* proporziona2;
    QGridLayout* layout;
    QPushButton* useResultAsRicetta1;
    QPushButton* useResultAsRicetta2;
    QHBoxLayout* l1;
    QSpinBox* prop1;
    QSpinBox* prop2;
};

#endif // RICETTAGUI_H
