#ifndef RECIPE_H
#define RECIPE_H

#include "descriptor.h"
#include "blob.h"
#include "ingredient.h"

class Recipe {
public:
    Descriptor descriptor;
    Blob superUserScriptFile;
    Blob userScriptFile;
    QList<Ingredient*> ingredients;

    Recipe(const Descriptor& desc, const QString& script = QString::null, const QString& suScript = QString::null);

    void addIngredient(const Ingredient&);

    bool delIngredient(const QByteArray& hash);

private:
    void setScriptFile(const QString& fileName, const QByteArray& hash, qlonglong sizeInBytes, Blob& target);
    void setSuperUserScriptFile(const QString&);
    void setUserScriptFile(const QString&);

};

#endif // RECIPE_H
