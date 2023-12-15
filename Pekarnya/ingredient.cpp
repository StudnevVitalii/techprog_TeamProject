#include "ingredient.h"

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

