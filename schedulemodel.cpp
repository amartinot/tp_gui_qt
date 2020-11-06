#include "schedulemodel.h"


ScheduleModel::ScheduleModel(Schedule *schedule, QString room, QObject *parent)
    : QAbstractTableModel(parent), schedule(schedule), room(room)
{
}

int ScheduleModel::rowCount(const QModelIndex &) const
{
    return schedule->getHours().size();
}

int ScheduleModel::columnCount(const QModelIndex &) const
{
    return schedule->getDays().size();
}

QVariant ScheduleModel::data(const QModelIndex &index, int role) const
{
  if (role != Qt::DisplayRole && role != Qt::EditRole) return {};

  QMap<QPair<int, QString>, Activity> activities = schedule->getActivities();

  int day;
  int hour;
  foreach (Activity activity, activities) {
      day = activity.getSlot() / schedule->getHours().size();
      hour = activity.getSlot() % schedule->getHours().size();
      if (day == index.column() && hour == index.row() && activity.getRoom() == room){
          return activity.getGroup();
      }
  }
  return QVariant();
}

QVariant ScheduleModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        QList<QString> days = schedule->getDays();
        return QString(days[section]);
    }
    if (role == Qt::DisplayRole && orientation == Qt::Vertical) {
        QList<QString> hours = schedule->getHours();
        return QString(hours[section]);
    }

    return QVariant();
}


