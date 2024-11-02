#include "addbook.h"
#include "qmessagebox.h"
#include "ui_addbook.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

addBook::addBook(QWidget* parent) : QDialog(parent), ui(new Ui::addBook)
{
  ui->setupUi(this);
  setWindowTitle("Add book");
  setModal(true);
  initializeDatabase();
  connect(ui->addButton, &QPushButton::clicked, this, &addBook::onAddBookClicked);
  setFixedSize(300, 300);
}

addBook::~addBook()
{
  delete ui;
}

void addBook::initializeDatabase()
{
  // Подключаемся к SQLite базе данных
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("library.db");

  if (!db.open())
  {
    qDebug() << "Ошибка открытия базы данных:" << db.lastError().text();
    return;
  }

  // Создаем таблицу для книг, если она еще не создана
  QSqlQuery query;
  QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS books (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            title TEXT NOT NULL
        )
    )";

  if (!query.exec(createTableQuery))
  {
    qDebug() << "Ошибка создания таблицы книг:" << query.lastError().text();
  }
}

bool addBook::addbooks(const QString& title)
{
  QSqlQuery query;
  query.prepare("INSERT INTO books (title) VALUES (:title)");
  query.bindValue(":title", title);

  if (!query.exec())
  {
    qDebug() << "Ошибка добавления книги:" << query.lastError().text();
    return false;
  }
  ui->titleLineEdit->clear();  // Очистка поля ввода
  emit bookAdded();            // Сигнализируем об успешном добавлении
  qDebug() << "Книга успешно добавлена!";
  return true;
}

void addBook::onAddBookClicked()
{
  // Получаем данные из UI
  QString title = ui->titleLineEdit->text();
  if (title != "")
  {
    if (addbooks(title))
    {
      qDebug() << "Запись добавлена успешно";
      close();
    }
    else
    {
      qDebug() << "Не удалось добавить запись";
      close();
    }
  }
  else
  {
    QMessageBox::warning(this, "Empty title.", "Title line can't be empty!");
  }
}
