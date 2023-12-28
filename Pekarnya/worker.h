#ifndef WORKER_H
#define WORKER_H

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

#endif // WORKER_H
