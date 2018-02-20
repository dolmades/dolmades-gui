#include <QFile>
#include <QCryptographicHash>
#include <QList>

#include "recipe.h"

Recipe::Recipe(const Descriptor& desc, const QString& script, const QString& suScript) {
    descriptor = desc;
    setUserScriptFile(script);
    setSuperUserScriptFile(suScript);
}

void Recipe::addIngredient(const Ingredient& ingr) {
    Ingredient *i = new Ingredient(ingr.descriptor);
    *i = ingr;
    ingredients.append(i);
    descriptor.sizeInBytes += ingr.descriptor.sizeInBytes;
}

bool Recipe::delIngredient(const QByteArray& hash) {
    for (int i=0; i<ingredients.size(); i++) {
        Ingredient *in = ingredients.at(i);
        if (in->hash == hash) {
            descriptor.sizeInBytes -= in->descriptor.sizeInBytes;
            ingredients.removeAt(i);
            delete in;
            return true;
        }
    }
    return false;
}

void Recipe::setScriptFile(const QString& fileName, const QByteArray& hash, qlonglong sizeInBytes, Blob& target) {
    Q_ASSERT(target.sizeInBytes == 0);
    target.filename = fileName;
    target.executable = true;
    target.hash = hash;
    target.sizeInBytes = sizeInBytes;
    descriptor.sizeInBytes += sizeInBytes;
}

void Recipe::setSuperUserScriptFile(const QString& scriptFile) {
    QFile f(scriptFile);
    setScriptFile(scriptFile, QCryptographicHash::hash(f.readAll(), HASH_ALGO), f.size(), this->superUserScriptFile);
}

void Recipe::setUserScriptFile(const QString& scriptFile) {
    QFile f(scriptFile);
    setScriptFile(scriptFile, QCryptographicHash::hash(f.readAll(), HASH_ALGO), f.size(), this->userScriptFile);
}
