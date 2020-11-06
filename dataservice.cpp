#include "dataservice.h"

DataService::DataService()
{
    QDir parent = QDir::current();
    parent.cdUp();
    parentDirectory = parent.absolutePath();
}

QString DataService::getParentDirectory()
{
    return parentDirectory;
}

QByteArray DataService::readFile(QString fileName)
{
    QFile inFile(fileName);
    inFile.open(QIODevice::ReadOnly);
    QByteArray data = inFile.readAll();
    inFile.close();

    return data;
}

void DataService::loadData(QString fileName, Schedule *schedule)
{
    schedule->clearSchedule();

    QByteArray data = readFile(fileName);

    QJsonParseError errorPtr;

    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);

    if (doc.isNull()) {
        qDebug("Parse failed");
    }
    QJsonObject rootObj = doc.object();
    QJsonArray coursesArray = rootObj.value("classes").toArray();
    schedule->setCourses(arrayToList(coursesArray));

    QJsonArray groupsArray = rootObj.value("groups").toArray();
    schedule->setGroups(arrayToList(groupsArray));

    QJsonArray roomsArray = rootObj.value("rooms").toArray();
    schedule->setRooms(arrayToList(roomsArray));

    QJsonArray teachersArray = rootObj.value("teachers").toArray();
    schedule->setTeachers(arrayToList(teachersArray));

    QJsonArray activitiesArray = rootObj.value("activities").toArray();
    schedule->setActivities(jsonActivitiesToMap(activitiesArray));

    schedule->setFilled(true);
    schedule->setUptodateSave(true);
}

void DataService::saveData(QString fileName, Schedule *schedule)
{

    QJsonObject jsonObj;

    QJsonArray roomsArray;
    for(QString room: schedule->getRooms()) {
        roomsArray.append(room);
    }
    jsonObj.insert("rooms", roomsArray);

    QJsonArray groupsArray;
    for(QString group: schedule->getGroups()) {
        groupsArray.append(group);
    }
    jsonObj.insert("groups", groupsArray);

    QJsonArray coursesArray;
    for(QString course: schedule->getCourses()) {
        coursesArray.append(course);
    }
    jsonObj.insert("classes", coursesArray);

    QJsonArray teachersArray;
    for(QString teacher: schedule->getTeachers()) {
        teachersArray.append(teacher);
    }
    jsonObj.insert("teachers", teachersArray);

    QJsonArray activitiesArray = mapActivitiesToJsonArray(schedule->getActivities());
    jsonObj.insert("activities", activitiesArray);

    QJsonDocument saveDoc(jsonObj);

    QFile file(fileName);
    file.open(QFile::WriteOnly);
    file.write(saveDoc.toJson());
    schedule->setUptodateSave(true);
}

QList<QString> DataService::arrayToList(QJsonArray array)
{
    QList<QString> list;

    for (auto value : array) {
        list.append(value.toString());
    }

    return list;
}

QMap<QPair<int, QString>, Activity> DataService::jsonActivitiesToMap(QJsonArray array)
{
    QMap<QPair<int, QString>, Activity> map;

    for (QJsonValue value : array) {
        Activity newActivity;
        QJsonObject activityObj = value.toObject();
        newActivity.setCourse(activityObj["class"].toString());
        newActivity.setGroup(activityObj["group"].toString());
        newActivity.setRoom(activityObj["room"].toString());
        newActivity.setTeacher(activityObj["teacher"].toString());
        newActivity.setSlot(activityObj["slot"].toInt());
        map.insert(QPair<int, QString>(newActivity.getSlot(), newActivity.getRoom()), newActivity);
    }

    return map;
}

QJsonArray DataService::mapActivitiesToJsonArray(QMap<QPair<int, QString>, Activity> activities)
{
    QJsonArray activitiesArray;
    foreach (Activity activity, activities) {
        QJsonObject jsonObj;
        jsonObj.insert("room", activity.getRoom());
        jsonObj.insert("group", activity.getGroup());
        jsonObj.insert("class", activity.getCourse());
        jsonObj.insert("slot", activity.getSlot());
        jsonObj.insert("teacher", activity.getTeacher());

        activitiesArray.append(jsonObj);
    }

    return activitiesArray;
}






