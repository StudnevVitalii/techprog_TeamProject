#include <iostream>
#include <string>
#include "elements.h"
#include "lists.h"

using namespace std;

int main()
{
//    Worker Vadim("Vadim","1234","admin");
//    Worker Andrey("Andrey","1234","pekar");
//    Worker Ivan("Ivan","1234","worker");
//    Worker Ilya;
//    ListWorkers WorkerList("Spisok Rabochich");
//    WorkerList.AddElement(Vadim);
//    WorkerList.AddElement(Andrey);
//    WorkerList.AddElement(Ivan);
//    Worker* W1 = WorkerList.Check("Ivan");
//    if (W1 != nullptr){
//        W1->shou();
//        system("pause");
//    }
//    W1 = WorkerList.Check("1");
//    if (W1 == nullptr){
//        cout << "ok" << endl;
//        system("pause");
//    }

//    WorkerList.AddElement(Ilya);


    ifstream file;
    file.open("D:/Team_project_ver2.0/Pekarnya/listofworkers.txt", ios_base::in);
    ListWorkers WorkerList(&file);

    WorkerList.Control();
    system("pause");



}

