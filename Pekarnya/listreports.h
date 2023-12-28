#ifndef LISTREPORTS_H
#define LISTREPORTS_H

#include <iostream>
#include <list>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <ctime>
#include "report.h"

using namespace std;

class ListReports {
private:
    list<ListProducts> Spisok;
    list<ListProducts>::iterator SelectedElement;
    string Name;

public:
    ListReports();
    ListReports(ifstream*);
    void shou();
    void shoulist();
    void AddElement(ListProducts);
    void Control(ListRecepi*,ListIngredients*);
    ListProducts* Check(string);
    void Save();

};

#endif // LISTREPORTS_H
