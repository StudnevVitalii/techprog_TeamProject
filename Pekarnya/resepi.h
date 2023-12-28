#ifndef LISTINGREDIENTFORRECEPI_H
#define LISTINGREDIENTFORRECEPI_H

#include <iostream>
#include <list>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <ctime>
#include "ingredientforrecepi.h"
#include "listingredients.h"

using namespace std;

class ListIngredientForRecepi {
private:
    list<IngredientForRecepi> Spisok;
    list<IngredientForRecepi>::iterator SelectedElement;
    string Name;

public:
    ListIngredientForRecepi();
    ListIngredientForRecepi(ifstream*);
    void shou();
    string GetName();
    void shoulist();
    void AddElement(IngredientForRecepi);
    void Control(ListIngredients*, string);
    IngredientForRecepi* Check(string);
    ListIngredientForRecepi* GetPointr();
    list<IngredientForRecepi> GetSpisok();
    void Save(ofstream*);
    bool Proverka(IngredientForRecepi*,ListIngredients*);
};

#endif // LISTINGREDIENTFORRECEPI_H
