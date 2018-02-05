#include "containercmd.h"

#include <QDebug>

ContainerCmd::ContainerCmd(QString pyInterpreter, QString pyCmd, QObject* parent) : QObject(parent)
{
    QString repoPath = QDir::homePath() + "/.dolmades/repo";

    proc = new QProcess();
    proc->setProgram(pyInterpreter);
    script = new QFile(pyCmd);
    script->open(QFile::ReadOnly | QFile::Text);

    if (!QDir().exists(repoPath)) {
        proc->setArguments( QStringList() << "-" << "mkrepo" << repoPath );
        qDebug()<< "creating repoPath " << repoPath << " ...";
        proc->start();
        proc->waitForStarted();
        proc->write(script->readAll());
        proc->closeWriteChannel();
        proc->waitForFinished();
        qDebug()<< "...done!";
    } else {
        qDebug()<< "repoPath " << repoPath << " found";
    }

    stdArg << "-" << QString("--repo=%1").arg(repoPath);
}

void ContainerCmd::exec(const QStringList & args)
{
    QStringList arg = stdArg;
    arg << args;
    proc->setArguments(arg);
    proc->start();
    proc->waitForStarted();
    proc->write(script->readAll());
    proc->closeWriteChannel();
    proc->waitForFinished();
    qDebug()<<proc->readAllStandardOutput();
    qDebug()<<proc->readAllStandardError();
}

/*
void ContainerCmd::wineexec()
{
    // ./udocker.py run --user dolmades --hostenv --bindhome 726f7451-0096-3591-b889-c7669f51b809 winecfg
    QStringList arg = stdArg;
    arg << "run" << "--user" << "dolmades" << "--hostenv" << "--bindhome" << "726f7451-0096-3591-b889-c7669f51b809" << "winecfg";
    proc->setArguments(arg);
    proc->start();
    proc->waitForStarted();
    proc->write(script->readAll());
    proc->closeWriteChannel();
    proc->waitForFinished();
    qDebug()<<proc->readAllStandardOutput();
    qDebug()<<proc->readAllStandardError();
}

void ContainerCmd::getContainer()
{
    QStringList arg = stdArg;
    arg << "ps";
    proc->setArguments(arg);
    proc->start();
    proc->waitForStarted();
    proc->write(script->readAll());
    proc->closeWriteChannel();
    proc->waitForFinished();
    qDebug()<<proc->readAllStandardOutput();
    qDebug()<<proc->readAllStandardError();
    qDebug()<<arg;
}
*/

ContainerCmd::~ContainerCmd()
{

}
