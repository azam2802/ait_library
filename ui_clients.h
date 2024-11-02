/********************************************************************************
** Form generated from reading UI file 'clients.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTS_H
#define UI_CLIENTS_H

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

class Ui_clients
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *addClient_btn;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *deleteClient_btn;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *reports_btn;
    QSpacerItem *verticalSpacer;
    QTableView *tableView;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *clients)
    {
        if (clients->objectName().isEmpty())
            clients->setObjectName("clients");
        clients->resize(712, 385);
        gridLayout = new QGridLayout(clients);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        addClient_btn = new QPushButton(clients);
        addClient_btn->setObjectName("addClient_btn");
        QFont font;
        font.setPointSize(12);
        addClient_btn->setFont(font);

        horizontalLayout_2->addWidget(addClient_btn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        deleteClient_btn = new QPushButton(clients);
        deleteClient_btn->setObjectName("deleteClient_btn");
        deleteClient_btn->setFont(font);

        horizontalLayout_2->addWidget(deleteClient_btn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 3);

        reports_btn = new QPushButton(clients);
        reports_btn->setObjectName("reports_btn");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(reports_btn->sizePolicy().hasHeightForWidth());
        reports_btn->setSizePolicy(sizePolicy);
        reports_btn->setFont(font);

        gridLayout->addWidget(reports_btn, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 2);

        tableView = new QTableView(clients);
        tableView->setObjectName("tableView");

        gridLayout->addWidget(tableView, 6, 0, 1, 3);

        label = new QLabel(clients);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label, 1, 0, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 4, 0, 1, 3);


        retranslateUi(clients);

        QMetaObject::connectSlotsByName(clients);
    } // setupUi

    void retranslateUi(QDialog *clients)
    {
        clients->setWindowTitle(QCoreApplication::translate("clients", "Dialog", nullptr));
        addClient_btn->setText(QCoreApplication::translate("clients", "Add client", nullptr));
        deleteClient_btn->setText(QCoreApplication::translate("clients", "Delete client", nullptr));
        reports_btn->setText(QCoreApplication::translate("clients", "Reports", nullptr));
        label->setText(QCoreApplication::translate("clients", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt;\">Clients</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class clients: public Ui_clients {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTS_H
