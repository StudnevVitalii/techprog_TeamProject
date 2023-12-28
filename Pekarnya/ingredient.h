#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Ingredient {

protected:
    string Name;
    int Value;
    string ED;
public:
   Ingredient();

   Ingredient(int);

   Ingredient(ifstream*);

   string GetName();

   int GetValue();

   string GetED();

   void SetValue(int);

   void shou();

   Ingredient* GetPointr();

};

#endif // INGREDIENT_H
