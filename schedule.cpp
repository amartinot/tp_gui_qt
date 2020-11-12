#include "schedule.h"

Schedule::Schedule(){}

bool Schedule::containsData() const
{
    return filled;
}

void Schedule::setFilled(bool value)
{
    filled = value;
}

QString Schedule::getCurrentRoom() const
{
    return currentRoom;
}

void Schedule::setCurrentRoom(const QString &value)
{
    currentRoom = value;
}

bool Schedule::saveIsUptodate() const
{
    return uptodateSave;
}

void Schedule::setUptodateSave(bool value)
{
    uptodateSave = value;
}

QList<QString> Schedule::getRooms()
{
    return rooms;
}

void Schedule::setRooms(QList<QString> rooms)
{
    this->rooms = rooms;
}

QList<QString> Schedule::getTeachers()
{
    return teachers;
}

void Schedule::setTeachers(QList<QString> teachers)
{
    this->teachers = teachers;
}

QList<QString> Schedule::getCourses()
{
    return courses;
}

void Schedule::setCourses(QList<QString> courses)
{
    this->courses = courses;
}

QList<QString> Schedule::getGroups()
{
    return groups;
}

void Schedule::setGroups(QList<QString> groups)
{
    this->groups = groups;
}

QList<QString> Schedule::getHours()
{
    return hours;
}

void Schedule::setHours(QList<QString> hours)
{
    this->hours = hours;
}

QMap<QPair<int, QString>, Activity> Schedule::getActivities() const
{
    return activities;
}

void Schedule::setActivities(const QMap<QPair<int, QString>, Activity> &value)
{
    activities = value;
}

void Schedule::addActivity(const Activity &newActivity) {

    checkActivityIfConflict(newActivity);

    activities.insert(QPair<int, QString>(newActivity.getSlot(), newActivity.getRoom()), newActivity);
}

void Schedule::deleteActivity(const Activity &activity) {
    activities.remove(QPair<int, QString>(activity.getSlot(), activity.getRoom()));
}

QList<QString> Schedule::getDays() const
{
    return days;
}

void Schedule::setDays(const QList<QString> &value)
{
    days = value;
}

// Find if a courses with same hour, same day and same teacher or same groups exists
void Schedule::checkActivityIfConflict(const Activity &newActivity) {

    foreach (Activity activity, activities) {
        if(activity.getSlot() == newActivity.getSlot() &&
                (activity.getGroup() == newActivity.getGroup() || activity.getTeacher() == newActivity.getTeacher())) {
            deleteActivity(activity);
        }
    }
}

void Schedule::clearSchedule() {
    setCurrentRoom("");
    setActivities(QMap<QPair<int, QString>, Activity>());
    setCourses(QList<QString>());
    setGroups(QList<QString>());
    setTeachers(QList<QString>());
    setRooms(QList<QString>());

    setFilled(false);
}

bool Schedule::getRoomsCBNeedUpdate() const
{
    return roomsCBNeedUpdate;
}

void Schedule::setRoomsCBNeedUpdate(bool value)
{
    roomsCBNeedUpdate = value;
}

