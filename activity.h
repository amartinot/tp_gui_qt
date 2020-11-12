#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QString>

class Activity
{
public:
    Activity();

    Activity(int slot, QString room, QString group = "", QString course = "", QString teacher = "");

    QString getRoom() const;
    void setRoom(const QString &value);

    QString getGroup() const;
    void setGroup(const QString &value);

    QString getCourse() const;
    void setCourse(const QString &value);

    QString getTeacher() const;
    void setTeacher(const QString &value);

    int getSlot() const;
    void setSlot(int value);

private:
    QString room;

    QString group;

    QString course;

    QString teacher;

    int slot;

};

#endif // ACTIVITY_H
