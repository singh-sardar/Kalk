#ifndef COLOROPERATIONBUTTONS_H
#define COLOROPERATIONBUTTONS_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QHBoxLayout>
class colorOperationButtons:public QWidget
{
    Q_OBJECT
public:
    colorOperationButtons(QWidget* parent = 0);
    QDoubleSpinBox* getFattoreScalaSpin()const;
    QDoubleSpinBox* getHSpin()const;
    QDoubleSpinBox* getSSpin()const;
    QDoubleSpinBox* getLSpin()const;

    QSpinBox* getRSpin()const;
    QSpinBox* getGSpin()const;
    QSpinBox* getBSpin()const;

    void removeSpinConversione();
    void addHsl2Rgb();
    void addRgb2Hsl();

    ~colorOperationButtons();



private:

    QPushButton *btnSomma,*btnDifferenza,*btnModulazione,*btnDeltaE,*btnScala,*btnComplementare,*btnLuminosita,*btnCaldo,*btnLab,*btnHsl,*btnHex,*btnHsl2Rgb;
    QPushButton *btnRgb2Hsl;
    QGridLayout* layout;
    QDoubleSpinBox *fattoreScala,*H,*S,*L;
    QSpinBox *R,*G,*B;
    QHBoxLayout* l;
    QLabel* lbl1,*lbl2;


    void deleteChildWidgets(QLayoutItem*);

signals:
    void btnSommaClicked(bool);
    void btnDifferenzaClicked(bool);
    void btnModulazioneClicked(bool);
    void btnDeltaEClicked(bool);
    void btnScalaClicked(bool);
    void btnComplementareClicked(bool);
    void btnLuminositaClicked(bool);
    void btnCaldoClicked(bool);
    void btnLabClicked(bool);
    void btnHslClicked(bool);
    void btnHexClicked(bool);
    void btnHsl2RgbClicked(bool);
    void btnRgb2HslClicked(bool);
};

#endif // COLOROPERATIONBUTTONS_H
