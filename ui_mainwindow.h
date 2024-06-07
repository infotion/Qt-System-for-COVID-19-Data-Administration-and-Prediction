/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *ExcelButton;
    QPushButton *GraphButton;
    QPushButton *PredictButton;
    QLabel *label_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(443, 227);
        QFont font;
        font.setBold(false);
        MainWindow->setFont(font);
        MainWindow->setTabletTracking(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ExcelButton = new QPushButton(centralWidget);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(ExcelButton);
        ExcelButton->setObjectName(QStringLiteral("ExcelButton"));
        ExcelButton->setGeometry(QRect(60, 60, 93, 61));
        GraphButton = new QPushButton(centralWidget);
        buttonGroup->addButton(GraphButton);
        GraphButton->setObjectName(QStringLiteral("GraphButton"));
        GraphButton->setGeometry(QRect(170, 60, 93, 61));
        PredictButton = new QPushButton(centralWidget);
        buttonGroup->addButton(PredictButton);
        PredictButton->setObjectName(QStringLiteral("PredictButton"));
        PredictButton->setEnabled(true);
        PredictButton->setGeometry(QRect(280, 60, 93, 61));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(410, 320, 72, 15));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 443, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\343\203\252\343\202\260\343\203\253\343\201\256\347\226\253\346\203\205\344\277\241\346\201\257\346\237\245\350\257\242\351\242\204\346\265\213\347\263\273\347\273\237", Q_NULLPTR));
        ExcelButton->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\350\241\250\346\240\274", Q_NULLPTR));
        GraphButton->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\346\237\261\347\212\266\345\233\276", Q_NULLPTR));
        PredictButton->setText(QApplication::translate("MainWindow", "\346\237\261\347\212\266\345\233\276\351\242\204\346\265\213", Q_NULLPTR));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
