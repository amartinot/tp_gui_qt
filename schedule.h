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

    void addActivity(const Activity &newActivity);
    void deleteActivity(const Activity &activity);
    void deleteActivityIfConflict(const Activity &newActivity);

    void clearSchedule();

private:
    QString currentRoom;
    bool filled = false;
    bool uptodateSave = true;
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
