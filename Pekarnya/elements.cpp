#include "elements.h"

using namespace std;

Worker::Worker()
    {

    }
Worker::Worker(string L,string P, string R)
   {
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
