#include "excelwidget.h"
#include "ui_excelwidget.h"

ExcelWidget::ExcelWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExcelWidget)
{
    ui->setupUi(this);

//    connect(ui->buttonBox,SIGNAL(accepted()),ui->buttonBox,SLOT(accept()));
//    connect(ui->buttonBox,SIGNAL(accepted()),ui->buttonBox,SLOT(accept()));
}

ExcelWidget::~ExcelWidget()
{
    delete ui;
}

void ExcelWidget::start(){

}
