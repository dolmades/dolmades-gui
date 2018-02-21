#ifndef DOLMADE_H
#define DOLMADE_H

#include <QMultiMap>
#include <QByteArray>

#include "descriptor.h"
#include "blob.h"

class Dolmade {
private:
    Descriptor descriptor;
    QByteArray baseImageHash;
    QList<QByteArray> supportedIngredients;
    QList<QByteArray> supportedRecipes;

public:
    Dolmade(const Descriptor&);
};


#endif
