/********************************************************************************
** Form generated from reading UI file 'select_graph_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECT_GRAPH_DIALOG_H
#define UI_SELECT_GRAPH_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Select_Graph_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *Select_Graph_Dialog)
    {
        if (Select_Graph_Dialog->objectName().isEmpty())
            Select_Graph_Dialog->setObjectName(QStringLiteral("Select_Graph_Dialog"));
        Select_Graph_Dialog->resize(503, 233);
        buttonBox = new QDialogButtonBox(Select_Graph_Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(140, 170, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Select_Graph_Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 50, 221, 16));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);

        retranslateUi(Select_Graph_Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Select_Graph_Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Select_Graph_Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Select_Graph_Dialog);
    } // setupUi

    void retranslateUi(QDialog *Select_Graph_Dialog)
    {
        Select_Graph_Dialog->setWindowTitle(QApplication::translate("Select_Graph_Dialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Select_Graph_Dialog", "\350\257\267\351\200\211\346\213\251\346\237\261\347\212\266\345\233\276\344\270\212\345\261\225\347\244\272\347\232\204\345\233\275\345\256\266/\345\234\260\345\214\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Select_Graph_Dialog: public Ui_Select_Graph_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECT_GRAPH_DIALOG_H
