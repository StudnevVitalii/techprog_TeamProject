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


#endif // ELEMENTS

