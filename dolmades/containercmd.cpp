#include "containercmd.h"

#include <QDebug>

ContainerCmd::ContainerCmd(QString pyInterpreter, QString pyCmd, QObject* parent) : QObject(parent)
{
    qDebug()<<workdir.path();

    proc = new QProcess();
    proc->setProgram(pyInterpreter);
    stdArg << "-" << QString("--repo=%1/.dolmades/repo").arg(QDir::homePath());

    script = new QFile(pyCmd);
    script->open(QFile::ReadOnly | QFile::Text);
}

void ContainerCmd::help()
{
    QStringList arg = stdArg;
    arg << "help";
    proc->setArguments(arg);
    proc->start();
    proc->waitForStarted();
    proc->write(script->readAll());
    proc->closeWriteChannel();
    proc->waitForFinished();
    qDebug()<<proc->readAllStandardOutput();
    qDebug()<<proc->readAllStandardError();
}

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

ContainerCmd::~ContainerCmd()
{

}
