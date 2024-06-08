/********************************************************************************
** Form generated from reading UI file 'graphdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHDIALOG_H
#define UI_GRAPHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include "mycombobox.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE

class Ui_GraphDialog
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox;
    QLabel *label;
    QLabel *label_2;
    MultiSelectComboBox *MSCB;
    QMainWindow *window;

    void setupUi(QDialog *GraphDialog)
    {
        if (GraphDialog->objectName().isEmpty())
            GraphDialog->setObjectName(QStringLiteral("GraphDialog"));
        GraphDialog->resize(284, 240);
        buttonBox = new QDialogButtonBox(GraphDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(40, 190, 201, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboBox = new QComboBox(GraphDialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(40, 60, 200, 25));
        label = new QLabel(GraphDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 30, 171, 20));
        label_2 = new QLabel(GraphDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 100, 211, 20));
        MSCB = new MultiSelectComboBox(GraphDialog);
        MSCB->setObjectName(QStringLiteral("SelectBox"));
        MSCB->setGeometry(QRect(40, 130, 200, 25));

        retranslateUi(GraphDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), GraphDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GraphDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(GraphDialog);
    } // setupUi

    void retranslateUi(QDialog *GraphDialog)
    {
        GraphDialog->setWindowTitle(QApplication::translate("GraphDialog", "Dialog", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("GraphDialog", "\347\241\256\350\257\212\347\227\205\344\276\213", Q_NULLPTR)
         << QApplication::translate("GraphDialog", "\346\226\260\345\242\236\347\241\256\350\257\212\347\227\205\344\276\213", Q_NULLPTR)
         << QApplication::translate("GraphDialog", "\345\272\267\345\244\215\347\227\205\344\276\213", Q_NULLPTR)
         << QApplication::translate("GraphDialog", "\346\226\260\345\242\236\345\272\267\345\244\215\347\227\205\344\276\213", Q_NULLPTR)
         << QApplication::translate("GraphDialog", "\346\255\273\344\272\241\347\227\205\344\276\213", Q_NULLPTR)
         << QApplication::translate("GraphDialog", "\346\226\260\345\242\236\346\255\273\344\272\241\347\227\205\344\276\213", Q_NULLPTR)
        );
        label->setText(QApplication::translate("GraphDialog", "\350\257\267\350\276\223\345\205\245\351\234\200\350\246\201\345\217\257\350\247\206\345\214\226\347\232\204\351\241\271\347\233\256", Q_NULLPTR));
        label_2->setText(QApplication::translate("GraphDialog", "\350\257\267\350\276\223\345\205\245\351\234\200\350\246\201\345\217\257\350\247\206\345\214\226\347\232\204\345\233\275\345\256\266/\345\234\260\345\214\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GraphDialog: public Ui_GraphDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHDIALOG_H
