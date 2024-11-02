/********************************************************************************
** Form generated from reading UI file 'books.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKS_H
#define UI_BOOKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_books
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *addBook_btn;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *deleteBook_btn;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *reports_btn;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *books)
    {
        if (books->objectName().isEmpty())
            books->setObjectName("books");
        books->resize(631, 445);
        gridLayout = new QGridLayout(books);
        gridLayout->setObjectName("gridLayout");
        tableView = new QTableView(books);
        tableView->setObjectName("tableView");

        gridLayout->addWidget(tableView, 5, 0, 1, 5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(3, -1, -1, -1);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        addBook_btn = new QPushButton(books);
        addBook_btn->setObjectName("addBook_btn");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addBook_btn->sizePolicy().hasHeightForWidth());
        addBook_btn->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        addBook_btn->setFont(font);

        horizontalLayout->addWidget(addBook_btn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        deleteBook_btn = new QPushButton(books);
        deleteBook_btn->setObjectName("deleteBook_btn");
        sizePolicy.setHeightForWidth(deleteBook_btn->sizePolicy().hasHeightForWidth());
        deleteBook_btn->setSizePolicy(sizePolicy);
        deleteBook_btn->setFont(font);

        horizontalLayout->addWidget(deleteBook_btn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label = new QLabel(books);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 5);

        reports_btn = new QPushButton(books);
        reports_btn->setObjectName("reports_btn");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(reports_btn->sizePolicy().hasHeightForWidth());
        reports_btn->setSizePolicy(sizePolicy1);
        reports_btn->setFont(font);

        gridLayout->addWidget(reports_btn, 0, 4, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 4, 0, 1, 5);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 4);


        retranslateUi(books);

        QMetaObject::connectSlotsByName(books);
    } // setupUi

    void retranslateUi(QDialog *books)
    {
        books->setWindowTitle(QCoreApplication::translate("books", "Dialog", nullptr));
        addBook_btn->setText(QCoreApplication::translate("books", "Add book", nullptr));
        deleteBook_btn->setText(QCoreApplication::translate("books", "Delete book", nullptr));
        label->setText(QCoreApplication::translate("books", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt;\">BOOKS</span></p></body></html>", nullptr));
        reports_btn->setText(QCoreApplication::translate("books", "Reports", nullptr));
    } // retranslateUi

};

namespace Ui {
    class books: public Ui_books {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKS_H
