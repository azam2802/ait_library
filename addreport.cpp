#include "addreport.h"
#include "ui_addreport.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>

addReport::addReport(QWidget* parent) : QDialog(parent), ui(new Ui::addReport)
{
  ui->setupUi(this);
  setModal(true);
  setWindowTitle("Add report");

  clientsModel = new QSqlQueryModel(this);
  booksModel = new QSqlQueryModel(this);

  createReportsTable();

  updateClients();  // Заполняем выпадающее меню клиентов
  updateBooks();    // Заполняем выпадающее меню книг
}

addReport::~addReport()
{
  delete ui;
}

void addReport::showEvent(QShowEvent* event)
{
  QDialog::showEvent(event);  // Вызов базового метода
  updateClients();            // Обновляем выпадающее меню клиентов
  updateBooks();              // Обновляем выпадающее меню книг
}

void addReport::createReportsTable()
{
  QSqlQuery query;
  QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS reports (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            client_name TEXT NOT NULL,
            book_title TEXT NOT NULL,
            report_date TEXT NOT NULL
        )
    )";

  if (!query.exec(createTableQuery))
  {
    qDebug() << "Ошибка создания таблицы reports:" << query.lastError().text();
  }
}

void addReport::updateClients()
{
  QSqlQuery query("SELECT name FROM clients");
  if (!query.exec())
  {
    qDebug() << "Ошибка выполнения запроса для клиентов:" << query.lastError().text();
    return;
  }
  clientsModel->setQuery(std::move(query));
  ui->clientsComboBox->setModel(clientsModel);
  ui->clientsComboBox->setModelColumn(0);  // Показываем имя клиента
}

void addReport::updateBooks()
{
  QSqlQuery query("SELECT title FROM books");
  if (!query.exec())
  {
    qDebug() << "Ошибка выполнения запроса для книг:" << query.lastError().text();
    return;
  }
  booksModel->setQuery(std::move(query));
  ui->booksComboBox->setModel(booksModel);
  ui->booksComboBox->setModelColumn(0);  // Показываем название книги
}

void addReport::on_addReportButton_clicked()
{
  // Получаем имя клиента и название книги из выпадающих меню
  QString clientName = clientsModel->index(ui->clientsComboBox->currentIndex(), 0).data().toString();
  QString bookTitle = booksModel->index(ui->booksComboBox->currentIndex(), 0).data().toString();

  QSqlQuery query;
  query.prepare(
      "INSERT INTO reports (client_name, book_title, report_date) VALUES (:client_name, :book_title, :report_date)");

  // Привязываем значения
  query.bindValue(":client_name", clientName);
  query.bindValue(":book_title", bookTitle);

  // Генерация текущей даты
  QString currentDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd");
  query.bindValue(":report_date", currentDateTime);

  // Выполнение запроса
  if (!query.exec())
  {
    qDebug() << "Ошибка добавления отчета:" << query.lastError().text();
  }
  else
  {
    qDebug() << "Отчет успешно добавлен!";
    emit addedReport();
    close();  // Закрываем окно после успешного добавления
  }
}
