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
ListWorkers::ListWorkers(ifstream *file)
{
    string N;
    string last;
    getline(*file, N, ' ');
    Name = N;
    getline(*file, last);
    int count = 1;
    while ((file->eof() != true) && (count <= stoi(last)))
    {
       Worker* NowyRabochiy = new Worker(file);
       ListWorkers::AddElement(*NowyRabochiy);
       count++;
    }
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
                    if (SelectedElement  == Spisok.end())
                    {
                        SelectedElement--;
                    }
                    break;
                    case 72: // ^
                    if (SelectedElement != Spisok.begin())
                    {
                        SelectedElement--;
                    }
            case 'd':

                    break;
            case 'a':{
                    Worker* NowyRabochiy = new Worker;
                    Worker* TestWorker = ListWorkers::Check(NowyRabochiy->GetName());
                    if (TestWorker == nullptr){
                        ListWorkers::AddElement(*NowyRabochiy);
                    }else{
                        cout << "that user already exist";
                        _getch();
                    }

                    break;}
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





ListIngredients::ListIngredients(){

}
ListIngredients::ListIngredients(string N){
    Name = N;
}
ListIngredients::ListIngredients(ifstream *file)
{
    string N;
    string last;
    getline(*file, N, ' ');
    Name = N;
    getline(*file, last);
    int count = 1;
    while ((file->eof() != true) && (count <= stoi(last)))
    {
       Ingredient* NowyIngredient = new Ingredient(file);
       ListIngredients::AddElement(*NowyIngredient);
       count++;
    }
}
void ListIngredients::shou(){
    cout << Name;
}
void ListIngredients::shoulist(){
    cout << endl;
    list<Ingredient>::iterator ItrForShouing;
    ItrForShouing = Spisok.begin();
    for (ItrForShouing = Spisok.begin(); ItrForShouing != Spisok.end(); ++ItrForShouing){
        ItrForShouing->shou();
        if (ItrForShouing == SelectedElement){
            cout << " <---";
        }
        cout << endl;
    }
}
void ListIngredients::AddElement(Ingredient x){
    Spisok.push_back(x);
}
string ListIngredients::GetName(){
    return this->Name;
}
void ListIngredients::Control(){
    SelectedElement = Spisok.begin();
    bool conec = true;
    while (conec) {
        system("cls");
        ListIngredients::shou();
        ListIngredients::shoulist();


        switch (_getch()){
            case 80: //V
                    if (SelectedElement  != Spisok.end())
                    {
                        SelectedElement++;
                    }
                    if (SelectedElement  == Spisok.end())
                    {
                        SelectedElement--;
                    }
                    break;
                    case 72: // ^
                    if (SelectedElement != Spisok.begin())
                    {
                        SelectedElement--;
                    }
            case 'd':

                    break;
            case 'a':{
                    Ingredient* NowyRabochiy = new Ingredient;
                    Ingredient* TestWorker = ListIngredients::Check(NowyRabochiy->GetName());
                    if (TestWorker == nullptr){
                        ListIngredients::AddElement(*NowyRabochiy);
                    }else{
                        cout << "that user already exist";
                        _getch();
                    }

                    break;}
            case 27: // esc
                conec = false;
                break;
            default:{}
            }
    }
}
Ingredient* ListIngredients::Check(string N){
    list<Ingredient>::iterator ItrToFind;
    ItrToFind = Spisok.begin();
    for (ItrToFind = Spisok.begin(); ItrToFind != Spisok.end(); ++ItrToFind)
        if (ItrToFind->GetName() == N){
            return ItrToFind->GetPointr();
        };
    return nullptr;
}


ListIngredientForRecepi::ListIngredientForRecepi(){

}
ListIngredientForRecepi::ListIngredientForRecepi(string N){
    Name = N;
}
ListIngredientForRecepi::ListIngredientForRecepi(ifstream *file)
{
    string N;
    string last;
    getline(*file, N, ' ');
    Name = N;
    getline(*file, last);
    int count = 1;
    while ((file->eof() != true) && (count <= stoi(last)))
    {
       IngredientForRecepi* NowyIngredient = new IngredientForRecepi(file);
       ListIngredientForRecepi::AddElement(*NowyIngredient);
       count++;
    }
}
void ListIngredientForRecepi::shou(){
    cout << Name;
}
void ListIngredientForRecepi::shoulist(){
    cout << endl;
    list<IngredientForRecepi>::iterator ItrForShouing;
    ItrForShouing = Spisok.begin();
    for (ItrForShouing = Spisok.begin(); ItrForShouing != Spisok.end(); ++ItrForShouing){
        ItrForShouing->shou();
        if (ItrForShouing == SelectedElement){
            cout << " <---";
        }
        cout << endl;
    }
}
void ListIngredientForRecepi::AddElement(IngredientForRecepi x){
    Spisok.push_back(x);
}
string ListIngredientForRecepi::GetName(){
    return this->Name;
}
void ListIngredientForRecepi::Control(){
    SelectedElement = Spisok.begin();
    bool conec = true;
    while (conec) {
        system("cls");
        ListIngredientForRecepi::shou();
        ListIngredientForRecepi::shoulist();


        switch (_getch()){
            case 80: //V
                    if (SelectedElement  != Spisok.end())
                    {
                        SelectedElement++;
                    }
                    if (SelectedElement  == Spisok.end())
                    {
                        SelectedElement--;
                    }
                    break;
                    case 72: // ^
                    if (SelectedElement != Spisok.begin())
                    {
                        SelectedElement--;
                    }
            case 'd':

                    break;
            case 'a':{
                    IngredientForRecepi* NowyRabochiy = new IngredientForRecepi;
                    IngredientForRecepi* TestWorker = ListIngredientForRecepi::Check(NowyRabochiy->GetName());
                    if (TestWorker == nullptr){
                        ListIngredientForRecepi::AddElement(*NowyRabochiy);
                    }else{
                        cout << "that user already exist";
                        _getch();
                    }

                    break;}
            case 27: // esc
                conec = false;
                break;
            default:{}
            }
    }
}
IngredientForRecepi* ListIngredientForRecepi::Check(string N){
    list<IngredientForRecepi>::iterator ItrToFind;
    ItrToFind = Spisok.begin();
    for (ItrToFind = Spisok.begin(); ItrToFind != Spisok.end(); ++ItrToFind)
        if (ItrToFind->GetName() == N){
            return ItrToFind->GetPointr();
        };
    return nullptr;
}
