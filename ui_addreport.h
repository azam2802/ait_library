/********************************************************************************
** Form generated from reading UI file 'addreport.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDREPORT_H
#define UI_ADDREPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_addReport
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *clientsComboBox;
    QComboBox *booksComboBox;
    QPushButton *addReportButton;
    QSpacerItem *verticalSpacer_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *addReport)
    {
        if (addReport->objectName().isEmpty())
            addReport->setObjectName("addReport");
        addReport->setEnabled(true);
        addReport->resize(430, 354);
        gridLayout = new QGridLayout(addReport);
        gridLayout->setObjectName("gridLayout");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalSpacer_4 = new QSpacerItem(5, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(5, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 1, 1, 1);

        label_2 = new QLabel(addReport);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(addReport);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        clientsComboBox = new QComboBox(addReport);
        clientsComboBox->setObjectName("clientsComboBox");

        gridLayout_2->addWidget(clientsComboBox, 1, 2, 1, 2);

        booksComboBox = new QComboBox(addReport);
        booksComboBox->setObjectName("booksComboBox");

        gridLayout_2->addWidget(booksComboBox, 2, 2, 1, 2);


        gridLayout->addLayout(gridLayout_2, 2, 1, 1, 3);

        addReportButton = new QPushButton(addReport);
        addReportButton->setObjectName("addReportButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addReportButton->sizePolicy().hasHeightForWidth());
        addReportButton->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(12);
        addReportButton->setFont(font);

        gridLayout->addWidget(addReportButton, 5, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(verticalSpacer_4, 4, 2, 1, 1);

        label = new QLabel(addReport);
        label->setObjectName("label");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(100, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 5, 3, 1, 1);

        verticalSpacer = new QSpacerItem(388, 17, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 5, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 100, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 6, 2, 1, 1);


        retranslateUi(addReport);

        QMetaObject::connectSlotsByName(addReport);
    } // setupUi

    void retranslateUi(QDialog *addReport)
    {
        addReport->setWindowTitle(QCoreApplication::translate("addReport", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("addReport", "Client:", nullptr));
        label_3->setText(QCoreApplication::translate("addReport", "Book:", nullptr));
        addReportButton->setText(QCoreApplication::translate("addReport", "Submit", nullptr));
        label->setText(QCoreApplication::translate("addReport", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt;\">ADD REPORT</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addReport: public Ui_addReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDREPORT_H
