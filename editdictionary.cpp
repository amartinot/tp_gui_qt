#include "editdictionary.h"
#include "ui_editdictionary.h"

EditDictionary::EditDictionary(Schedule *schedule, QString dataToEdit, QWidget *parent) :
    schedule(schedule),
    dataToEdit(dataToEdit),
    QDialog(parent),
    ui(new Ui::EditDictionary)
{
    ui->setupUi(this);
    setDataList();
    ui->dataList->addItems(dataList);
}

EditDictionary::~EditDictionary()
{
    delete ui;
}

void EditDictionary::setDataList()
{
    if (dataToEdit == "rooms") {
        dataList = schedule->getRooms();
    } else if (dataToEdit == "groups") {
        dataList = schedule->getGroups();
    } else if (dataToEdit == "classes") {
        dataList = schedule->getCourses();
    } else if (dataToEdit == "teachers") {
        dataList = schedule->getTeachers();
    }
}

void EditDictionary::add()
{
    bool ok;
    QString value = QInputDialog::getText(this, tr("Enter new value"),dataToEdit, QLineEdit::Normal,"", &ok);
    if (ok) {
        dataList.append(value);
        ui->dataList->addItem(value);

        schedule->setUptodateSave(false);
    }
}

void EditDictionary::remove()
{
    QList<QListWidgetItem*> items = ui->dataList->selectedItems();

    if (items.size() > 0) {
        foreach(QListWidgetItem* item, items){
            dataList.removeOne(item->text());
            ui->dataList->removeItemWidget(item);
            delete item;
        }

        schedule->setUptodateSave(false);
    }

}

void EditDictionary::saveAndClose()
{
    if (dataToEdit == "rooms") {
        schedule->setRooms(dataList);
    } else if (dataToEdit == "groups") {
        schedule->setGroups(dataList);
    } else if (dataToEdit == "classes") {
        schedule->setCourses(dataList);
    } else if (dataToEdit == "teachers") {
        schedule->setTeachers(dataList);
    }

    close();
}
