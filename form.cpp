#include "form.h"
#include "ui_form.h"
#include<QCheckBox>
#include<QWidget>
#include<QDebug>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

        QCheckBox *checkBox1 = new QCheckBox(this);             //创建QCheckBox对象
        checkBox1->move(100, 50);                               //设置位置
        checkBox1->setText("语文");                              //设置显示文本

        QCheckBox *checkBox2 = new QCheckBox(this);
        checkBox2->move(100, 100);
        checkBox2->setText("数学");
        checkBox2->setChecked(true);                            //设置选中状态，默认为未选中

        QCheckBox *checkBox3 = new QCheckBox(this);
        checkBox3->move(100, 150);
        checkBox3->setText("英语");

        checkBox3->setTristate(true);                           //开启三态选择模式
        checkBox3->setCheckState(Qt::PartiallyChecked);         //设置选中状态

        connect(checkBox3, SIGNAL(stateChanged(int)),
                this, SLOT(slotCheckedChanged(int)));
}

Form::~Form()
{
    delete ui;
}

void Form::slotCheckedChanged(int state)
{
    if (state == Qt::Checked)
    {
        qDebug() << "选中";
    }
    else if (state == Qt::Unchecked)
    {
        qDebug() << "未选中";
    }
    else if (state == Qt::PartiallyChecked)
    {
        qDebug() << "半选中";
    }
}
