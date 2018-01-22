#ifndef CONTAINERCMD_H
#define CONTAINERCMD_H

#include <QProcess>
#include <QString>
#include <QObject>
#include <QTemporaryDir>
#include <QProcess>
#include <QFile>

class ContainerCmd : public QObject
{
    Q_OBJECT

public:
    explicit ContainerCmd(QString, QString, QObject *);
    ~ContainerCmd();

    void help();
    void wineexec();
    void getContainer();

private:
    QTemporaryDir workdir;
    QProcess* proc;
    QFile* script;
    QStringList stdArg;
};

#endif
