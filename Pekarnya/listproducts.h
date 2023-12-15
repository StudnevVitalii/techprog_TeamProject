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

using namespace std;

class ListProducts {
private:
    list<Product> Spisok;
    list<Product>::iterator SelectedElement;
    string Name;

public:
    ListProducts();
    ListProducts(string N);
    ListProducts(ifstream *file);
    void shou();
    string GetName();
    void shoulist();
    void AddElement(Product);
    void Control();
    Product* Check(string N);
    ListProducts* GetPointr();

};

#endif // LISTPRODUCTS_H
