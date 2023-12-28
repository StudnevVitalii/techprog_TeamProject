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
    ListIngredients(ifstream*);
    void shou();
    void shoulist();
    void AddElement(Ingredient);
    void Control(string);
    Ingredient* Check(string);
    void Save();
};

#endif // LISTINGREDIENTS_H
