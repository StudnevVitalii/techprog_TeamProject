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

    Product(string,int );

    Product(ifstream *file);

   string GetName();

   int GetValue();

   void shou();

   Product* GetPointr();

};

#endif // PRODUCT_H
