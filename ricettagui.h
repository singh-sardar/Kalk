#ifndef RICETTAGUI_H
#define RICETTAGUI_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
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
    QGridLayout* layout;
};

#endif // RICETTAGUI_H
