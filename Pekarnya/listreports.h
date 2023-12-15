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
#include "listproducts.h"

using namespace std;

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

#endif // LISTREPORTS_H
