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
ListIngredientForRecepi* ListIngredientForRecepi::GetPointr(){
    return this;
}

ListProducts::ListProducts(){

}
ListProducts::ListProducts(string N){
    Name = N;
}
ListProducts::ListProducts(ifstream *file)
{
    string N;
    string last;
    getline(*file, N, ' ');
    Name = N;
    getline(*file, last);
    int count = 1;
    while ((file->eof() != true) && (count <= stoi(last)))
    {
       Product* NowyRabochiy = new Product(file);
       ListProducts::AddElement(*NowyRabochiy);
       count++;
    }
}
void ListProducts::shou(){
    cout << Name;
}
void ListProducts::shoulist(){
    cout << endl;
    list<Product>::iterator ItrForShouing;
    ItrForShouing = Spisok.begin();
    for (ItrForShouing = Spisok.begin(); ItrForShouing != Spisok.end(); ++ItrForShouing){
        ItrForShouing->shou();
        if (ItrForShouing == SelectedElement){
            cout << " <---";
        }
        cout << endl;
    }
}
void ListProducts::AddElement(Product x){
    Spisok.push_back(x);
}
string ListProducts::GetName(){
    return this->Name;
}
void ListProducts::Control(){
    SelectedElement = Spisok.begin();
    bool conec = true;
    while (conec) {
        system("cls");
        ListProducts::shou();
        ListProducts::shoulist();


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
                    time_t t = time(nullptr);
                    tm* now = localtime(&t);
                    string today = to_string(now->tm_mday) + '.' + to_string((now->tm_mon + 1)) + '.' + to_string((now->tm_year + 1900));
                    if(this->Name == today){
                        Product* NowyRabochiy = new Product;
                        Product* TestWorker = ListProducts::Check(NowyRabochiy->GetName());
                        if (TestWorker == nullptr){
                            ListProducts::AddElement(*NowyRabochiy);
                        }
                    }
                    else{
                        cout << "Mozhno izmenyat tolko za tekushchij den!";
                    }

                    break;}
            case 27: // esc
                conec = false;
                break;
            default:{}
            }
    }
}
Product* ListProducts::Check(string N){
    list<Product>::iterator ItrToFind;
    ItrToFind = Spisok.begin();
    for (ItrToFind = Spisok.begin(); ItrToFind != Spisok.end(); ++ItrToFind)
        if (ItrToFind->GetName() == N){
            return ItrToFind->GetPointr();
        };
    return nullptr;
}
ListProducts* ListProducts::GetPointr(){
    return this;
}


ListRecepi::ListRecepi(){

}
ListRecepi::ListRecepi(string N){
    Name = N;
}
ListRecepi::ListRecepi(ifstream *file)
{
    string N;
    string last;
    getline(*file, N, ' ');
    Name = N;
    getline(*file, last);
    int count = 1;
    while ((file->eof() != true) && (count <= stoi(last)))
    {
       ListIngredientForRecepi* NowyRabochiy = new ListIngredientForRecepi(file);
       ListRecepi::AddElement(*NowyRabochiy);
       count++;
    }
}
void ListRecepi::shou(){
    cout << Name;
}
void ListRecepi::shoulist(){
    cout << endl;
    list<ListIngredientForRecepi>::iterator ItrForShouing;
    ItrForShouing = Spisok.begin();
    for (ItrForShouing = Spisok.begin(); ItrForShouing != Spisok.end(); ++ItrForShouing){
        ItrForShouing->shou();
        if (ItrForShouing == SelectedElement){
            cout << " <---";
        }
        cout << endl;
    }
}
void ListRecepi::AddElement(ListIngredientForRecepi x){
    Spisok.push_back(x);
}
string ListRecepi::GetName(){
    return this->Name;
}
void ListRecepi::Control(){
    SelectedElement = Spisok.begin();
    bool conec = true;
    while (conec) {
        system("cls");
        ListRecepi::shou();
        ListRecepi::shoulist();


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
                    time_t t = time(nullptr);
                    tm* now = localtime(&t);
                    string today = to_string(now->tm_mday) + '.' + to_string((now->tm_mon + 1)) + '.' + to_string((now->tm_year + 1900));
                    if(this->Name == today){
                        ListIngredientForRecepi* NowyRabochiy = new ListIngredientForRecepi;
                        ListIngredientForRecepi* TestWorker = ListRecepi::Check(NowyRabochiy->GetName());
                        if (TestWorker == nullptr){
                            ListRecepi::AddElement(*NowyRabochiy);
                        }
                    }
                    else{
                        cout << "Mozhno izmenyat tolko za tekushchij den!";
                    }

                    break;}
            case 27: // esc
                conec = false;
                break;
            default:{}
            }
    }
}
ListIngredientForRecepi* ListRecepi::Check(string N){
    list<ListIngredientForRecepi>::iterator ItrToFind;
    ItrToFind = Spisok.begin();
    for (ItrToFind = Spisok.begin(); ItrToFind != Spisok.end(); ++ItrToFind)
        if (ItrToFind->GetName() == N){
            return ItrToFind->GetPointr();
        };
    return nullptr;
}

ListReports::ListReports(){

}
ListReports::ListReports(string N){
    Name = N;
}
ListReports::ListReports(ifstream *file)
{
    string N;
    string last;
    getline(*file, N, ' ');
    Name = N;
    getline(*file, last);
    int count = 1;
    while ((file->eof() != true) && (count <= stoi(last)))
    {
       ListProducts* NowyRabochiy = new ListProducts(file);
       ListReports::AddElement(*NowyRabochiy);
       count++;
    }
}
void ListReports::shou(){
    cout << Name;
}
void ListReports::shoulist(){
    cout << endl;
    list<ListProducts>::iterator ItrForShouing;
    ItrForShouing = Spisok.begin();
    for (ItrForShouing = Spisok.begin(); ItrForShouing != Spisok.end(); ++ItrForShouing){
        ItrForShouing->shou();
        if (ItrForShouing == SelectedElement){
            cout << " <---";
        }
        cout << endl;
    }
}
void ListReports::AddElement(ListProducts x){
    Spisok.push_back(x);
}
string ListReports::GetName(){
    return this->Name;
}
void ListReports::Control(){
    SelectedElement = Spisok.begin();
    bool conec = true;
    while (conec) {
        system("cls");
        ListReports::shou();
        ListReports::shoulist();


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
                    time_t t = time(nullptr);
                    tm* now = localtime(&t);
                    string today = to_string(now->tm_mday) + '.' + to_string((now->tm_mon + 1)) + '.' + to_string((now->tm_year + 1900));
                    if(this->Name == today){
                        ListProducts* NowyRabochiy = new ListProducts;
                        ListProducts* TestWorker = ListReports::Check(NowyRabochiy->GetName());
                        if (TestWorker == nullptr){
                            ListReports::AddElement(*NowyRabochiy);
                        }
                    }
                    else{
                        cout << "Mozhno izmenyat tolko za tekushchij den!";
                    }

                    break;}
            case 27: // esc
                conec = false;
                break;
            default:{}
            }
    }
}
ListProducts* ListReports::Check(string N){
    list<ListProducts>::iterator ItrToFind;
    ItrToFind = Spisok.begin();
    for (ItrToFind = Spisok.begin(); ItrToFind != Spisok.end(); ++ItrToFind)
        if (ItrToFind->GetName() == N){
            return ItrToFind->GetPointr();
        };
    return nullptr;
}


