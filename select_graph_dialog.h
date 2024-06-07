#ifndef SELECT_GRAPH_DIALOG_H
#define SELECT_GRAPH_DIALOG_H

#include <QDialog>
#include "mycombobox.h"
#include "country.h"
#include<QBarSet>
#include<QtCharts>

namespace Ui {
class Select_Graph_Dialog;
}

class Select_Graph_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Select_Graph_Dialog(QWidget *parent = 0);
    ~Select_Graph_Dialog();

    void setMSCB();
    MultiSelectComboBox* SelectedCountry();

signals:


private slots:
    bool on_buttonBox_accepted();

private:
    Ui::Select_Graph_Dialog *ui;
    MultiSelectComboBox *MSCB;
};

#endif // SELECT_GRAPH_DIALOG_H
