#include "elements.h"

using namespace std;

Worker::Worker()
    {
        cout << "Vvedite login: " << endl;
        cin >> this->Login;
        cout << "Vvedite parol: " << endl;
        cin >> this->Password;
        cout << "Vvedite Root: " << endl;
        cin >> this->Root;
    }
Worker::Worker(string L,string P, string R)
   {
        Login = L;
        Password = P;
        Root = R;
   }
Worker::Worker(ifstream *file)
{
    string L;
    string P;
    string R;

    getline(*file, L, ' ');
    getline(*file, P, ' ');
    getline(*file, R);
    Login = L;
    Password = P;
    Root = R;
}
string Worker::GetName()
   {
       return Login;
   }
string Worker::GetPassword()
   {
       return Password;
   }
string Worker::GetRoot(){
    return Root;
}
void Worker::shou()
   {
       cout << Login << "   " << Password << "   " << Root;
   }
Worker* Worker::GetPointr(){ //итератор сам не даёт указатель
    return this;
    }



Ingredient::Ingredient()
    {


    }
Ingredient::Ingredient(string n,int v,string e)
   {
       Name = n;
       Value = v;
       ED = e;
   }
Ingredient::Ingredient(ifstream *file)
{
    string N;
    string temp_V;
    string ED;

    getline(*file, N, ' ');
    getline(*file, temp_V, ' ');
    getline(*file, ED);
    Name = N;
    Value = stoi(temp_V);
    this->ED = ED;
}
string Ingredient::GetName()
   {
       return Name;
   }
int Ingredient::GetValue()
   {
       return Value;
   }
void Ingredient::shou()
   {
       cout << Name << "   " << Value << "   " << ED << "   "  ;
   }
Ingredient* Ingredient::GetPointr(){
    return this;
    }

IngredientForRecepi::IngredientForRecepi():Ingredient(){}

IngredientForRecepi::IngredientForRecepi(string n,int v,string e):Ingredient(n,v,e){}

IngredientForRecepi::IngredientForRecepi(ifstream *file):Ingredient(file){}





Product::Product()
    {

    }
Product::Product(string n,int v)
   {
       Name = n;
       Value = v;
   }
string Product::GetName()
   {
       return Name;
   }
int Product::GetValue()
   {
       return Value;
   }
void Product::shou()
   {
       cout << Name << "   " << Value <<  "   "  ;

   }

