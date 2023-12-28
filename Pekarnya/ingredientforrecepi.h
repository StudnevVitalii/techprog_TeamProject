#ifndef INGREDIENTFORRECEPI_H
#define INGREDIENTFORRECEPI_H

#include <string>
#include <iostream>
#include <fstream>
#include "ingredient.h"

using namespace std;

class IngredientForRecepi : public Ingredient{
public:
   IngredientForRecepi();

   IngredientForRecepi(int);

   IngredientForRecepi(ifstream*);

   IngredientForRecepi* GetPointr();

   void SetED(string);
};

#endif // INGREDIENTFORRECEPI_H
