#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();
public slots:
    void slotCheckedChanged(int state);			//声明槽函数

private:
    Ui::Form *ui;
};

#endif // FORM_H
