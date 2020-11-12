#ifndef SCHEDULEMODEL_H
#define SCHEDULEMODEL_H

#include <QAbstractTableModel>

#include <schedule.h>
#include <activity.h>

class ScheduleModel : public QAbstractTableModel
{
public:
    ScheduleModel(Schedule *schedule, QString room, QObject *parent=0);

    // Method to return number of rows
    int rowCount(const QModelIndex &parent) const;

    // method to return number of columns
    int columnCount(const QModelIndex &parent) const;

    // Method to filled the tableView
    QVariant data(const QModelIndex &index, int role) const override;

    // Method to set the header
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

private:
    Schedule *schedule;

    QString room;
};

#endif // SCHEDULEMODEL_H
