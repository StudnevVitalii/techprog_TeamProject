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

using namespace std;

class ListIngredientForRecepi {
private:
    list<IngredientForRecepi> Spisok;
    list<IngredientForRecepi>::iterator SelectedElement;
    string Name;

public:
    ListIngredientForRecepi();
    ListIngredientForRecepi(string N);
    ListIngredientForRecepi(ifstream *file);
    void shou();
    string GetName();
    void shoulist();
    void AddElement(IngredientForRecepi);
    void Control();
    IngredientForRecepi* Check(string N);
    ListIngredientForRecepi* GetPointr();
    list<IngredientForRecepi> GetSpisok();
    void Save(ofstream*);
};

#endif // LISTINGREDIENTFORRECEPI_H
