#include "mainwindow.h"
#include "books.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  books = new class books(this);
  clients = new class clients(this);
  addReport = new class addReport(this);
  connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxSelectionChanged(int)));
  connect(ui->closeButton, &QPushButton::clicked, this, &MainWindow::close);

  setWindowTitle("American Institute of Technology. Library.");

  // Создаем модель для таблицы reports
  model = new QSqlTableModel(this);
  model->setTable("reports");  // Указываем таблицу
  model->select();             // Загружаем данные из таблицы

  // Устанавливаем модель в QTableView
  ui->tableView->setModel(model);

  model->setHeaderData(0, Qt::Horizontal, "ID");
  model->setHeaderData(1, Qt::Horizontal, "Client");
  model->setHeaderData(2, Qt::Horizontal, "Book");
  model->setHeaderData(3, Qt::Horizontal, "Date");

  calendarDialog = new QDialog(this);
  calendarDialog->setWindowFlags(Qt::Popup);  // Устанавливаем флаг, чтобы окно вело себя как всплывающее
  calendarWidget = new QCalendarWidget(calendarDialog);
  calendarWidget->setFixedSize(250, 200);

  QHeaderView* header = ui->tableView->horizontalHeader();
  header->setSectionResizeMode(QHeaderView::Stretch);  // Устанавливаем режим растяжения для всех столбцов

  connect(addReport, &addReport::addedReport, this, &MainWindow::updateReportTable);
  connect(ui->dateButton, &QPushButton::clicked, this, &MainWindow::showCalendar);
  connect(calendarWidget, &QCalendarWidget::clicked, this, &MainWindow::dateSelected);

  qDebug() << "Инициализация завершена";
}

MainWindow::~MainWindow()
{
  delete ui;
  delete books;
  delete clients;
  delete addReport;
}

void MainWindow::onComboBoxSelectionChanged(int index)
{
  if (index == 1)
  {
    ui->comboBox->setCurrentIndex(0);
    books->exec();
  }
  else if (index == 2)
  {
    ui->comboBox->setCurrentIndex(0);
    clients->exec();
  }
}

void MainWindow::on_addReport_btn_clicked()
{
  addReport->exec();
}

void MainWindow::updateReportTable()
{
  model->select();  // Refresh model
}

void MainWindow::showCalendar()
{
  // Показываем календарь рядом с кнопкой
  QPoint globalPos = ui->dateButton->mapToGlobal(QPoint(0, ui->dateButton->height()));
  calendarDialog->move(globalPos);
  calendarDialog->adjustSize();
  calendarDialog->show();
  qDebug() << "Всплывающее окно должно появиться на позиции:" << globalPos;
}

void MainWindow::dateSelected()
{
  // Получаем выбранную дату
  QDate selectedDate = calendarWidget->selectedDate();

  // Скрываем календарь
  calendarDialog->hide();

  // Фильтруем данные в таблице reports на основе выбранной даты
  filterReportsByDate(selectedDate);
}

void MainWindow::filterReportsByDate(const QDate& date)
{
  // Получаем модель данных таблицы
  QAbstractItemModel* model = ui->tableView->model();
  if (!model)
    return;

  // Перебираем строки таблицы и скрываем те, которые не соответствуют выбранной дате
  for (int row = 0; row < model->rowCount(); ++row)
  {
    // Предположим, что дата хранится в первом столбце (колонка 0)
    QModelIndex index = model->index(row, 3);
    QDate rowDate = index.data().toDate();

    // Сравниваем дату строки с выбранной датой
    bool match = (rowDate == date);
    qDebug() << rowDate;
    qDebug() << date;
    // Показываем строку, если даты совпадают, иначе скрываем
    ui->tableView->setRowHidden(row, !match);
  }
}

void MainWindow::on_deleteReport_clicked()
{
  int currentRow = ui->tableView->currentIndex().row();
  if (currentRow >= 0)
  {
    QModelIndex index = model->index(currentRow, 0);
    int id = index.data().toInt();
    QString affirmText = QString("Are you sure you want to delete report %1?").arg(id);
    QMessageBox::StandardButton affirmation =
        QMessageBox::question(this, "Attention", affirmText, QMessageBox::Yes | QMessageBox::No);
    if (affirmation == QMessageBox::Yes)
    {
      QSqlQuery query;
      query.prepare("DELETE FROM reports WHERE id = :id");
      query.bindValue(":id", id);

      if (query.exec())
      {
        qDebug() << "Запись успешно удалена!";
        updateReportTable();
        QMessageBox::information(this, "Success!", "Report deleted.");
      }
      else
      {
        QMessageBox::critical(this, "Error!", "Unexpected error occured!");
      }
    }
    else
    {
      return;
    }
  }
  else
  {
    QMessageBox::warning(this, "Row not selected.", "Choose report to delete.");
  }
}
