#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>

#include <dataservice.h>
#include <schedule.h>
#include <schedulemodel.h>
#include <editdialog.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initiateTable();
    void saveConfirm(QString message);

protected:
    bool event(QEvent *event);

public slots:
    void showAlert();
    void openDataFile();
    void saveData();
    void changeTable();
    void openEdit(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    Schedule *schedule;
};

#endif // MAINWINDOW_H
