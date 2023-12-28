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
       delete NewListIngredients;
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
void ListIngredients::Control(string root){
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
                    break;
            case 'd':
                    if(!Spisok.empty() && root == "admin"){
                        Spisok.erase(SelectedElement);
                        SelectedElement = Spisok.begin();
                    }
                    break;
            case 'a':{
                    Ingredient* NewListIngredients = new Ingredient;
                    Ingredient* TestListIngredients = ListIngredients::Check(NewListIngredients->GetName());
                    if(NewListIngredients->GetValue() != -1 && NewListIngredients->GetED() != ""){
                        if (TestListIngredients == nullptr){
                            ListIngredients::AddElement(*NewListIngredients);
                        }
                        else if(TestListIngredients != nullptr && NewListIngredients->GetED() == TestListIngredients->GetED()){
                            TestListIngredients->SetValue(TestListIngredients->GetValue() + NewListIngredients->GetValue());
                        }
                        else{
                            cout << "neverno vvedeny dannye";
                            _getch();
                        }
                    }
                    delete NewListIngredients;
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

 void ListIngredients::Save(){
     ofstream file_w("D:/WorkFiles/sklad.txt", ios_base::out | ios_base::trunc);
     file_w << Name + ' ';
     if(Spisok.size() == 0){
         file_w << Spisok.size();
     }
     else{
         file_w << Spisok.size() << endl;
     }
     for(SelectedElement = Spisok.begin(); SelectedElement != Spisok.end(); ++SelectedElement){
         if(SelectedElement == --Spisok.end()){
             file_w << (*SelectedElement).GetName() + ' ';
             file_w << to_string((*SelectedElement).GetValue()) + ' ';
             file_w << (*SelectedElement).GetED();
         }
         else{
             file_w << (*SelectedElement).GetName() + ' ';
             file_w << to_string((*SelectedElement).GetValue()) + ' ';
             file_w << (*SelectedElement).GetED() << endl;
         }
     }
     file_w.close();
 }

