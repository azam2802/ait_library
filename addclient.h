#ifndef ADDCLIENT_H
#define ADDCLIENT_H
#include <QSqlTableModel>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class addClient;
}
QT_END_NAMESPACE

class addClient : public QDialog
{
    Q_OBJECT

public:
    explicit addClient(QWidget *parent = nullptr);
    ~addClient();

private slots:
    void onAddClientClicked();

signals:
    void clientAdded();

private:
    Ui::addClient *ui;
    bool addclients(const QString &name);
    void initializeDatabase();
    QSqlTableModel *model;
};

#endif // ADDCLIENT_H
