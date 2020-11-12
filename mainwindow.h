#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>

#include <dataservice.h>
#include <schedule.h>
#include <schedulemodel.h>
#include <editdialog.h>
#include <editdictionary.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

    // Method to initiate the TableView with our schedule data
    void initiateTable();

    // Method to ask the user if he want to save
    void saveConfirm(QString message);

protected:
    // Method to handle the focus event
    void changeEvent(QEvent *event);

    // Method to handle all the others events
    bool event(QEvent *event);

public slots:
    // Slot to open a data file for the loading
    void openDataFile();

    // Slot to open a data file for the saving
    void saveData();

    // Slot to change the tableView content when the value of the rooms combobox change
    void changeTable();

    // Slot to open the edit activity dialog when the user double-clicked in a cell of the tableView
    void openEditActivity(const QModelIndex &index);

    // Slot to open the edit rooms dialog
    void openEditRooms();

     // Slot to open the edit groups dialog
    void openEditGroups();

     // Slot to open the edit classes dialog
    void openEditClasses();

     // Slot to open the edit taechers dialog
    void openEditTeachers();

private:
    Ui::MainWindow *ui;

    Schedule *schedule;
};

#endif // MAINWINDOW_H
