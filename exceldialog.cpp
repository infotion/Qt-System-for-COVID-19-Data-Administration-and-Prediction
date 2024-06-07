#include "exceldialog.h"
#include "ui_exceldialog.h"

ExcelDialog::ExcelDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExcelDialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(build()));
}

ExcelDialog::~ExcelDialog()
{
    delete ui;
}

void ExcelDialog::build(){
    QComboBox *country=ui->CountryBox;

    Country *st=new Country;
    st->read(country->currentIndex());

    QTableWidget *T=new QTableWidget;
    T->setWindowTitle(Country::NAME[country->currentIndex()]+"疫情数据表格");
    T->resize(1200,900);

    int R=Country::ROW,C=Country::COLUMN;
    T->setRowCount(R);
    T->setColumnCount(C-1);

    for(int i=0;i<R;i++)
    {
        for(int j=1;j<C;j++)
        {
            QString text=st->Item(i,j);
            QTableWidgetItem *it;
            it=new QTableWidgetItem(text);
            T->setItem(i,j,it);
        }
    }

    QMainWindow *window=new QMainWindow;
    window->setCentralWidget(T);
    window->resize(1200, 900);

//    QAction *action_L=new QAction(tr("悔棋(&L)"),this);
//    QAction *action_S=new QAction(tr("结束(&S)"),this);
//    connect(action_L,&QAction::triggered,this,&MainWindow::RepentanceGame);
//    connect(action_S,&QAction::triggered,this,&MainWindow::StopGame);
//    ui->toolBar->addAction(action_L);
//    ui->toolBar->addAction(action_S);
//    QAction *save=new QAction(tr("保存(&S)"),window);
//    connect(save,&QAction::triggered,window,&)
//    window->addToolBar(save);

    window->show();
}
