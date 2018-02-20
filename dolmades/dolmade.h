#ifndef DOLMADE_H
#define DOLMADE_H

#include <QMultiMap>
#include <QByteArray>

#include "descriptor.h"
#include "blob.h"
#include "ingredient.h"
#include "recipe.h"

class Dolmade {
private:
    Descriptor descriptor;
    QByteArray baseImageHash;
    QMultiMap<Ingredient*,Recipe*> supportedIngredients;
    QMultiMap<Recipe*,Ingredient*> supportedRecipes;

public:
    Dolmade(const Descriptor&);
};


#endif
