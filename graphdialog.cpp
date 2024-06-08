#include "graphdialog.h"
#include "ui_graphdialog.h"

GraphDialog::GraphDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraphDialog)
{
    ui->setupUi(this);

//    QVBoxLayout *vbox = new QVBoxLayout(this);
//    vbox->setAlignment(Qt::AlignBaseline);
//    vbox->insertWidget(2,ui->label/*,Qt::AlignHCenter*/);
//    vbox->insertWidget(4,ui->comboBox);
//    vbox->insertWidget(6,ui->label_2);
//    vbox->insertWidget(8,MSCB);
//    vbox->insertWidget(10,ui->buttonBox);
//    setLayout(vbox);

    for(int i=0;i<16;i++) ui->MSCB->addItem(Country::NAME[i]);
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(build()));
}

GraphDialog::~GraphDialog()
{
    delete ui;
}

void GraphDialog::build(){
    qDebug()<<"ShowGraph";

    QFont font;
    font.setFamily("HarmonyOS Sans");

    QStringList list=ui->MSCB->CheckText();
    QChart *chart = new QChart();
    QBarSeries *cset=new QBarSeries();
    int col=ui->comboBox->currentIndex();

    int MAXY=0;

    for(auto it=list.begin();it!=list.end();it++){
        qDebug()<<*it;
        QBarSet *data=new QBarSet(*it);

        Country *st=new Country;
        st->read(*it);

        for(int i=1;i<=6;i++){
            int res=st->calc_month(i,col);
            data->append(res);
            MAXY=max(MAXY,res);
        }

        data->setLabelColor(Qt::black);
        data->setLabelFont(font);

        cset->append(data);
    }

//![1]

//![2]
//    QBarSeries *series = new QBarSeries();
//    series->append(set0);
//    series->append(set1);
//    series->append(set2);
//    series->append(set3);
//    series->append(set4);

//![2]

//![3]
    cset->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);
    cset->setLabelsVisible(true);

    chart->addSeries(cset);
    QString title="已选国家的"+ui->comboBox->currentText()+"数据";
    chart->setTitle(title);
    chart->setAnimationOptions(QChart::SeriesAnimations);
//![3]

//![4]
    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";

    QBarCategoryAxis *axis = new QBarCategoryAxis();
    QValueAxis *yxis=new QValueAxis();

    axis->append(categories);
    yxis->setRange(0,ceil(MAXY*1.5/1000)*1000);

    chart->createDefaultAxes();//创建默认的左侧的坐标轴（根据 QBarSet 设置的值）
    chart->setAxisX(axis, cset);//设置坐标轴
    chart->setAxisY(yxis, cset);
//![4]

//![5]
    chart->legend()->setVisible(true); //设置图例为显示状态
    chart->legend()->setAlignment(Qt::AlignBottom);//设置图例的显示位置在底部
//![5]

//![6]
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

//![6]

//![7]
    ui->window=new QMainWindow;
    ui->window->setCentralWidget(chartView);
    ui->window->setWindowTitle("柱状图可视化界面");
    ui->window->setFont(font);
    ui->window->resize(1600, 900);

    QToolBar *tb=new QToolBar("工具栏",ui->window);
    QAction *action_S=new QAction(tr("保存图片(&S)"),ui->window);
    tb->addAction(action_S);
    connect(action_S,&QAction::triggered,this,&GraphDialog::screenshot);
    ui->window->addToolBar(tb);

    ui->window->show();
}

void GraphDialog::screenshot(){
    QPixmap pixMap_ = QPixmap::grabWidget(ui->window->centralWidget());
    QDateTime t=QDateTime::currentDateTime();
    QString time=t.toString("yyyy-MM-dd hh-mm-ss");
    QString name=time+".png";
    qDebug()<<"./png/"+name;
    pixMap_.save("./png/"+name);

    QDialog *as=new QDialog;
    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->addWidget(new QLabel("图片已保存至D:\\1111111111111111111\\CSU\\0000\\system\\System\\png\\"+name));
    QDialogButtonBox *b=new QDialogButtonBox(QDialogButtonBox::Ok);
    vbox->addWidget(b);
    as->setLayout(vbox);
    as->show();
    connect(b,SIGNAL(accepted()),as,SLOT(accept()));
}
