#ifndef LISTS_H
#define LISTS_H
#include <iostream>
#include <list>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <fstream>


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
    void AddElement(Ingridient);
    void Control();
    Ingredient* Check(string N);
};
#endif // LISTS_H
