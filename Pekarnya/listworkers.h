#ifndef LISTWORKERS_H
#define LISTWORKERS_H

#include <iostream>
#include <list>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <ctime>
#include "worker.h"

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
    void Save();
};

#endif // LISTWORKERS_H
