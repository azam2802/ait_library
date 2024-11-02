#ifndef CLIENTS_H
#define CLIENTS_H

#include <QDialog>
#include "addclient.h"
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class clients;
}
QT_END_NAMESPACE

class clients : public QDialog
{
    Q_OBJECT

public:
    explicit clients(QWidget *parent = nullptr);
    ~clients();

private slots:
    void on_addClient_btn_clicked();
    void on_reports_btn_clicked();
    void on_deleteClient_btn_clicked();

public slots:
    void updateClients();

private:
    Ui::clients *ui;
    addClient *addClient;
    QSqlTableModel *model;
};

#endif // CLIENTS_H
