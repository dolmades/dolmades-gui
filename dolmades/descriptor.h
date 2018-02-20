#ifndef DESCRIPTOR_H
#define DESCRIPTOR_H

#define HASH_ALGO QCryptographicHash::Sha256

#include <QString>
#include <QDate>
#include <QUuid>
#include <QUrl>

class Descriptor {
public:
    QString name, version, description, author, logo;
    QUrl url;
    QDate date;
    qlonglong sizeInBytes;
    QUuid uuid;
};

#endif // DESCRIPTOR_H
