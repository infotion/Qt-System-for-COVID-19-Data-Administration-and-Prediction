#include "predictdialog.h"
#include "ui_predictdialog.h"

PredictDialog::PredictDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PredictDialog)
{
    ui->setupUi(this);
}

PredictDialog::~PredictDialog()
{
    delete ui;
}
