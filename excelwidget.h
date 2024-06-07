#ifndef EXCELWIDGET_H
#define EXCELWIDGET_H

#include <QWidget>
#include <QComboBox>
#include "country.h"
#include <QTableWidget>
#include <QMainWindow>

namespace Ui {
class ExcelWidget;
}

class ExcelWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ExcelWidget(QWidget *parent = nullptr);
    ~ExcelWidget();
    void start();

private:
    Ui::ExcelWidget *ui;

//protected slots:

};

#endif // EXCELWIDGET_H
