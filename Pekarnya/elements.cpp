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
