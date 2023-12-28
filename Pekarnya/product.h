#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Product {
private:
string Name;
int Value;


public:

    Product();
    Product(ifstream*);
    string GetName();
    int GetValue();
    void IncValue(int);
    void shou();
    Product* GetPointr();

};

#endif // PRODUCT_H
