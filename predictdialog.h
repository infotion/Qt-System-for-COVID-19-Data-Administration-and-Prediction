#ifndef PREDICTDIALOG_H
#define PREDICTDIALOG_H

#include <QDialog>
#include "country.h"
#include <QtCharts>
#include <cmath>
#include "polycurve.h"

namespace Ui {
class PredictDialog;
}

class PredictDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PredictDialog(QWidget *parent = nullptr);
    ~PredictDialog();

private:
    Ui::PredictDialog *ui;
    static char MONTH[12][4];
private slots:
    void Calc();
    void screenshot();
};

#endif // PREDICTDIALOG_H
