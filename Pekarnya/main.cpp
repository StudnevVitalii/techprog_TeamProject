#include <iostream>
#include <string>
#include "elements.h"
#include "lists.h"
#include "userinterface.h"

using namespace std;

int main()
{
    ListReports aaa("11.12.2023");
    Product a1("bulka1", 123);
    Product a2("bulka2", 12);
    Product a3("bulka3", 1);
    aaa.AddElement(a1);
    aaa.AddElement(a2);
    aaa.AddElement(a3);
    aaa.Control();


    UserInterface the_user_interface;
    the_user_interface.Login();
    system("pause");



}

