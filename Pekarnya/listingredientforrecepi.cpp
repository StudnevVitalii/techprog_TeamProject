#include "listingredientforrecepi.h"

ListIngredientForRecepi::ListIngredientForRecepi(){
    cout << "Vvedite imya:";
    cin >> Name;
}
ListIngredientForRecepi::ListIngredientForRecepi(string N){
    Name = N;
}
ListIngredientForRecepi::ListIngredientForRecepi(ifstream *file)
{
    string N;
    string last;
    getline(*file, N, ' ');
    Name = N;
    getline(*file, last);
    int count = 1;
    while ((file->eof() != true) && (count <= stoi(last)))
    {
       IngredientForRecepi* NewIngredientForRecepi = new IngredientForRecepi(file);
       ListIngredientForRecepi::AddElement(*NewIngredientForRecepi);
       count++;
    }
}
void ListIngredientForRecepi::shou(){
    cout << Name;
}
void ListIngredientForRecepi::shoulist(){
    cout << endl;
    list<IngredientForRecepi>::iterator ItrForShouing;
    ItrForShouing = Spisok.begin();
    for (ItrForShouing = Spisok.begin(); ItrForShouing != Spisok.end(); ++ItrForShouing){
        ItrForShouing->shou();
        if (ItrForShouing == SelectedElement){
            cout << " <---";
        }
        cout << endl;
    }
}
void ListIngredientForRecepi::AddElement(IngredientForRecepi x){
    Spisok.push_back(x);
}
string ListIngredientForRecepi::GetName(){
    return this->Name;
}
void ListIngredientForRecepi::Control(ListIngredients* sklad){
    SelectedElement = Spisok.begin();
    bool conec = true;
    while (conec) {
        system("cls");
        ListIngredientForRecepi::shou();
        ListIngredientForRecepi::shoulist();


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
                    IngredientForRecepi* NewIngredientForRecepi = new IngredientForRecepi;
                    IngredientForRecepi* TestIngredientForRecepi = ListIngredientForRecepi::Check(NewIngredientForRecepi->GetName());
                    if (TestIngredientForRecepi == nullptr && NewIngredientForRecepi->GetValue() != -1 && NewIngredientForRecepi->GetED() != ""){
                        ListIngredientForRecepi::AddElement(*NewIngredientForRecepi);
                    }else{
                        cout << "that ingridient exist";
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
IngredientForRecepi* ListIngredientForRecepi::Check(string N){
    list<IngredientForRecepi>::iterator ItrToFind;
    ItrToFind = Spisok.begin();
    for (ItrToFind = Spisok.begin(); ItrToFind != Spisok.end(); ++ItrToFind)
        if (ItrToFind->GetName() == N){
            return ItrToFind->GetPointr();
        };
    return nullptr;
}
ListIngredientForRecepi* ListIngredientForRecepi::GetPointr(){
    return this;
}

list<IngredientForRecepi> ListIngredientForRecepi::GetSpisok(){
    return this->Spisok;
}

void ListIngredientForRecepi::Save(ofstream* file_w){
    for(unsigned int i = 0; i < Name.size(); ++i){
        file_w->put(Name[i]);
    }
    file_w->put(' ');
    if(Spisok.size() == 0){
        file_w->put('0');
    }
    else{
        string str = to_string(Spisok.size());
        for(unsigned int i = 0; i < str.size(); ++i){
            file_w->put(str[i]);
        }
        file_w->operator <<(endl);
    }
    for(SelectedElement = Spisok.begin(); SelectedElement != Spisok.end(); ++SelectedElement){
        if(SelectedElement == --Spisok.end()){
            string str = (*SelectedElement).GetName();
            for(unsigned int i = 0; i < str.size(); ++i){
                file_w->put(str[i]);
            }
            file_w->put(' ');
            string str1 = to_string((*SelectedElement).GetValue());
            for(unsigned int i = 0; i < str1.size(); ++i){
                file_w->put(str1[i]);
            }
            file_w->put(' ');
            string str2 = (*SelectedElement).GetED();
            for(unsigned int i = 0; i < str2.size(); ++i){
                file_w->put(str2[i]);
            }
        }
        else{
            string str = (*SelectedElement).GetName();
            for(unsigned int i = 0; i < str.size(); ++i){
                file_w->put(str[i]);
            }
            file_w->put(' ');
            string str1 = to_string((*SelectedElement).GetValue());
            for(unsigned int i = 0; i < str1.size(); ++i){
                file_w->put(str1[i]);
            }
            file_w->put(' ');
            string str2 = (*SelectedElement).GetED();
            for(unsigned int i = 0; i < str2.size(); ++i){
                file_w->put(str2[i]);
            }
            file_w->operator <<(endl);
        }
    }
}
