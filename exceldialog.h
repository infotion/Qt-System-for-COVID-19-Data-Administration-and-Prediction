#ifndef EXCELDIALOG_H
#define EXCELDIALOG_H

#include <QDialog>
#include "country.h"
#include <QTableWidget>
#include <QMainWindow>
#include <QToolBar>
#include <QDesktopServices>
#include <QUrl>
#include <QAxObject>
#include <QMessageBox>
#include <QFileDialog>

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
    void save();
};

#endif // EXCELDIALOG_H
