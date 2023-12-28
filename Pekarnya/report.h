#ifndef LISTPRODUCTS_H
#define LISTPRODUCTS_H

#include <iostream>
#include <list>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <ctime>
#include "product.h"
#include "listingredients.h"
#include "ingredient.h"
#include "listrecepi.h"
#include "resepi.h"
#include "ingredientforrecepi.h"



using namespace std;

class ListProducts {
private:
    list<Product> Spisok;
    list<Product>::iterator SelectedElement;
    string Name;

public:
    ListProducts();
    ListProducts(string);
    ListProducts(ifstream*);
    void shou();
    string GetName();
    void shoulist();
    void AddElement(Product);
    void Control(ListRecepi*,ListIngredients*);
    Product* Check(string);
    ListProducts* GetPointr();
    void Save(ofstream*);
    bool Proverka(Product*,ListRecepi*,ListIngredients*);// реализовать

};

#endif // LISTPRODUCTS_H
