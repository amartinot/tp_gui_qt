#ifndef DATASERVICE_H
#define DATASERVICE_H

#include <QString>
#include <QtGlobal>
#include <QDebug>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDir>

#include "schedule.h"

class DataService
{
public:
    DataService();

    QString getParentDirectory();

    // Method to read a file in parameter and return a QByteArray
    QByteArray readFile(QString fileName);

    // Method to load data from a json file to our application schedule
    void loadData(QString fileName, Schedule *schedule);

    // Method to save the data from our application schedule to a json file
    void saveData(QString fileName, Schedule *schedule);

    // Method to convert a json array to a QList of QString
    QList<QString> arrayToList(QJsonArray array);

    // Method to convert a QJsonArray of activities to a QMap<QPair<int, QString>, Activity>
    QMap<QPair<int, QString>, Activity> jsonActivitiesToMap(QJsonArray array);

    // Method to convert our Map of activities (QMap<QPair<int, QString>, Activity>) to a QJsonArray
    QJsonArray mapActivitiesToJsonArray(QMap<QPair<int, QString>, Activity>);

private:
    // parent directory for the saving and the loading
    QString parentDirectory;
};

#endif // DATASERVICE_H
