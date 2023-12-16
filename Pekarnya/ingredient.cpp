#include "ingredient.h"

Ingredient::Ingredient()
    {
    string n, e;
    int v;
    cout << "Vvedite naimenovanie: " << endl;
    cin >> n;
    Name = n;
    cout << "Vvedite kol-vo: " << endl;
    cin >> v;
    Value = v;
    cout << "Vvedite edenicy izmereniya: " << endl;
    cin >> e;
    ED = e;

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
void Ingredient::SetValue(int Value){
    this->Value = Value;
}

void Ingredient::shou()
   {
       cout << Name << "   " << Value << "   " << ED << "   "  ;
   }
Ingredient* Ingredient::GetPointr(){
    return this;
    }

