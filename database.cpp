#include "database.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool Database::connect()
{
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("library.db");  // Имя файла базы данных

  if (!db.open())
  {
    qDebug() << "Не удалось подключиться к базе данных:" << db.lastError().text();
    return false;
  }

  // Создаем таблицу "books", если она не существует
  QSqlQuery query;
  QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS books (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            title TEXT NOT NULL,
        )
    )";

  if (!query.exec(createTableQuery))
  {
    qDebug() << "Не удалось создать таблицу 'books':" << query.lastError().text();
    return false;
  }

  return true;
}
