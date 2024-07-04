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
//    if(t!=NULL) delete t;
//    delete ui;
}

void ExcelDialog::build(){
    ui->t=new QTableWidget;
    QComboBox *country=ui->CountryBox;

    Country *st=new Country;
    st->read(country->currentIndex());

    ui->t->setWindowTitle(Country::NAME[country->currentIndex()]+"疫情数据表格");
    ui->t->resize(1200,900);

    int R=Country::ROW,C=Country::COLUMN;
    ui->t->setRowCount(R);
    ui->t->setColumnCount(C-1);


    for(int i=0;i<R;i++)
    {
//        qDebug()<<"!"<<i;
        QString text=st->Item(i,7);
        QTableWidgetItem *it=new QTableWidgetItem(text);
        ui->t->setItem(i,0,it);

        for(int j=1;j+1<C;j++)
        {
            int y=j+(j>=7);//qDebug()<<i<<" "<<y;
            QString text=st->Item(i,y);
            it=new QTableWidgetItem(text);
            ui->t->setItem(i,j,it);
//            delete it;
        }
        delete it;
    }

//    if(ui->window) delete ui->window;
    ui->window=new QMainWindow;
    ui->window->setWindowTitle(ui->CountryBox->currentText()+"疫情数据");
    ui->window->setCentralWidget(ui->t);

    QToolBar *tb=new QToolBar("工具栏",ui->window);
    QAction *action_S=new QAction(tr("保存为Excel(&S)"),ui->window);
    tb->addAction(action_S);
    connect(action_S,&QAction::triggered,this,&ExcelDialog::save);
    ui->window->addToolBar(tb);

    ui->window->resize(1200, 900);
    ui->window->show();

    delete st;
}

void ExcelDialog::save(){
    qDebug()<<"SC OK";
    QString fileName = QFileDialog::getSaveFileName(ui->t, "保存",QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),"Excel 文件(*.xls *.xlsx)");
         if (fileName!="")
         {
             QAxObject *excel = new QAxObject;
             if (excel->setControl("Excel.Application")) //连接Excel控件
             {
                 excel->dynamicCall("SetVisible (bool Visible)","false");//不显示窗体
                 excel->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
                 QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
                 workbooks->dynamicCall("Add");//新建一个工作簿
                 QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
                 QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);



                 int i,j;
                 //QTablewidget 获取数据的列数
                 int colcount=ui->t->columnCount();
                  //QTablewidget 获取数据的行数
                 int rowscount=ui->t->rowCount();
                 QString title=ui->CountryBox->currentText()+"疫情数据";
                 QAxObject *cell,*col;

                 //标题行
                 cell=worksheet->querySubObject("Cells(int,int)", 1, 1);
                 cell->dynamicCall("SetValue(const QString&)", title);
                 cell->querySubObject("Font")->setProperty("Size", 18);
                 //调整行高
                 worksheet->querySubObject("Range(const QString&)", "1:1")->setProperty("RowHeight", 30);
                 //合并标题行
                 QString cellTitle;
                 cellTitle.append("A1:");
                 cellTitle.append(QChar(colcount - 1 + 'A'));
                 cellTitle.append(QString::number(1));
                 QAxObject *range = worksheet->querySubObject("Range(const QString&)", cellTitle);
                 range->setProperty("WrapText", true);
                 range->setProperty("MergeCells", true);
                 range->setProperty("HorizontalAlignment", -4108);//xlCenter
                 range->setProperty("VerticalAlignment", -4108);//xlCenter
                 //列标题


                 for(i=0;i<colcount;i++)
                 {
                     QString columnName;
                     columnName.append(QChar(i + 'A'));
//                     columnName.append(":");
//                     columnName.append(QChar(i + 'A'));
                     col = worksheet->querySubObject("Columns(const QString&)", columnName);
                     col->setProperty("ColumnWidth", ui->t->columnWidth(i)/6);
                     cell=worksheet->querySubObject("Cells(int,int)", 2, i+1);
                     //QTableWidget 获取表格头部文字信息
//                     columnName=ui->t->horizontalHeaderItem(i)->text();qDebug()<<"?";
                     //QTableView 获取表格头部文字信息
                     // columnName=ui->tableView_right->model()->headerData(i,Qt::Horizontal,Qt::DisplayRole).toString();
                     cell->dynamicCall("SetValue(const QString&)", columnName);
                     cell->querySubObject("Font")->setProperty("Bold", true);
                     cell->querySubObject("Interior")->setProperty("Color",QColor(191, 191, 191));
                     cell->setProperty("HorizontalAlignment", -4108);//xlCenter
                     cell->setProperty("VerticalAlignment", -4108);//xlCenter
                 }

                //数据区

                //QTableWidget 获取表格数据部分
                 for(i=0;i<rowscount;i++){
                     for (j=0;j<colcount;j++)
                     {
                         worksheet->querySubObject("Cells(int,int)", i+3, j+1)->dynamicCall("SetValue(const QString&)", ui->t->item(i,j)?ui->t->item(i,j)->text():"");
                     }
                 }


                //QTableView 获取表格数据部分
                //  for(i=0;i<rowcount;i++) //行数
                //     {
                //         for (j=0;j<colcount;j++)   //列数
                //         {
                //             QModelIndex index = ui->tableView_right->model()->index(i, j);
                //             QString strdata=ui->tableView_right->model()->data(index).toString();
                //             worksheet->querySubObject("Cells(int,int)", i+3, j+1)->dynamicCall("SetValue(const QString&)", strdata);
                //         }
                //     }


                 //画框线
                 QString lrange;
                 lrange.append("A2:");
                 lrange.append(colcount - 1 + 'A');
                 lrange.append(QString::number(ui->t->rowCount() + 2));
                 range = worksheet->querySubObject("Range(const QString&)", lrange);
                 range->querySubObject("Borders")->setProperty("LineStyle", QString::number(1));
                 range->querySubObject("Borders")->setProperty("Color", QColor(0, 0, 0));
                 //调整数据区行高
                 QString rowsName;
                 rowsName.append("2:");
                 rowsName.append(QString::number(ui->t->rowCount() + 2));
                 range = worksheet->querySubObject("Range(const QString&)", rowsName);
                 range->setProperty("RowHeight", 20);
                 workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName));//保存至fileName
                 workbook->dynamicCall("Close()");//关闭工作簿
                 excel->dynamicCall("Quit()");//关闭excel
                 delete excel;
                 excel=NULL;    //QMessageBox::information(this,tr("提示"),tr("数据已保存"));
                 if (QMessageBox::question(NULL,"完成","文件已经导出，是否现在打开？",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
                 {
                     QDesktopServices::openUrl(QUrl("file:///" + QDir::toNativeSeparators(fileName)));
                 }
             }
             else
             {
                 QMessageBox::warning(NULL,"错误","未能创建 Excel 对象，请安装 Microsoft Excel。",QMessageBox::Apply);
             }
         }
}
