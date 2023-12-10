#include <iostream>
#include <string>
#include "elements.h"
#include "lists.h"

using namespace std;

int main()
{
    Worker Vadim("Vadim","1234","admin");
    Worker Andrey("Andrey","1234","pekar");
    Worker Ivan("Ivan","1234","worker");
    Worker Ilya;
    ListWorkers WorkerList("Spisok Rabochich");
    WorkerList.AddElement(Vadim);
    WorkerList.AddElement(Andrey);
    WorkerList.AddElement(Ivan);
    WorkerList.AddElement(Ilya);
    WorkerList.Control();
    system("pause");



}

