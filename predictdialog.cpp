#include "predictdialog.h"
#include "ui_predictdialog.h"
#include<iomanip>

PredictDialog::PredictDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PredictDialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(Calc()));
}

PredictDialog::~PredictDialog()
{
    delete ui;
}

char PredictDialog::MONTH[12][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

void PredictDialog::Calc(){
    int S=ui->StartMonthBox->currentIndex()+2;
    int T=ui->EndMonthBox->currentIndex()+2;
    int D=ui->DuringMonthBox->currentIndex()+1;

    if(S>=T){
        QDialog *as=new QDialog;
        QVBoxLayout *vbox = new QVBoxLayout(this);
        vbox->addWidget(new QLabel("起始月份必须小于终止月份，否则无法实现线性回归计算！"));
        QDialogButtonBox *b=new QDialogButtonBox(QDialogButtonBox::Ok);
        vbox->addWidget(b);
        as->setLayout(vbox);
        as->show();
        connect(b,SIGNAL(accepted()),as,SLOT(accept()));
        return;
    }

    QComboBox *country=ui->CountryBox;

    Country *st=new Country;
    st->read(country->currentIndex());

    int col=ui->comboBox->currentIndex();

    while(!st->calc_month(S,col)) S++;

    if(S>=T){
        QDialog *as=new QDialog;
        QVBoxLayout *vbox = new QVBoxLayout(this);
        vbox->addWidget(new QLabel("该国家（地区）的起始月份数据不足，请选择一个更晚的起始月份！"));
        QDialogButtonBox *b=new QDialogButtonBox(QDialogButtonBox::Ok);
        vbox->addWidget(b);
        as->setLayout(vbox);
        as->show();
        connect(b,SIGNAL(accepted()),as,SLOT(accept()));
        return;
    }

    double X[20]={},N=T-S+1;
    double Y[20]={};
    double aX,aY,sY,sX,ssX;

    for(int i=S;i<=T;i++){
        X[i]=i;
        Y[i]=st->calc_month(i,col);
    }

//[0]
    double B_0=0.0,A_0=0.0;
    double X0[20],Y0[20];

    memcpy(X0,X,sizeof(X));
    memcpy(Y0,Y,sizeof(Y));

    aX=(S+T)/2.0,aY=0,sY=0,sX=0,ssX=0;
    for(int i=S;i<=T;i++) sY+=Y0[i];
    aY=sY/N;
    for(int i=S;i<=T;i++) sX+=i,ssX+=i*i;

    for(int i=S;i<=T;i++) B_0+=(X0[i]-aX)*(Y0[i]-aY);
    B_0/=ssX-N*aX*aX;
    A_0=aY-B_0*aX;

    for(int i=S;i<=T+D;i++) Y0[i]=B_0*(i)+A_0/*,qDebug()<<Y0[i]*/;

    double R0=0.0;
    for(int i=S;i<=T;i++)
        R0+=1.0/N*(Y0[i]-Y[i])*(Y0[i]-Y[i]);

//[1]
    double B_1=0.0,A_1=0.0;
    double X1[20],Y1[20];

    memcpy(X1,X,sizeof(X));
    memcpy(Y1,Y,sizeof(Y));

    aY=0,sY=0,sX=0,ssX=0;

    for(int i=S;i<=T;i++) sY+=Y1[i];
    aY=sY/N;
    for(int i=S;i<=T;i++) X1[i]=log(X1[i])/log(2.7182818285);
    for(int i=S;i<=T;i++) sX+=X1[i],ssX+=X1[i]*X1[i];
    aX=sX/N;

    for(int i=S;i<=T;i++){
        B_1+=(X1[i]-aX)*(Y1[i]-aY);
    }

    B_1/=ssX-N*aX*aX;
    A_1=aY-B_1*aX;

    for(int i=S;i<=T+D;i++) Y1[i]=B_1*log(i)/log(2.7182818285)+A_1/*,qDebug()<<Y1[i]*/;

    double R1=0.0;
    for(int i=S;i<=T;i++)
        R1+=1.0/N*(Y1[i]-Y[i])*(Y1[i]-Y[i]);
//[2]
    double B_2=0.0,A_2=0.0;
    double X2[20],Y2[20];

    memcpy(X2,X,sizeof(X));
    memcpy(Y2,Y,sizeof(Y));

    aY=0,sY=0,sX=0,ssX=0;

    for(int i=S;i<=T;i++) Y2[i]=log(Y2[i])/log(2.7182818285),sY+=Y2[i];
    aY=sY/N;
    for(int i=S;i<=T;i++) X2[i]=i;
    for(int i=S;i<=T;i++) sX+=X2[i],ssX+=X2[i]*X2[i];
    aX=sX/N;

    for(int i=S;i<=T;i++){
        B_2+=(X2[i]-aX)*(Y2[i]-aY);
    }

    B_2/=ssX-N*aX*aX;
    A_2=aY-B_2*aX;

    for(int i=S;i<=T+D;i++) Y2[i]=pow(10,(B_2*i+A_2)*log(2.7182818285));

    double R2=0.0;
    for(int i=S;i<=T;i++)
        R2+=1.0/N*(Y2[i]-Y[i])*(Y2[i]-Y[i]);

    qDebug()<<"ShowGraph";

    QFont font;
    font.setFamily("HarmonyOS Sans");

    QStringList list;
    list.append(ui->CountryBox->currentText());
    QChart *chart = new QChart();
    QBarSeries *cset=new QBarSeries();

    double *tmp=new double;
    if(R0<R1 and R0<R2) tmp=Y0,cerr<<"!"<<endl;
    else if(R1<R0 and R1<R2) tmp=Y1,cerr<<"!!"<<endl;
    else tmp=Y2,cerr<<"!!!"<<endl;

    qDebug()<<R0<<" "<<R1<<" "<<R2<<endl;

    for(int i=S;i<=T+D;i++)
    {

    }

    double MAXY=0;

    for(auto it=list.begin();it!=list.end();it++){
        qDebug()<<*it;
        QBarSet *data=new QBarSet(*it);

        for(int i=S;i<=T;i++){
            qDebug()<<Y[i];
            *data<<Y[i];
            MAXY=max(MAXY,Y[i]);
        }
        for(int i=T+1;i<=T+D;i++){
            qDebug()<<tmp[i];
            *data<<(int)(tmp[i]);
            MAXY=max(MAXY,tmp[i]);
        }

        data->setLabelColor(Qt::black);
        data->setLabelFont(font);

        cset->append(data);
    }

    cset->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);
    cset->setLabelsVisible(true);

    chart->addSeries(cset);
    QString title="已选国家的"+ui->comboBox->currentText()+"预测数据";
    chart->setTitle(title);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    for(int i=S;i<=T+D;i++){
        categories<<MONTH[i-1];
    }

    QBarCategoryAxis *axis = new QBarCategoryAxis();
    QValueAxis *yxis=new QValueAxis();

    axis->append(categories);
    yxis->setRange(0,ceil(MAXY*1.5/1000)*1000);

    chart->createDefaultAxes();//创建默认的左侧的坐标轴（根据 QBarSet 设置的值）
    chart->setAxisX(axis, cset);//设置坐标轴
    chart->setAxisY(yxis, cset);
    chart->legend()->setVisible(true); //设置图例为显示状态
    chart->legend()->setAlignment(Qt::AlignBottom);//设置图例的显示位置在底部
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);


    QMainWindow *window=new QMainWindow;
    window->setCentralWidget(chartView);
    window->setWindowTitle("柱状图可视化界面");
    window->setFont(font);
    window->resize(1600, 900);
    window->show();
}
