#include "ingredientforrecepi.h"

IngredientForRecepi::IngredientForRecepi()
{
    string n;
    int v;
    cout << "Vvedite naimenovanie: " << endl;
    cin >> n;
    this->Name = n;
    cout << "Vvedite kol-vo: " << endl;
    cin >> v;
    this->Value = v;

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

