#ifndef SCHEDULEMODEL_H
#define SCHEDULEMODEL_H

#include <QAbstractTableModel>

#include <schedule.h>
#include <activity.h>

class ScheduleModel : public QAbstractTableModel
{
public:
    ScheduleModel(Schedule *schedule, QString room, QObject *parent=0);

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    // void append(const PlannedCourse & plannedCourse);

private:
    Schedule *schedule;
    QString room;
};

#endif // SCHEDULEMODEL_H
