#ifndef ELEMENTS
#define ELEMENTS

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Worker {

private:
string Login;
string Password;
string Root;


public:
   Worker();

   Worker(string,string,string);

   Worker(ifstream *file);

   string GetName();

   string GetPassword();

   string GetRoot();

   void shou();

   Worker* GetPointr();
};

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

class Ingredient {

private:
    string Name;
    int Value;
    string ED;
public:
   Ingredient();

   Ingredient(string,int,string);

   Ingredient(ifstream *file);

   string GetName();

   int GetValue();

   void shou();

   Ingredient* GetPointr();

};
class IngredientForRecepi : public Ingredient{
public:
   IngredientForRecepi();

   IngredientForRecepi(string,int,string);

   IngredientForRecepi(ifstream *file);

   IngredientForRecepi* GetPointr();
};


#endif // ELEMENTS

