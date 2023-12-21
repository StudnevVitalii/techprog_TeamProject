#include "ingredientforrecepi.h"

IngredientForRecepi::IngredientForRecepi()
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
IngredientForRecepi::IngredientForRecepi(string n,int v,string e):Ingredient(n,v,e)
{

}
IngredientForRecepi::IngredientForRecepi(ifstream *file):Ingredient(file)
{

}
IngredientForRecepi* IngredientForRecepi::GetPointr()
{
    return this;
}

