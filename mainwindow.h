#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "books.h"
#include <QSqlTableModel>
#include "clients.h"
#include "addreport.h"
#include <QCalendarWidget>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

private slots:
  void onComboBoxSelectionChanged(int index);
  void on_addReport_btn_clicked();
  void updateReportTable();
  void on_deleteReport_clicked();
  void showCalendar();
  void dateSelected();

private:
  Ui::MainWindow* ui;
  books* books;
  clients* clients;
  void setupModelAndView();
  void filterReportsByDate(const QDate& date);
  QDialog* calendarDialog;          // Всплывающее окно для календаря
  QCalendarWidget* calendarWidget;  // Сам календарь
  QSqlTableModel* model;
  addReport* addReport;
};
#endif  // MAINWINDOW_H
