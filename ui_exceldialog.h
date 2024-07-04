/********************************************************************************
** Form generated from reading UI file 'exceldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXCELDIALOG_H
#define UI_EXCELDIALOG_H

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
#include <QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ExcelDialog
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *CountryBox;
    QLabel *CountryLabel;
    QMainWindow *window;
    QTableWidget *t;

    void setupUi(QDialog *ExcelDialog)
    {
        if (ExcelDialog->objectName().isEmpty())
            ExcelDialog->setObjectName(QStringLiteral("ExcelDialog"));
        ExcelDialog->resize(314, 215);
        buttonBox = new QDialogButtonBox(ExcelDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-90, 150, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        CountryBox = new QComboBox(ExcelDialog);
        CountryBox->setObjectName(QStringLiteral("CountryBox"));
        CountryBox->setGeometry(QRect(80, 80, 141, 31));
        CountryLabel = new QLabel(ExcelDialog);
        CountryLabel->setObjectName(QStringLiteral("CountryLabel"));
        CountryLabel->setGeometry(QRect(80, 50, 141, 20));

        retranslateUi(ExcelDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ExcelDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ExcelDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ExcelDialog);
    } // setupUi

    void retranslateUi(QDialog *ExcelDialog)
    {
        ExcelDialog->setWindowTitle(QApplication::translate("ExcelDialog", "ExcelDialog", Q_NULLPTR));
        CountryBox->clear();
        CountryBox->insertItems(0, QStringList()
         << QApplication::translate("ExcelDialog", "\344\270\226\347\225\214", Q_NULLPTR)
         << QApplication::translate("ExcelDialog", "\344\270\255\345\233\275", Q_NULLPTR)
         << QApplication::translate("ExcelDialog", "\346\227\245\346\234\254", Q_NULLPTR)
         << QApplication::translate("ExcelDialog", "\351\237\251\345\233\275", Q_NULLPTR)
         << QApplication::translate("ExcelDialog", "\350\222\231\345\217\244", Q_NULLPTR)
         << QApplication::translate("ExcelDialog", "\350\266\212\345\215\227", Q_NULLPTR)
         << QApplication::translate("ExcelDialog", "\346\263\260\345\233\275", Q_NULLPTR)
         << QApplication::translate("ExcelDialog", "\347\274\205\347\224\270", Q_NULLPTR)
         << QApplication::translate("ExcelDialog", "\350\200\201\346\214\235", Q_NULLPTR)
         << QApplication::translate("ExcelDialog", "\346\237\254\345\237\224\345\257\250", Q_NULLPTR)
         << QApplication::translate("ExcelDialog", "\351\251\254\346\235\245\350\245\277\344\272\232", Q_NULLPTR)
         << QApplication::translate("ExcelDialog", "\346\226\260\345\212\240\345\235\241", Q_NULLPTR)
         << QApplication::translate("ExcelDialog", "\345\215\260\345\272\246\345\260\274\350\245\277\344\272\232", Q_NULLPTR)
         << QApplication::translate("ExcelDialog", "\350\217\262\345\276\213\345\256\276", Q_NULLPTR)
         << QApplication::translate("ExcelDialog", "\346\276\263\345\244\247\345\210\251\344\272\232", Q_NULLPTR)
         << QApplication::translate("ExcelDialog", "\346\226\260\350\245\277\345\205\260", Q_NULLPTR)
        );
        CountryLabel->setText(QApplication::translate("ExcelDialog", "\351\200\211\346\213\251\351\234\200\350\246\201\346\237\245\350\257\242\347\232\204\345\233\275\345\256\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ExcelDialog: public Ui_ExcelDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXCELDIALOG_H
