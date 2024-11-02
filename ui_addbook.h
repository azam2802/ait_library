/********************************************************************************
** Form generated from reading UI file 'addbook.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBOOK_H
#define UI_ADDBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_addBook
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *addButton;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QLineEdit *titleLineEdit;
    QLabel *label;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *addBook)
    {
        if (addBook->objectName().isEmpty())
            addBook->setObjectName("addBook");
        addBook->resize(312, 259);
        gridLayout = new QGridLayout(addBook);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer_2 = new QSpacerItem(20, 100, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 5, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 0, 1, 1);

        addButton = new QPushButton(addBook);
        addButton->setObjectName("addButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        addButton->setFont(font);

        gridLayout->addWidget(addButton, 4, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(100, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 4, 2, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        label_3 = new QLabel(addBook);
        label_3->setObjectName("label_3");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        titleLineEdit = new QLineEdit(addBook);
        titleLineEdit->setObjectName("titleLineEdit");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(titleLineEdit->sizePolicy().hasHeightForWidth());
        titleLineEdit->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(titleLineEdit, 0, 2, 1, 1);


        gridLayout->addLayout(gridLayout_2, 3, 0, 1, 3);

        label = new QLabel(addBook);
        label->setObjectName("label");

        gridLayout->addWidget(label, 2, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 3);


        retranslateUi(addBook);

        QMetaObject::connectSlotsByName(addBook);
    } // setupUi

    void retranslateUi(QDialog *addBook)
    {
        addBook->setWindowTitle(QCoreApplication::translate("addBook", "Dialog", nullptr));
        addButton->setText(QCoreApplication::translate("addBook", "Submit", nullptr));
        label_3->setText(QCoreApplication::translate("addBook", "Book:", nullptr));
        label->setText(QCoreApplication::translate("addBook", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt;\">ADD BOOK</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addBook: public Ui_addBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBOOK_H
