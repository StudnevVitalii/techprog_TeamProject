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

   string GetName();

   string GetPassword();

   string GetRoot();

   void shou();
};


class Ingridient {

private:
    string Name;
    int Value;
    string ED;
public:
   Ingridient();

   Ingridient(string,int,string);

   string GetName();

   int GetValue();

   void shou();

};

#endif // ELEMENTS

