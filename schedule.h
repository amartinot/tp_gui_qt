#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QList>
#include <QString>

#include <activity.h>

class Schedule
{
public:

    Schedule();

    QString getCurrentRoom() const;
    void setCurrentRoom(const QString &value);

    bool containsData() const;
    void setFilled(bool value);

    bool saveIsUptodate() const;
    void setUptodateSave(bool value);

    bool getRoomsCBNeedUpdate() const;
    void setRoomsCBNeedUpdate(bool value);

    QList<QString> getRooms();
    void setRooms(QList<QString> rooms);

    QList<QString> getTeachers();
    void setTeachers(QList<QString> teachers);

    QList<QString> getCourses();
    void setCourses(QList<QString> courses);

    QList<QString> getGroups();
    void setGroups(QList<QString> groups);

    QList<QString> getHours();
    void setHours(QList<QString> hours);

    QList<QString> getDays() const;
    void setDays(const QList<QString> &value);

    QMap<QPair<int, QString>, Activity> getActivities() const;
    void setActivities(const QMap<QPair<int, QString>, Activity> &value);

    // Method to add a new activity to the map
    void addActivity(const Activity &newActivity);

    // Method to delete an activity from the map
    void deleteActivity(const Activity &activity);

    // Method to check it there is a conflict with another activity
    // and call the delete method for the activty in conflit if it found one
    // impossible to have:
    //      - same slot & same groups
    //      - same slot & same teacher
    //      - same slot & same room (impossible because there is one table by rooms)
    void checkActivityIfConflict(const Activity &newActivity);

    // Method to clear the application schedule
    void clearSchedule();

private:
    QString currentRoom;

    // True if our application schedule contains data
    bool filled = false;

    // True if our schedule is up to date with the last saving
    bool uptodateSave = true;

    // True if the rooms combobox need to be updating
    bool roomsCBNeedUpdate = false;

    QList<QString> rooms;

    QList<QString> teachers;

    QList<QString> courses;

    QList<QString> groups;

    QList<QString> hours = QList<QString>({
        QString("08:00 - 08:45"),
        QString("08:55 - 09:40"),
        QString("09:50 - 10:35"),
        QString("10:45 - 11:30"),
        QString("11:40 - 12:25"),
        QString("12:35 - 13:30"),
        QString("13:40 - 14:25"),
        QString("14:35 - 15:20"),
        QString("15:30 - 16:15"),
        QString("16:25 - 17:10")
    });

    QList<QString> days = QList<QString>({
        QString("Mon"),
        QString("Tue"),
        QString("Wed"),
        QString("Thu"),
        QString("Fri")
    });

    QMap<QPair<int, QString>, Activity> activities;
};

#endif // SCHEDULE_H
