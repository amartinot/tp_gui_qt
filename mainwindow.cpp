#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("School Planner");
    schedule = new Schedule();
    DataService *dataService = new DataService();

    initiateTable();
    // à enlever
    dataService->loadData("/home/amartinot/Documents/WUT/GUI/tp_qt/tp_gui/data/data.json", schedule);
    ui->roomsComboBox->addItems(schedule->getRooms());

    delete dataService;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->schedule;
}

void MainWindow::showAlert()
{
    QMessageBox Msgbox;
    Msgbox.setText("boutton cliqué");
    Msgbox.exec();
}

void MainWindow::openDataFile()
{
    DataService *dataService = new DataService();
    if (!schedule->saveIsUptodate() && schedule->containsData()) {
        saveConfirm("Do you want to save your data before loading new ones");
    }

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Data"), dataService->getParentDirectory(), tr("Json Files (*.json)"));

    dataService->loadData(fileName, schedule);
    ui->roomsComboBox->clear();
    ui->roomsComboBox->addItems(schedule->getRooms());

    delete dataService;
}

void MainWindow::saveData()
{
   DataService dataService;
   QString fileName = QFileDialog::getSaveFileName(this, tr("Save Data"), dataService.getParentDirectory(), tr("Json Files (*.json)"));
   if (!fileName.endsWith(".json")) {
       fileName += ".json";
   }

   dataService.saveData(fileName, schedule);
}

void MainWindow::initiateTable()
{
    ui->roomsComboBox->addItems(schedule->getRooms());
    schedule->setCurrentRoom(ui->roomsComboBox->currentText());

    ScheduleModel *model = new ScheduleModel(schedule, ui->roomsComboBox->currentText(), this);

    ui->scheduleTable->setModel(model);       
    ui->scheduleTable->show();
}

void MainWindow::changeTable() {
    schedule->setCurrentRoom(ui->roomsComboBox->currentText());
    ScheduleModel *model = new ScheduleModel(schedule, ui->roomsComboBox->currentText(), this);

    ui->scheduleTable->setModel(model);
    ui->scheduleTable->show();
}

void MainWindow::openEdit(const QModelIndex &index) {
    EditDialog* editDialog = new EditDialog(schedule, index);
    editDialog->exec();
}

void MainWindow::saveConfirm(QString message) {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Save ?", message, QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        saveData();
    }
}

bool MainWindow::event(QEvent* e)
{
    switch (e->type())
    {
        case QEvent::FocusIn:
            changeTable();
            break;
        case QEvent::Close:
            if (!schedule->saveIsUptodate()){
                saveConfirm("Do you want to save your data ?");
            }
            break;
        default:
            break;
    };
    return QMainWindow::event(e);
}


