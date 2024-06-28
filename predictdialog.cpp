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
    int idx=country->currentIndex();

//    if(idx==8 or idx==4 or idx==9)
//    {
//        QDialog *as=new QDialog;
//        QVBoxLayout *vbox = new QVBoxLayout(this);
//        vbox->addWidget(new QLabel(Country::NAME[idx]+"收集的疫情数据极少（远少于中国），不具有统计意义，还是看看其他国家（地区）吧"));
//        QDialogButtonBox *b=new QDialogButtonBox(QDialogButtonBox::Ok);
//        vbox->addWidget(b);
//        as->setLayout(vbox);
//        as->show();
//        connect(b,SIGNAL(accepted()),as,SLOT(accept()));
//        return;
//    }

    int col=ui->comboBox->currentIndex()*2;
    Country *st=new Country;
    st->read(ui->CountryBox->currentText());
    while(S<=6 and !st->calc_month(S,col)) S++;

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
        qDebug()<<Y[i];

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
    for(int i=S;i<=T;i++) X1[i]=log(X1[i]);
    for(int i=S;i<=T;i++) sX+=X1[i],ssX+=X1[i]*X1[i];
    aX=sX/N;

    for(int i=S;i<=T;i++){
        B_1+=(X1[i]-aX)*(Y1[i]-aY);
    }

    B_1/=ssX-N*aX*aX;
    A_1=aY-B_1*aX;

    for(int i=S;i<=T+D;i++) Y1[i]=B_1*log(i)+A_1/*,qDebug()<<Y1[i]*/;

    double R1=0.0;
    for(int i=S;i<=T;i++)
        R1+=1.0/N*(Y1[i]-Y[i])*(Y1[i]-Y[i]);
//[2]
    double B_2=0.0,A_2=0.0;
    double X2[20],Y2[20];

    memcpy(X2,X,sizeof(X));
    memcpy(Y2,Y,sizeof(Y));

    aY=0,sY=0,sX=0,ssX=0;

    for(int i=S;i<=T;i++) Y2[i]=log(Y2[i]),sY+=Y2[i];
    aY=sY/N;
    for(int i=S;i<=T;i++) X2[i]=i;
    for(int i=S;i<=T;i++) sX+=X2[i],ssX+=X2[i]*X2[i];
    aX=sX/N;

    for(int i=S;i<=T;i++){
        B_2+=(X2[i]-aX)*(Y2[i]-aY);
    }

    B_2/=ssX-N*aX*aX;
    A_2=aY-B_2*aX;

    for(int i=S;i<=T+D;i++) Y2[i]=pow(10,(B_2*i+A_2)*log10(2.7182818285));

    double R2=0.0;
    for(int i=S;i<=T;i++)
        R2+=1.0/N*(Y2[i]-Y[i])*(Y2[i]-Y[i]);
//[3]
    vector<double> XX,YY;
    double Y3[20];
    for(int i=S;i<=T;i++) XX.push_back(X[i]),YY.push_back(Y[i]);

    Fit fit;
    fit.polyfit(XX,YY,3,true);

    for(int i=S;i<=T+D;i++) Y3[i]=fit.getY(i);

    double R3=0.0;
    for(int i=S;i<=T;i++)
        R3+=1.0/N*(Y3[i]-Y[i])*(Y3[i]-Y[i]);

    double Y4[20];
    fit.polyfit(XX,YY,2,true);

    for(int i=S;i<=T+D;i++) Y4[i]=fit.getY(i);

    double R4=0.0;
    for(int i=S;i<=T;i++)
        R4+=1.0/N*(Y4[i]-Y[i])*(Y4[i]-Y[i]);
