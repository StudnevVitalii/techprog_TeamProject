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

   IngredientForRecepi(string,int,string);

   IngredientForRecepi(ifstream *file);

   IngredientForRecepi* GetPointr();   
};

#endif // INGREDIENTFORRECEPI_H
