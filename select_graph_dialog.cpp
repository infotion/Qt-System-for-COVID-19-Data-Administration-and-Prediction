#include "select_graph_dialog.h"
#include "ui_select_graph_dialog.h"

Select_Graph_Dialog::Select_Graph_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Select_Graph_Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("选择");
}

Select_Graph_Dialog::~Select_Graph_Dialog()
{
    delete ui;
}

void Select_Graph_Dialog::setMSCB(){
    MSCB=new MultiSelectComboBox;
    for(int i=0;i<16;i++)
    {
        MSCB->addItem(Country::NAME[i]);
    }
}

MultiSelectComboBox* Select_Graph_Dialog::SelectedCountry(){
    return MSCB;
}

bool Select_Graph_Dialog::on_buttonBox_accepted()
{
}