//[SP]
    bool flag=1;

    for(int i=1;i<=D;i++)
    {
        if(Y3[T+i]<0 or Y4[T+i]<0 or Y3[T+i]<Y3[T+i-1] or Y4[T+i]<Y4[T+i-1]) flag=0;
    }
    if(!flag) R3=R4=R0+R1+R2;

    qDebug()<<"ShowGraph";

    QFont font;
    font.setFamily("HarmonyOS Sans");

    QStringList list;
    list.append(ui->CountryBox->currentText());
    QChart *chart = new QChart();
    QBarSeries *cset=new QBarSeries();

    double *tmp=new double;
    if(R0<R1 and R0<R2 and R0<R3 and R0<R4) tmp=Y0,cerr<<"Linear"<<endl;
    else if(R1<R0 and R1<R2 and R1<R3 and R0<R4) tmp=Y1,cerr<<"Log"<<endl;
    else if(R2<R0 and R2<R1 and R2<R3 and R0<R4) tmp=Y2,cerr<<"Exp"<<endl;
    else if(R3<R0 and R3<R1 and R3<R2 and R3<R4) tmp=Y3,cerr<<"Poly3"<<endl;
    else tmp=Y4,cerr<<"Poly2"<<endl;

    qDebug()<<R0<<" "<<R1<<" "<<R2<<" "<<R3<<" "<<R4<<endl;

    double MAXY=0;

    for(auto it=list.begin();it!=list.end();it++){
        qDebug()<<*it;

        QBarSet *data=new QBarSet(*it);
        QBarSet *data_p=new QBarSet(*it+"(预测)");

        for(int i=S;i<=T;i++){
            *data<<Y[i];
            *data_p<<0;
            MAXY=max(MAXY,max(tmp[i],Y[i]));
        }

        data->setLabelColor(Qt::black);
        data->setLabelFont(font);

        for(int i=T+1;i<=T+D;i++){
            qDebug()<<tmp[i];
            *data_p<<(long long)tmp[i];
            MAXY=max(MAXY,tmp[i]);
        }

        data_p->setLabelColor(Qt::red);
        data_p->setLabelFont(font);

        cset->append(data);
        cset->append(data_p);
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
    yxis->setRange(0,ceil(MAXY*1.2/pow(10,(int)log10(MAXY)))*pow(10,(int)log10(MAXY)));

    chart->createDefaultAxes();//创建默认的左侧的坐标轴（根据 QBarSet 设置的值）
    chart->setAxisX(axis, cset);//设置坐标轴
    chart->setAxisY(yxis, cset);
    chart->legend()->setVisible(true); //设置图例为显示状态
    chart->legend()->setAlignment(Qt::AlignBottom);//设置图例的显示位置在底部
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);


    ui->window=new QMainWindow;
    ui->window->setCentralWidget(chartView);
    ui->window->setWindowTitle("柱状图可视化界面");
    ui->window->setFont(font);
    ui->window->resize(1600, 900);

    QToolBar *tb=new QToolBar("工具栏",ui->window);
    QAction *action_S=new QAction(tr("保存图片(&S)"),ui->window);
    tb->addAction(action_S);
    connect(action_S,&QAction::triggered,this,&PredictDialog::screenshot);
    ui->window->addToolBar(tb);

    ui->window->show();
}

void PredictDialog::screenshot(){
    QPixmap pixMap_ = QPixmap::grabWidget(ui->window->centralWidget());
    QDateTime t=QDateTime::currentDateTime();
    QString time=t.toString("yyyy-MM-dd hh-mm-ss");
    QString name=time+".png";
    qDebug()<<"./png/"+name;
    pixMap_.save("./png/"+name);

    QDialog *as=new QDialog;
    QVBoxLayout *vbox = new QVBoxLayout(this);
    QString *text=new QString("图片已保存至");
    text->append(QString::fromStdString(Country::PATH));
    text->append("\\png\\");
    text->append(name);
    vbox->addWidget(new QLabel(*text));
//    vbox->addWidget(new QLabel("图片已保存至D:\\1111111111111111111\\CSU\\0000\\system\\System\\png\\"+name));
    QDialogButtonBox *b=new QDialogButtonBox(QDialogButtonBox::Ok);
    vbox->addWidget(b);
    as->setLayout(vbox);
    as->show();
    connect(b,SIGNAL(accepted()),as,SLOT(accept()));
}
