#ifndef ADDBOOK_H
#define ADDBOOK_H
#include <QSqlTableModel>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui
{
class addBook;
}
QT_END_NAMESPACE

class addBook : public QDialog
{
  Q_OBJECT

public:
  explicit addBook(QWidget* parent = nullptr);
  ~addBook();

private slots:
  void onAddBookClicked();

  // void on_addButton_clicked();

signals:
  void bookAdded();

private:
  Ui::addBook* ui;
  bool addbooks(const QString& title);
  void initializeDatabase();
  QSqlTableModel* model;  // Модель для таблицы
};

#endif  // ADDBOOK_H
