#ifndef LISTS_H
#define LISTS_H
#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <conio.h>

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
    void shou();
    string GetName();
    void shoulist();
    void AddElement(Worker);
    void Control();
};
#endif // LISTS_H
