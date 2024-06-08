#ifndef EXCELDIALOG_H
#define EXCELDIALOG_H

#include <QDialog>
#include "country.h"
#include <QTableWidget>
#include <QMainWindow>

namespace Ui {
class ExcelDialog;
}

class ExcelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExcelDialog(QWidget *parent = nullptr);
    ~ExcelDialog();

private:
    Ui::ExcelDialog *ui;

private slots:
    void build();
};

#endif // EXCELDIALOG_H
