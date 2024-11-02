#include "addclient.h"
#include "ui_addclient.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

addClient::addClient(QWidget* parent) : QDialog(parent), ui(new Ui::addClient)
{
  ui->setupUi(this);
  setWindowTitle("Add client");
  setModal(true);
  initializeDatabase();
  connect(ui->addButton, &QPushButton::clicked, this, &addClient::onAddClientClicked);
  setFixedSize(300, 300);
}

addClient::~addClient()
{
  delete ui;
}

void addClient::initializeDatabase()
{
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("library.db");
  if (!db.open())
  {
    qDebug() << "Ошибка открытия базы данных:" << db.lastError().text();
    return;
  }

  QSqlQuery query;
  QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS clients (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL
        )
    )";

  if (!query.exec(createTableQuery))
  {
    qDebug() << "Ошибка создания таблицы клиентов:" << query.lastError().text();
  }
}

bool addClient::addclients(const QString& name)
{
  QSqlQuery query;
  query.prepare("INSERT INTO clients (name) VALUES (:name)");
  query.bindValue(":name", name);

  if (!query.exec())
  {
    qDebug() << "Ошибка добавления клиента:" << query.lastError().text();
    return false;
  }

  ui->titleNameEdit->clear();  // Очистка поля ввода
  emit clientAdded();          // Сигнализируем об успешном добавлении
  qDebug() << "Клиент успешно добавлен!";
  return true;
}

void addClient::onAddClientClicked()
{
  // Получаем данные из UI
  QString name = ui->titleNameEdit->text();
  qDebug() << name;
  // Добавляем книгу в базу данных
  if (name != "")
  {
    if (addclients(name))
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
    QMessageBox::warning(this, "Empty name", "Name line can't be empty");
  }
}
