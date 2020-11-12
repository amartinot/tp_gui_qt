#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>
#include <QModelIndex>

#include <schedule.h>

namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDialog(Schedule *schedule, const QModelIndex &index, QWidget *parent = 0);

    ~EditDialog();

private:  
    Activity activity;

    Schedule *schedule;

    QModelIndex index;

    Ui::EditDialog *ui;

public slots:
    // Slot to save an activity
    void save();

    // Slot to unassign an activity
    void unassign();
};

#endif // EDITDIALOG_H
