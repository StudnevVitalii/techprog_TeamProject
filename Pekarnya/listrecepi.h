#ifndef LISTRECEPI_H
#define LISTRECEPI_H

#include <iostream>
#include <list>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <ctime>
#include "listingredientforrecepi.h"
#include "listingredients.h"

using namespace std;

class ListRecepi {
private:
    list<ListIngredientForRecepi> Spisok;
    list<ListIngredientForRecepi>::iterator SelectedElement;
    string Name;

public:
    ListRecepi();
    ListRecepi(string N);
    ListRecepi(ifstream *file);
    void shou();
    string GetName();
    void shoulist();
    void AddElement(ListIngredientForRecepi);
    void Control(ListIngredients*, string);
    ListIngredientForRecepi* Check(string N);
    void Save();
    bool Proverka();

};

#endif // LISTRECEPI_H
