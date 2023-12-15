#include "listrecepi.h"

ListRecepi::ListRecepi(){

}
ListRecepi::ListRecepi(string N){
    Name = N;
}
ListRecepi::ListRecepi(ifstream *file)
{
    string N;
    string last;
    getline(*file, N, ' ');
    Name = N;
    getline(*file, last);
    int count = 1;
    while ((file->eof() != true) && (count <= stoi(last)))
    {
       ListIngredientForRecepi* NowyRabochiy = new ListIngredientForRecepi(file);
       ListRecepi::AddElement(*NowyRabochiy);
       count++;
    }
}
void ListRecepi::shou(){
    cout << Name;
}
void ListRecepi::shoulist(){
    cout << endl;
    list<ListIngredientForRecepi>::iterator ItrForShouing;
    ItrForShouing = Spisok.begin();
    for (ItrForShouing = Spisok.begin(); ItrForShouing != Spisok.end(); ++ItrForShouing){
        ItrForShouing->shou();
        if (ItrForShouing == SelectedElement){
            cout << " <---";
        }
        cout << endl;
    }
}
void ListRecepi::AddElement(ListIngredientForRecepi x){
    Spisok.push_back(x);
}
string ListRecepi::GetName(){
    return this->Name;
}
void ListRecepi::Control(){
    SelectedElement = Spisok.begin();
    bool conec = true;
    while (conec) {
        system("cls");
        ListRecepi::shou();
        ListRecepi::shoulist();


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
                        ListIngredientForRecepi* NowyRabochiy = new ListIngredientForRecepi;
                        ListIngredientForRecepi* TestWorker = ListRecepi::Check(NowyRabochiy->GetName());
                        if (TestWorker == nullptr){
                            ListRecepi::AddElement(*NowyRabochiy);
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
ListIngredientForRecepi* ListRecepi::Check(string N){
    list<ListIngredientForRecepi>::iterator ItrToFind;
    ItrToFind = Spisok.begin();
    for (ItrToFind = Spisok.begin(); ItrToFind != Spisok.end(); ++ItrToFind)
        if (ItrToFind->GetName() == N){
            return ItrToFind->GetPointr();
        };
    return nullptr;
}
