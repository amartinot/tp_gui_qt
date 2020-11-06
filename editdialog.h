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
    Ui::EditDialog *ui;
    Activity activity;
    Schedule *schedule;
    QModelIndex index;

public slots:
    void save();
    void unassign();
};

#endif // EDITDIALOG_H
