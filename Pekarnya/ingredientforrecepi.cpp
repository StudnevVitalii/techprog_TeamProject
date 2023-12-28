#include "ingredientforrecepi.h"


IngredientForRecepi::IngredientForRecepi(int a):Ingredient(a)
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
    }else{
        cout << "Vy vveli nekorrektnoe chislo!!!" << endl;
        system("pause");
        Value = -1;
    }}


IngredientForRecepi::IngredientForRecepi():Ingredient()
{

}

IngredientForRecepi::IngredientForRecepi(ifstream *file):Ingredient(file)
{

}
IngredientForRecepi* IngredientForRecepi::GetPointr()
{
    return this;
}
void IngredientForRecepi::SetED(string ED){
    this->ED = ED;
}
