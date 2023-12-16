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

   Ingredient(string,int,string);

   Ingredient(ifstream *file);

   string GetName();

   int GetValue();

   void shou();

   Ingredient* GetPointr();

};

#endif // INGREDIENT_H
