#ifndef INGREDIENTEDIALOG_H
#define INGREDIENTEDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QLineEdit>
class IngredienteDialog: public QDialog
{
    Q_OBJECT
public:
    IngredienteDialog(QWidget* parent =0);
    ~IngredienteDialog();
    QLineEdit* getNomeIngrediente()const;
    QDoubleSpinBox* getQuantitaIngrediente()const;
    QDoubleSpinBox* getCalorieIngrediente()const;
    QDoubleSpinBox* getCostoIngrediente()const;
private:
    QGridLayout* layout;
    QPushButton* ok;
    QPushButton* cancel;

    QLabel* lblNome;
    QLabel* lblQuantita;
    QLabel* lblCalorie;
    QLabel* lblCosto;

    QLineEdit* editNome;
    QDoubleSpinBox* spinQuantita;
    QDoubleSpinBox* spinCalorie;
    QDoubleSpinBox* spinCosto;

private slots:
    void btnOK();
    void btnCancel();
};

#endif // INGREDIENTEDIALOG_H
