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

public slots:
    void setDataList();
    void add();
    void remove();
    void saveAndClose();

private:
    Ui::EditDictionary *ui;
    Schedule *schedule;
    QString dataToEdit;
    QList<QString> dataList;
};

#endif // EDITDICTIONARY_H
