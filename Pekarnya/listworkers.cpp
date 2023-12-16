#include "listworkers.h"

ListWorkers::ListWorkers(){

}
ListWorkers::ListWorkers(string N){
    Name = N;
}
ListWorkers::ListWorkers(ifstream *file)
{
    string N;
    string last;
    getline(*file, N, ' ');
    Name = N;
    getline(*file, last);
    int count = 1;
    while ((file->eof() != true) && (count <= stoi(last)))
    {
       Worker* NowyRabochiy = new Worker(file);
       ListWorkers::AddElement(*NowyRabochiy);
       count++;
    }
}
void ListWorkers::shou(){
    cout << Name;
}
void ListWorkers::shoulist(){
    cout << endl;
    list<Worker>::iterator ItrForShouing;
    ItrForShouing = Spisok.begin();
    for (ItrForShouing = Spisok.begin(); ItrForShouing != Spisok.end(); ++ItrForShouing){
        ItrForShouing->shou();
        if (ItrForShouing == SelectedElement){
            cout << " <---";
        }
        cout << endl;
    }
}
void ListWorkers::AddElement(Worker x){
    Spisok.push_back(x);
}
string ListWorkers::GetName(){
    return this->Name;
}
void ListWorkers::Control(){
    SelectedElement = Spisok.begin();
    bool conec = true;
    while (conec) {
        system("cls");
        ListWorkers::shou();
        ListWorkers::shoulist();


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
                    Worker* NowyRabochiy = new Worker;
                    Worker* TestWorker = ListWorkers::Check(NowyRabochiy->GetName());
                    if (TestWorker == nullptr){
                        ListWorkers::AddElement(*NowyRabochiy);
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
Worker* ListWorkers::Check(string N){
    list<Worker>::iterator ItrToFind;
    ItrToFind = Spisok.begin();
    for (ItrToFind = Spisok.begin(); ItrToFind != Spisok.end(); ++ItrToFind)
        if (ItrToFind->GetName() == N){
            return ItrToFind->GetPointr();
        };
    return nullptr;
}
