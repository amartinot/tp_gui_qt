#ifndef EDITDICTIONARY_H
#define EDITDICTIONARY_H

#include <QDialog>
#include <QInputDialog>

#include <schedule.h>

namespace Ui {
class EditDictionary;
}

class EditDictionary : public QDialog
{
    Q_OBJECT

public:
    explicit EditDictionary(Schedule *schedule, QString dataToEdit, QWidget *parent = 0);

    ~EditDictionary();

    // Method to set the DataList of this dialog from our application schedule
    void setDataList();

public slots:
    // Slot to add a new item
    void add();

    // Slot to remove an item
    void remove();

    // Slot to save the new items in our apllication schedule an dclose the dialog
    void saveAndClose();

private:
    Ui::EditDictionary *ui;

    Schedule *schedule;

    QString dataToEdit;

    QList<QString> dataList;
};

#endif // EDITDICTIONARY_H
