#include "ingredientforrecepi.h"

IngredientForRecepi::IngredientForRecepi():Ingredient()
{

}
IngredientForRecepi::IngredientForRecepi(string n,int v,string e):Ingredient(n,v,e)
{

}
IngredientForRecepi::IngredientForRecepi(ifstream *file):Ingredient(file)
{

}
IngredientForRecepi* IngredientForRecepi::GetPointr()
{
    return this;
}

