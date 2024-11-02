#ifndef BOOKS_H
#define BOOKS_H

#include <QDialog>
#include "addbook.h"
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class books;
}
QT_END_NAMESPACE

class books : public QDialog
{
    Q_OBJECT

public:
    explicit books(QWidget *parent = nullptr);
    ~books();

private slots:
    void on_addBook_btn_clicked();
    void on_reports_btn_clicked();
    void on_deleteBook_btn_clicked();

public slots:
    void updateBooks();

private:
    Ui::books *ui;
    addBook *addBook;
    QSqlTableModel *model; // Модель для таблицы
};

#endif // BOOKS_H
