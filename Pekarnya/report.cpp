#include "report.h"

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
       delete NewListProducts;
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
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    string today = to_string(now->tm_mday) + '.' + to_string((now->tm_mon + 1)) + '.' + to_string((now->tm_year + 1900));
    bool conec = true;
    while (conec) {
        system("cls");


        if(this->Name == today){
        cout << "a - add product " << endl;}

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
                            if(this->Name == today){
                                Product* NewListProducts = new Product;
                                Product* TestListProducts = ListProducts::Check(NewListProducts->GetName());
                                if (NewListProducts->GetValue() != -1 && Proverka(NewListProducts, ListOfRecepi, sklad)){
                                    if(TestListProducts == nullptr){
                                        ListProducts::AddElement(*NewListProducts);
                                    }
                                    else{
                                        TestListProducts->IncValue(NewListProducts->GetValue());
                                    }
                                }
                                else if(!Proverka(NewListProducts, ListOfRecepi, sklad)){
                                    cout << "Nelzya dobavit produkt v otchet (ne hvataet ingredientov na sklade)" << endl;
                                    system("pause");
                                }
                                delete NewListProducts;
                            }
                            else{
                                cout << "Mozhno izmenyat tolko za tekushchij den!";
                                system("pause");
                            }
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

bool ListProducts::Proverka(Product* ptr_product, ListRecepi* ptr_list_recepi, ListIngredients* ptr_list_ingredient){
    ListIngredientForRecepi* recept = ptr_list_recepi->Check(ptr_product->GetName());
    unsigned count = 0;
    if(recept != nullptr){ //ввели правильный продукт(рецепт), такой есть в списке рецептов
        list<IngredientForRecepi> Spisok = recept->GetSpisok();
        list<IngredientForRecepi>::iterator SelectedElement;
        for(SelectedElement = Spisok.begin(); SelectedElement != Spisok.end(); ++SelectedElement){
            if(ptr_list_ingredient->Check((*SelectedElement).GetName()) != nullptr){ //есть ингредиент из рецепта на складе
                if(ptr_list_ingredient->Check((*SelectedElement).GetName())->GetValue() >= (ptr_product->GetValue() * (*SelectedElement).GetValue())){//на складе достаточно ингредиентов для добавления готовой продукции
                    ++count;
                }
            }
        }
        if(count == Spisok.size()){
            for(SelectedElement = Spisok.begin(); SelectedElement != Spisok.end(); ++SelectedElement){
                ptr_list_ingredient->Check((*SelectedElement).GetName())->SetValue(ptr_list_ingredient->Check((*SelectedElement).GetName())->GetValue() - ((ptr_product->GetValue() * (*SelectedElement).GetValue())));
            }
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
