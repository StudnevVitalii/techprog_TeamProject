#include "listingredients.h"

ListIngredients::ListIngredients(){

}
ListIngredients::ListIngredients(string N){
    Name = N;
}
ListIngredients::ListIngredients(ifstream *file)
{
    string N;
    string last;
    getline(*file, N, ' ');
    Name = N;
    getline(*file, last);
    int count = 1;
    while ((file->eof() != true) && (count <= stoi(last)))
    {
       Ingredient* NewListIngredients = new Ingredient(file);
       ListIngredients::AddElement(*NewListIngredients);
       count++;
    }
}
void ListIngredients::shou(){
    cout << Name;
}
void ListIngredients::shoulist(){
    cout << endl;
    list<Ingredient>::iterator ItrForShouing;
    ItrForShouing = Spisok.begin();
    for (ItrForShouing = Spisok.begin(); ItrForShouing != Spisok.end(); ++ItrForShouing){
        ItrForShouing->shou();
        if (ItrForShouing == SelectedElement){
            cout << " <---";
        }
        cout << endl;
    }
}
void ListIngredients::AddElement(Ingredient x){
    Spisok.push_back(x);
}
string ListIngredients::GetName(){
    return this->Name;
}
void ListIngredients::Control(){
    SelectedElement = Spisok.begin();
    bool conec = true;
    while (conec) {
        system("cls");
        ListIngredients::shou();
        ListIngredients::shoulist();


        switch (_getch()){
            case 80: //V
                    if (SelectedElement  != Spisok.end())
                    {
                        SelectedElement++;
                    }
                    if (SelectedElement  == Spisok.end())
                    {
                        SelectedElement--;
                    }
                    break;
                    case 72: // ^
                    if (SelectedElement != Spisok.begin())
                    {
                        SelectedElement--;
                    }
            case 'd':

                    break;
            case 'a':{
                    Ingredient* NewListIngredients = new Ingredient;
                    Ingredient* TestListIngredients = ListIngredients::Check(NewListIngredients->GetName());
                    if (TestListIngredients == nullptr){
                        ListIngredients::AddElement(*NewListIngredients);
                    }else{
                        cout << "that user already exist";
                        _getch();
                    }

                    break;}
            case 27: // esc
                conec = false;
                break;
            default:{}
            }
    }
}
Ingredient* ListIngredients::Check(string N){
    list<Ingredient>::iterator ItrToFind;
    ItrToFind = Spisok.begin();
    for (ItrToFind = Spisok.begin(); ItrToFind != Spisok.end(); ++ItrToFind)
        if (ItrToFind->GetName() == N){
            return ItrToFind->GetPointr();
        };
    return nullptr;
}

