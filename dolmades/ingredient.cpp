#include <QFile>
#include <QCryptographicHash>

#include "ingredient.h"

Ingredient::Ingredient(const Descriptor &desc) {
    descriptor = desc;
}

void Ingredient::addBlob(const QString& fileName, const QByteArray& hash, qlonglong sizeInBytes, bool exec) {
   Blob* b = new Blob();
   b->filename = fileName;
   b->hash = hash;
   b->sizeInBytes = sizeInBytes;
   b->executable = exec;
   blobs.append(b);
   descriptor.sizeInBytes += sizeInBytes;
}

void Ingredient::addBlob(const QString& fileName) {
   QFile f(fileName);
   addBlob(fileName, QCryptographicHash::hash(f.readAll(), HASH_ALGO), f.size(), f.permissions() == QFile::ExeOwner );
}

bool Ingredient::delBlob(const QByteArray& hash) {
   for(int i=0; i<blobs.size(); i++) {
       Blob *b = blobs.at(i);
       if (b->hash == hash) {
           descriptor.sizeInBytes -= b->sizeInBytes;
           blobs.removeAt(i);
           delete b;
           return true;
       }
   }
   return false;
}
