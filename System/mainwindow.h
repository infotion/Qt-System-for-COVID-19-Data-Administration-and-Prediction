#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QFont>
#include <QTextCodec>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <QDebug>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "country.h"
#include "exceldialog.h"
#include "graphdialog.h"
#include "predictdialog.h"
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void Excel_Build();
    void Graph_Build();
    void Predict_Start();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
