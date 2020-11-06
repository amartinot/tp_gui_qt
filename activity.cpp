#include "activity.h"

Activity::Activity()
{}

Activity::Activity(int slot, QString room, QString group, QString course, QString teacher):
    room(room), group(group), course(course), teacher(teacher), slot(slot)
{}

QString Activity::getRoom() const
{
    return room;
}

void Activity::setRoom(const QString &value)
{
    room = value;
}

QString Activity::getGroup() const
{
    return group;
}

void Activity::setGroup(const QString &value)
{
    group = value;
}

QString Activity::getCourse() const
{
    return course;
}

void Activity::setCourse(const QString &value)
{
    course = value;
}

QString Activity::getTeacher() const
{
    return teacher;
}

void Activity::setTeacher(const QString &value)
{
    teacher = value;
}

int Activity::getSlot() const
{
    return slot;
}

void Activity::setSlot(int value)
{
    slot = value;
}


