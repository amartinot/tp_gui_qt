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

    QByteArray readFile(QString fileName);

    void loadData(QString fileName, Schedule *schedule);

    void saveData(QString fileName, Schedule *schedule);

    QList<QString> arrayToList(QJsonArray array);

    QMap<QPair<int, QString>, Activity> jsonActivitiesToMap(QJsonArray array);

    QJsonArray mapActivitiesToJsonArray(QMap<QPair<int, QString>, Activity>);

private:
    QString parentDirectory;
    //QString basicDataFileName = "/data/basic_data.json";
};

#endif // DATASERVICE_H
