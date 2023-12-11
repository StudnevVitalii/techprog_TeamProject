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

class ListReports {
private:
    list<Product> Spisok;
    list<Product>::iterator SelectedElement;
    string Name;

public:
    ListReports();
    ListReports(string N);
    ListReports(ifstream *file);
    void shou();
    string GetName();
    void shoulist();
    void AddElement(Product);
    void Control();
    Product* Check(string N);
};
#endif // LISTS_H
