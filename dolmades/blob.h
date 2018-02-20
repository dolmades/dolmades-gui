#ifndef BLOB_H
#define BLOB_H

#define HASH_ALGO QCryptographicHash::Sha256

#include <QString>
#include <QByteArray>

class Blob {
public:
    QString filename;
    QByteArray hash;
    qlonglong sizeInBytes;
    bool executable;
};

#endif // BLOB_H
