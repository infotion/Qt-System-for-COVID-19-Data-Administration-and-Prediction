#ifndef GRAPHDIALOG_H
#define GRAPHDIALOG_H

#include <QDialog>
#include "mycombobox.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QtCharts>
#include <QBarSet>
#include "country.h"
//using namespace QtCharts;

namespace Ui {
class GraphDialog;
}

class GraphDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GraphDialog(QWidget *parent = nullptr);
    ~GraphDialog();

private:
    Ui::GraphDialog *ui;

private slots:
    void build();
};

#endif // GRAPHDIALOG_H
