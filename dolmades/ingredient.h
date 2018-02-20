#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <QList>
#include <QString>
#include <QByteArray>

#include "descriptor.h"
#include "blob.h"

class Ingredient {
public:
    Descriptor descriptor;
    QList<Blob*> blobs;
    QByteArray hash;

   Ingredient(const Descriptor &);

   void addBlob(const QString& fileName, const QByteArray& hash, qlonglong sizeInBytes, bool exec = false);
   void addBlob(const QString& fileName);
   bool delBlob(const QByteArray& hash);
};


#endif // INGREDIENT_H
