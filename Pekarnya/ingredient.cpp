#include "ingredient.h"

Ingredient::Ingredient()
    {
    string n, e, temp_v;
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
        cout << "Neobhodimo ukazat edinicu izmereniya ingredienta." << endl;
        cout << "Tri edinicy izmereniya: 1 - gr. 2 - sht. 3 - ml. (ukazhite cifru)" << endl;
        cout << "Edinica izmereniya ingredienta: ";
        cin >> e;
        _flushall();
        if(e == "1"){
            ED = "gr.";
        }
        else if(e == "2"){
            ED = "sht.";
        }
        else if(e == "3"){
            ED = "ml.";
        }
        else{
            ED = "";
            cout << "Vy vveli nekorrektnoe chislo!!!" << endl;
            system("pause");
        }
    }
    else{
        temp_v = "-1";
        Value = stoi(temp_v);
        ED = "";
        cout << "Vy vveli nekorrektnoe chislo!!!" << endl;
        system("pause");
    }
    }

Ingredient::Ingredient(int a)
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

string Ingredient::GetED(){
    return ED;
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

