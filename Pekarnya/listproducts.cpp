#include "listproducts.h"

ListProducts::ListProducts(){

}
ListProducts::ListProducts(string N){
    Name = N;
}
ListProducts::ListProducts(ifstream *file)
{
    string N;
    string last;
    getline(*file, N, ' ');
    Name = N;
    getline(*file, last);
    int count = 1;
    while ((file->eof() != true) && (count <= stoi(last)))
    {
       Product* NewListProducts = new Product(file);
       ListProducts::AddElement(*NewListProducts);
       count++;
    }
}
void ListProducts::shou(){
    cout << Name;
}
void ListProducts::shoulist(){
    cout << endl;
    list<Product>::iterator ItrForShouing;
    ItrForShouing = Spisok.begin();
    for (ItrForShouing = Spisok.begin(); ItrForShouing != Spisok.end(); ++ItrForShouing){
        ItrForShouing->shou();
        if (ItrForShouing == SelectedElement){
            cout << " <---";
        }
        cout << endl;
    }
}
void ListProducts::AddElement(Product x){
    Spisok.push_back(x);
}
string ListProducts::GetName(){
    return this->Name;
}
void ListProducts::Control(ListRecepi* ListOfRecepi,ListIngredients* sklad){
    SelectedElement = Spisok.begin();
    bool conec = true;
    while (conec) {
        system("cls");
        ListProducts::shou();
        ListProducts::shoulist();


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
                    time_t t = time(nullptr);
                    tm* now = localtime(&t);
                    string today = to_string(now->tm_mday) + '.' + to_string((now->tm_mon + 1)) + '.' + to_string((now->tm_year + 1900));
                    if(this->Name == today){
                        Product* NewListProducts = new Product;
                        Product* TestListProducts = ListProducts::Check(NewListProducts->GetName());
                        if (TestListProducts == nullptr && NewListProducts->GetValue() != -1){
                            ListProducts::AddElement(*NewListProducts);
                        }
                    }
                    else{
                        cout << "Mozhno izmenyat tolko za tekushchij den!";
                    }
                    // вставить проверку сюда

                    break;}
            case 27: // esc
                conec = false;
                break;
            default:{}
            }
    }
}
Product* ListProducts::Check(string N){
    list<Product>::iterator ItrToFind;
    ItrToFind = Spisok.begin();
    for (ItrToFind = Spisok.begin(); ItrToFind != Spisok.end(); ++ItrToFind)
        if (ItrToFind->GetName() == N){
            return ItrToFind->GetPointr();
        };
    return nullptr;
}
ListProducts* ListProducts::GetPointr(){
    return this;
}

void ListProducts::Save(ofstream* file_w){
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
            file_w->operator <<(endl);
        }
    }
}
