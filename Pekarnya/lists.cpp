#include "lists.h"

#include <iostream>
#include <list>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <iostream>

using namespace std;




ListWorkers::ListWorkers(){

}
ListWorkers::ListWorkers(string N){
    Name = N;
}
void ListWorkers::shou(){
    cout << Name;
}
void ListWorkers::shoulist(){
    cout << endl;
    list<Worker>::iterator ItrForShouing;
    ItrForShouing = Spisok.begin();
    for (ItrForShouing = Spisok.begin(); ItrForShouing != Spisok.end(); ++ItrForShouing){
        ItrForShouing->shou();
        if (ItrForShouing == SelectedElement){
            cout << " <---";
        }
        cout << endl;
    }
}
void ListWorkers::AddElement(Worker x){
    Spisok.push_back(x);
}
string ListWorkers::GetName(){
    return this->Name;
}
void ListWorkers::Control(){
    SelectedElement = Spisok.begin();
    bool conec = true;
    while (conec) {
        system("cls");
        ListWorkers::shou();
        ListWorkers::shoulist();


        switch (_getch()){
            case 80: //V
                    if (SelectedElement  != Spisok.end())
                    {
                        SelectedElement++;
                    }
                    break;
                    case 72: // ^
                    if (SelectedElement != Spisok.begin())
                    {
                        SelectedElement--;
                    }
            case 'd':

                    break;
            case 'a':

                    break;
            case 27: // esc
                conec = false;
                break;
            default:{}
            }
    }
}
Worker* ListWorkers::Check(string N){
    list<Worker>::iterator ItrToFind;
    ItrToFind = Spisok.begin();
    for (ItrToFind = Spisok.begin(); ItrToFind != Spisok.end(); ++ItrToFind)
        if (ItrToFind->GetName() == N){
            return ItrToFind->GetPointr();
        };
    return nullptr;
}


