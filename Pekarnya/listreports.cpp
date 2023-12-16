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
void ListReports::Control(){
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
            case 'd':

                    break;
            case 'a':{
                    time_t t = time(nullptr);
                    tm* now = localtime(&t);
                    string today = to_string(now->tm_mday) + '.' + to_string((now->tm_mon + 1)) + '.' + to_string((now->tm_year + 1900));
                    if(this->Name == today){
                        ListProducts* NewListProducts = new ListProducts;
                        ListProducts* TestListProducts = ListReports::Check(NewListProducts->GetName());
                        if (TestListProducts == nullptr){
                            ListReports::AddElement(*NewListProducts);
                        }
                    }
                    else{
                        cout << "Mozhno izmenyat tolko za tekushchij den!";
                    }

                    break;}
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

