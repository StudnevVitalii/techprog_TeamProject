#include "listreports.h"

ListReports::ListReports(){

}
ListReports::ListReports(string N){
    Name = N;
}
ListReports::ListReports(ifstream *file)
{
    string N;
    string last;
    getline(*file, N, ' ');
    Name = N;
    getline(*file, last);
    int count = 1;
    while ((file->eof() != true) && (count <= stoi(last)))
    {
       ListProducts* NewListProducts = new ListProducts(file);
       ListReports::AddElement(*NewListProducts);
       count++;
    }
}
void ListReports::shou(){
    cout << Name;
}
void ListReports::shoulist(){
    cout << endl;
    list<ListProducts>::iterator ItrForShouing;
    ItrForShouing = Spisok.begin();
    for (ItrForShouing = Spisok.begin(); ItrForShouing != Spisok.end(); ++ItrForShouing){
        ItrForShouing->shou();
        if (ItrForShouing == SelectedElement){
            cout << " <---";
        }
        cout << endl;
    }
}
void ListReports::AddElement(ListProducts x){
    Spisok.push_back(x);
}
string ListReports::GetName(){
    return this->Name;
}
void ListReports::Control(ListRecepi* ListOfRecepi,ListIngredients* sklad){
    SelectedElement = Spisok.begin();
    bool conec = true;
    while (conec) {
        system("cls");
        ListReports::shou();
        ListReports::shoulist();


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
            case 13:
                    SelectedElement->Control(ListOfRecepi,sklad);
                    break;
            case 27: // esc
                conec = false;
                break;
            default:{}
            }
    }
}
ListProducts* ListReports::Check(string N){
    list<ListProducts>::iterator ItrToFind;
    ItrToFind = Spisok.begin();
    for (ItrToFind = Spisok.begin(); ItrToFind != Spisok.end(); ++ItrToFind)
        if (ItrToFind->GetName() == N){
            return ItrToFind->GetPointr();
        };
    return nullptr;
}

void ListReports::Save(){
    ofstream file_w("D:/WorkFiles/listofproducts.txt", ios_base::out | ios_base::trunc);
    file_w << Name + ' ';
    if(Spisok.size() == 0){
        file_w << Spisok.size();
    }
    else{
        file_w << Spisok.size() << endl;
    }
    for(SelectedElement = Spisok.begin(); SelectedElement != Spisok.end(); ++SelectedElement){
        if(SelectedElement == Spisok.begin()){
            (*SelectedElement).Save(&file_w);
        }
        else{
            file_w.operator <<(endl);
            (*SelectedElement).Save(&file_w);
        }
    }
    file_w.close();
}
