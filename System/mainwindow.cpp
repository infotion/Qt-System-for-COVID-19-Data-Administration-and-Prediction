#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->ExcelButton,SIGNAL(clicked()),this,SLOT(Excel_Build()));
    connect(ui->GraphButton,SIGNAL(clicked()),this,SLOT(Graph_Build()));
    connect(ui->PredictButton,SIGNAL(clicked()),this,SLOT(Predict_Start()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Excel_Build(){
    qDebug()<<"ShowExcel";

    GraphDialog *ed=new GraphDialog;
    ed->show();
}

void MainWindow::Graph_Build(){
    qDebug()<<"ShowGraph";

    GraphDialog *gd=new GraphDialog;
    gd->show();
}

void MainWindow::Predict_Start(){
    qDebug()<<"PredictStart";

    PredictDialog *pd=new PredictDialog;
    pd->show();
}

