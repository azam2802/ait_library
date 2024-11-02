#include "clients.h"
#include "ui_clients.h"
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

clients::clients(QWidget* parent) : QDialog(parent), ui(new Ui::clients)
{
  ui->setupUi(this);
  setModal(true);
  setWindowTitle("Clients");
  addClient = new class addClient;

  model = new QSqlTableModel(this);
  model->setTable("clients");  // Указываем таблицу
  model->select();             // Загружаем данные из таблицы
  setMinimumSize(582, 445);
  // Устанавливаем модель в QTableView
  ui->tableView->setModel(model);

  QHeaderView* header = ui->tableView->horizontalHeader();
  header->setSectionResizeMode(QHeaderView::Stretch);  // Устанавливаем режим растяжения для всех столбцов

  // Дополнительные настройки
  ui->tableView->resizeColumnsToContents();  // Автоматически подгоняем ширину столбцов
}

clients::~clients()
{
  delete ui;
}

void clients::on_addClient_btn_clicked()
{
  connect(addClient, &addClient::clientAdded, this, &clients::updateClients);  // Подключаем сигнал к слоту
  addClient->exec();
}

void clients::on_reports_btn_clicked()
{
  close();
}

void clients::updateClients()
{
  model->select();  // Обновляем данные модели
}

void clients::on_deleteClient_btn_clicked()
{
  int currentRow = ui->tableView->currentIndex().row();
  if (currentRow >= 0)
  {
    QModelIndex name = model->index(currentRow, 1);
    QString affirmText = QString("Are you sure you want to delete client %1?").arg(name.data().toString());
    QMessageBox::StandardButton affirmation =
        QMessageBox::question(this, "Attention", affirmText, QMessageBox::Yes | QMessageBox::No);
    if (affirmation == QMessageBox::Yes)
    {
      QModelIndex index = model->index(currentRow, 0);
      int id = index.data().toInt();

      QSqlQuery query;
      query.prepare("DELETE FROM clients WHERE id = :id");
      query.bindValue(":id", id);

      if (query.exec())
      {
        updateClients();
        QMessageBox::information(this, "Success", "Client deleted successfully");
        qDebug() << "Клиент успешно удален!";
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
    QMessageBox::warning(this, "Client not selected.", "Choose client to delete him.");
    qDebug() << "Нет выделенного клиента для удаления.";
  }
}
