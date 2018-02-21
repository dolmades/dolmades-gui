#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <QList>
#include <QString>
#include <QByteArray>

#include "descriptor.h"
#include "blob.h"

class Ingredient {
private:
    Descriptor descriptor;
    QList<Blob*> blobs;
    QByteArray hash;

public:
    const QByteArray& getHash() const {return hash;}
    const Descriptor& getDescriptor() const {return descriptor;}
    void setDescriptor(const Descriptor& desc) {descriptor=desc;}
    Ingredient(const Descriptor &);

   void addBlob(const QString& fileName, const QByteArray& hash, qlonglong sizeInBytes, bool exec = false);
   void addBlob(const QString& fileName);
   bool delBlob(const QByteArray& hash);
};


#endif // INGREDIENT_H
