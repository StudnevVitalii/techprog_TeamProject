#ifndef LISTS_H
#define LISTS_H
#include <iostream>
#include <list>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <ctime>


#include "elements.h"

using namespace std;

class ListWorkers {
private:
    list<Worker> Spisok;
    list<Worker>::iterator SelectedElement;
    string Name;

public:
    ListWorkers();
    ListWorkers(string N);
    ListWorkers(ifstream *file);
    void shou();
    string GetName();
    void shoulist();
    void AddElement(Worker);
    void Control();
    Worker* Check(string N);
};

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
};


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
};

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
    void Control();
    ListIngredientForRecepi* Check(string N);

};
class ListReports {
private:
    list<ListProducts> Spisok;
    list<ListProducts>::iterator SelectedElement;
    string Name;

public:
    ListReports();
    ListReports(string N);
    ListReports(ifstream *file);
    void shou();
    string GetName();
    void shoulist();
    void AddElement(ListProducts);
    void Control();
    ListProducts* Check(string N);

};
#endif // LISTS_H
