#include "product.h"

Product::Product()
    {
    cout << "Vvedite Name: " << endl;
    cin >> this->Name;
    cout << "Vvedite Value: " << endl;
    cin >> this->Value;
    }
Product::Product(string n,int v)
   {
       Name = n;
       Value = v;
   }
Product::Product(ifstream *file)
{
    string N;
    string temp_V;

    getline(*file, N, ' ');
    getline(*file, temp_V);
    Name = N;
    Value = stoi(temp_V);
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
Product* Product::GetPointr(){ //итератор сам не даёт указатель
    return this;
    }

