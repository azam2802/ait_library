#include "books.h"
#include "ui_books.h"
#include "addbook.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

books::books(QWidget* parent) : QDialog(parent), ui(new Ui::books)
{
  ui->setupUi(this);
  setModal(true);
  setWindowTitle("Books");
  addBook = new class addBook;

  model = new QSqlTableModel(this);
  model->setTable("books");  // Указываем таблицу
  model->select();           // Загружаем данные из таблицы
  setMinimumSize(582, 445);
  // Устанавливаем модель в QTableView
  ui->tableView->setModel(model);

  QHeaderView* header = ui->tableView->horizontalHeader();
  header->setSectionResizeMode(QHeaderView::Stretch);  // Устанавливаем режим растяжения для всех столбцов
  connect(addBook, &addBook::bookAdded, this, &books::updateBooks);
  // Дополнительные настройки
  ui->tableView->resizeColumnsToContents();  // Автоматически подгоняем ширину столбцов
}

books::~books()
{
  delete ui;
}

void books::on_addBook_btn_clicked()
{
  addBook->exec();
}

void books::on_reports_btn_clicked()
{
  close();
}

void books::updateBooks()
{
  model->select();  // Обновляем данные модели
}

void books::on_deleteBook_btn_clicked()
{
  int currentRow = ui->tableView->currentIndex().row();
  if (currentRow >= 0)
  {
    QModelIndex index = model->index(currentRow, 0);  // Предполагается, что первый столбец - это ID
    int id = index.data().toInt();

    QString affirmText = QString("Are you sure you want to delete book %1?").arg(id);
    QMessageBox::StandardButton affirmation =
        QMessageBox::question(this, "Attention", affirmText, QMessageBox::Yes | QMessageBox::No);

    if (affirmation == QMessageBox::Yes)
    {
      QSqlQuery query;
      query.prepare("DELETE FROM books WHERE id = :id");
      query.bindValue(":id", id);

      if (query.exec())
      {
        updateBooks();
        QMessageBox::information(this, "Success", "Book was deleted successfully!");
      }
      else
      {
        QMessageBox::critical(this, "Error!", "Unexpected error occured!");
        qDebug() << "Ошибка удаления книги:" << query.lastError().text();
      }
    }
    else
    {
      return;
    }
  }
  else
  {
    QMessageBox::warning(this, "Book not selected", "Choose the book to delete it.");
    qDebug() << "Нет выделенной книги для удаления.";
  }
}
