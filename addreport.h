#ifndef ADDREPORT_H
#define ADDREPORT_H

#include <QDialog>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class addReport;
}
QT_END_NAMESPACE

class addReport : public QDialog
{
    Q_OBJECT

public:
    explicit addReport(QWidget *parent = nullptr);
    ~addReport();

private slots:
    void on_addReportButton_clicked();
    void updateClients(); // Обновление списка клиентов
    void updateBooks();   // Обновление списка книг

protected:
    void showEvent(QShowEvent *event) override;

signals:
    void addedReport();

private:
    Ui::addReport *ui;
    void createReportsTable();
    QSqlQueryModel *clientsModel; // Модель для клиентов
    QSqlQueryModel *booksModel;   // Модель для книг

};


#endif // ADDREPORT_H
