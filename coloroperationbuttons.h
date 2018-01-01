#ifndef COLOROPERATIONBUTTONS_H
#define COLOROPERATIONBUTTONS_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
class colorOperationButtons:public QWidget
{
    Q_OBJECT
public:
    colorOperationButtons(QWidget* parent = 0);

private:

    QPushButton *btnSomma,*btnDifferenza,*btnModulazione,*btnDeltaE,*btnScala,*btnComplementare,*btnLuminosita,*btnCaldo,*btnLab,*btnHsl,*btnHex,*btnHsl2Rgb;
    QGridLayout* layout;

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
};

#endif // COLOROPERATIONBUTTONS_H
