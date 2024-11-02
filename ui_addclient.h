/********************************************************************************
** Form generated from reading UI file 'addclient.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCLIENT_H
#define UI_ADDCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_addClient
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *addButton;
    QSpacerItem *verticalSpacer_4;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *titleNameEdit;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *addClient)
    {
        if (addClient->objectName().isEmpty())
            addClient->setObjectName("addClient");
        addClient->resize(408, 332);
        gridLayout = new QGridLayout(addClient);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(addClient);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 1, 0, 1, 4);

        addButton = new QPushButton(addClient);
        addButton->setObjectName("addButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(12);
        addButton->setFont(font);

        gridLayout->addWidget(addButton, 4, 1, 1, 2);

        verticalSpacer_4 = new QSpacerItem(20, 60, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(verticalSpacer_4, 3, 1, 1, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        label_2 = new QLabel(addClient);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        titleNameEdit = new QLineEdit(addClient);
        titleNameEdit->setObjectName("titleNameEdit");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(titleNameEdit->sizePolicy().hasHeightForWidth());
        titleNameEdit->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(titleNameEdit, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(5, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 2, 0, 1, 4);

        horizontalSpacer_3 = new QSpacerItem(100, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 4, 3, 1, 1);

        verticalSpacer = new QSpacerItem(388, 17, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 4);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 100, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 5, 1, 1, 2);


        retranslateUi(addClient);

        QMetaObject::connectSlotsByName(addClient);
    } // setupUi

    void retranslateUi(QDialog *addClient)
    {
        addClient->setWindowTitle(QCoreApplication::translate("addClient", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("addClient", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt;\">ADD CLIENT</span></p></body></html>", nullptr));
        addButton->setText(QCoreApplication::translate("addClient", "Submit", nullptr));
        label_2->setText(QCoreApplication::translate("addClient", "Client:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addClient: public Ui_addClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCLIENT_H
