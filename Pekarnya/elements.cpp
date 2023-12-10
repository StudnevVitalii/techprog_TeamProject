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
Worker* Worker::GetPointr(){
    return this;
    }



Ingridient::Ingridient()
    {


    }
Ingridient::Ingridient(string n,int v,string e)
   {
       Name = n;
       Value = v;
       ED = e;
   }

string Ingridient::GetName()
   {
       return Name;
   }
int Ingridient::GetValue()
   {
       return Value;
   }
void Ingridient::shou()
   {
       cout << Name << "   " << Value << "   " << ED << "   "  ;
   }


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
