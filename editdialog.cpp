#include "editdialog.h"
#include "ui_editdialog.h"

EditDialog::EditDialog(Schedule *schedule, const QModelIndex &index, QWidget *parent) :
    schedule(schedule),
    QDialog(parent),
    index(index),
    ui(new Ui::EditDialog)
{
    ui->setupUi(this);
    setWindowTitle("Edit entry");

    ui->roomNumber->setText(schedule->getCurrentRoom());
    ui->classComboBox->addItems(schedule->getGroups());
    ui->courseComboBox->addItems(schedule->getCourses());
    ui->teacherComboBox->addItems(schedule->getTeachers());

    int activitySlot = index.column() * schedule->getHours().size() + index.row();
    if (index.data().toString() != "") {
        // TODO: show unasigned button
        activity = schedule->getActivities().value(QPair<int, QString>(activitySlot, schedule->getCurrentRoom()));
        ui->classComboBox->setCurrentText(activity.getGroup());
        ui->courseComboBox->setCurrentText(activity.getCourse());
        ui->teacherComboBox->setCurrentText(activity.getTeacher());

    } else {
        activity = Activity(activitySlot, schedule->getCurrentRoom());
    }
}

EditDialog::~EditDialog()
{
    delete ui;
}

void EditDialog::save() {
    activity.setCourse(ui->courseComboBox->currentText());
    activity.setGroup(ui->classComboBox->currentText());
    activity.setTeacher(ui->teacherComboBox->currentText());

    schedule->addActivity(activity);
    schedule->setUptodateSave(false);

    close();
}

void EditDialog::unassign() {
    schedule->deleteActivity(activity);
    schedule->setUptodateSave(false);

    close();
}
