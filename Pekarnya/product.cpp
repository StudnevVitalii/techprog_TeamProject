#include "product.h"

Product::Product()
    {
    string n, temp_v;
    char mas[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    unsigned int count = 0;
    cout << "Vvedite naimenovanie: " << endl;
    cin >> n;
    _flushall();
    Name = n;
    cout << "Vvedite kol-vo: " << endl;
    cin >> temp_v;
    _flushall();
    for(unsigned int i = 0; i < temp_v.size(); ++i){
    bool exists = false;
        for (int j: mas){
            if (j == temp_v[i]) {
                exists = true;
                break;
            }
        }
        if(exists){
            count++;
        }
    }
    if(count == temp_v.size()){
        Value = stoi(temp_v);
    }
    else{
        temp_v = "-1";
        Value = stoi(temp_v);
        cout << "Vy vveli nekorrektnoe chislo!!!" << endl;
        system("pause");
    }
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

