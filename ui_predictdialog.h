/********************************************************************************
** Form generated from reading UI file 'predictdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREDICTDIALOG_H
#define UI_PREDICTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QMainWindow>

QT_BEGIN_NAMESPACE

class Ui_PredictDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QComboBox *DuringMonthBox;
    QLabel *label_2;
    QLabel *label_4;
    QComboBox *StartMonthBox;
    QComboBox *EndMonthBox;
    QLabel *CountryLabel;
    QComboBox *CountryBox;
    QLabel *label_3;
    QComboBox *comboBox;
    QMainWindow *window;

    void setupUi(QDialog *PredictDialog)
    {
        if (PredictDialog->objectName().isEmpty())
            PredictDialog->setObjectName(QStringLiteral("PredictDialog"));
        PredictDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(PredictDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(PredictDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 140, 72, 15));
        DuringMonthBox = new QComboBox(PredictDialog);
        DuringMonthBox->setObjectName(QStringLiteral("DuringMonthBox"));
        DuringMonthBox->setEnabled(true);
        DuringMonthBox->setGeometry(QRect(260, 160, 87, 22));
        label_2 = new QLabel(PredictDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(150, 140, 72, 15));
        label_4 = new QLabel(PredictDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(260, 140, 72, 15));
        StartMonthBox = new QComboBox(PredictDialog);
        StartMonthBox->setObjectName(QStringLiteral("StartMonthBox"));
        StartMonthBox->setEnabled(true);
        StartMonthBox->setGeometry(QRect(40, 160, 87, 22));
        StartMonthBox->setMouseTracking(true);
        StartMonthBox->setTabletTracking(true);
        StartMonthBox->setEditable(false);
        EndMonthBox = new QComboBox(PredictDialog);
        EndMonthBox->setObjectName(QStringLiteral("EndMonthBox"));
        EndMonthBox->setEnabled(true);
        EndMonthBox->setGeometry(QRect(150, 160, 87, 22));
        EndMonthBox->setMouseTracking(true);
        EndMonthBox->setTabletTracking(true);
        EndMonthBox->setEditable(false);
        CountryLabel = new QLabel(PredictDialog);
        CountryLabel->setObjectName(QStringLiteral("CountryLabel"));
        CountryLabel->setGeometry(QRect(40, 40, 141, 20));
        CountryBox = new QComboBox(PredictDialog);
        CountryBox->setObjectName(QStringLiteral("CountryBox"));
        CountryBox->setGeometry(QRect(40, 70, 141, 31));
        label_3 = new QLabel(PredictDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(190, 40, 171, 20));
        comboBox = new QComboBox(PredictDialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(190, 70, 161, 31));

        retranslateUi(PredictDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PredictDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PredictDialog, SLOT(reject()));

        StartMonthBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PredictDialog);
    } // setupUi

    void retranslateUi(QDialog *PredictDialog)
    {
        PredictDialog->setWindowTitle(QApplication::translate("PredictDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("PredictDialog", "\350\265\267\345\247\213\346\234\210\344\273\275", Q_NULLPTR));
        DuringMonthBox->clear();
        DuringMonthBox->insertItems(0, QStringList()
         << QApplication::translate("PredictDialog", "1\344\270\252\346\234\210", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "2\344\270\252\346\234\210", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "3\344\270\252\346\234\210", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "4\344\270\252\346\234\210", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "5\344\270\252\346\234\210", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "6\344\270\252\346\234\210", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("PredictDialog", "\347\273\210\346\255\242\346\234\210\344\273\275", Q_NULLPTR));
        label_4->setText(QApplication::translate("PredictDialog", "\351\242\204\346\265\213\351\225\277\345\272\246", Q_NULLPTR));
        StartMonthBox->clear();
        StartMonthBox->insertItems(0, QStringList()
         << QApplication::translate("PredictDialog", "2\346\234\210", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "3\346\234\210", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "4\346\234\210", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "5\346\234\210", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "6\346\234\210", Q_NULLPTR)
        );
        StartMonthBox->setCurrentText(QApplication::translate("PredictDialog", "2\346\234\210", Q_NULLPTR));
        EndMonthBox->clear();
        EndMonthBox->insertItems(0, QStringList()
         << QApplication::translate("PredictDialog", "2\346\234\210", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "3\346\234\210", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "4\346\234\210", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "5\346\234\210", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "6\346\234\210", Q_NULLPTR)
        );
        EndMonthBox->setCurrentText(QApplication::translate("PredictDialog", "2\346\234\210", Q_NULLPTR));
        CountryLabel->setText(QApplication::translate("PredictDialog", "\351\200\211\346\213\251\351\234\200\350\246\201\346\237\245\350\257\242\347\232\204\345\233\275\345\256\266", Q_NULLPTR));
        CountryBox->clear();
        CountryBox->insertItems(0, QStringList()
         << QApplication::translate("PredictDialog", "\344\270\226\347\225\214", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "\344\270\255\345\233\275", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "\346\227\245\346\234\254", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "\351\237\251\345\233\275", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "\350\222\231\345\217\244", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "\350\266\212\345\215\227", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "\346\263\260\345\233\275", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "\347\274\205\347\224\270", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "\350\200\201\346\214\235", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "\346\237\254\345\237\224\345\257\250", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "\351\251\254\346\235\245\350\245\277\344\272\232", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "\346\226\260\345\212\240\345\235\241", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "\345\215\260\345\272\246\345\260\274\350\245\277\344\272\232", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "\350\217\262\345\276\213\345\256\276", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "\346\276\263\345\244\247\345\210\251\344\272\232", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "\346\226\260\350\245\277\345\205\260", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("PredictDialog", "\350\276\223\345\205\245\351\234\200\350\246\201\345\217\257\350\247\206\345\214\226\347\232\204\351\241\271\347\233\256", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("PredictDialog", "\347\241\256\350\257\212\347\227\205\344\276\213", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "\345\272\267\345\244\215\347\227\205\344\276\213", Q_NULLPTR)
         << QApplication::translate("PredictDialog", "\346\255\273\344\272\241\347\227\205\344\276\213", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class PredictDialog: public Ui_PredictDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREDICTDIALOG_H
