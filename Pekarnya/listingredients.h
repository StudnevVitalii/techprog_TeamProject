#ifndef LISTINGREDIENTS_H
#define LISTINGREDIENTS_H

#include <iostream>
#include <list>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <ctime>
#include "ingredient.h"

using namespace std;

class ListIngredients {
private:
    list<Ingredient> Spisok;
    list<Ingredient>::iterator SelectedElement;
    string Name;

public:
    ListIngredients();
    ListIngredients(string N);
    ListIngredients(ifstream *file);
    void shou();
    string GetName();
    void shoulist();
    void AddElement(Ingredient);
    void Control();
    Ingredient* Check(string N);
    void Save();
};

#endif // LISTINGREDIENTS_H
