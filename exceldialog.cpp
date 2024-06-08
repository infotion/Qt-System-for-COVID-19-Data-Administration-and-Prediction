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
        QString text=st->Item(i,7);
        QTableWidgetItem *it=new QTableWidgetItem(text);
        T->setItem(i,0,it);

        for(int j=1;j+1<C;j++)
        {
            int y=j+(j>=7);
            QString text=st->Item(i,y);
            QTableWidgetItem *it=new QTableWidgetItem(text);
            T->setItem(i,j,it);
        }
    }

    ui->window=new QMainWindow;
    ui->window->setCentralWidget(T);
    ui->window->resize(1200, 900);
    ui->window->show();
}
