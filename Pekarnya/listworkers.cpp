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
       Worker* NewListWorkers = new Worker(file);
       ListWorkers::AddElement(*NewListWorkers);
       delete NewListWorkers;
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
void ListWorkers::Control(string root){
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
                    break;
            case 'd':
                    if(!Spisok.empty() && SelectedElement->GetRoot() != "admin" && root == "admin"){
                        Spisok.erase(SelectedElement);
                        SelectedElement = Spisok.begin();
                    }
                    break;
            case 'a':{
                    Worker* NewListWorkers = new Worker;
                    Worker* TestListWorkers = ListWorkers::Check(NewListWorkers->GetName());
                    if (TestListWorkers == nullptr && NewListWorkers->GetPassword() != "" && NewListWorkers->GetRoot() != ""){
                        ListWorkers::AddElement(*NewListWorkers);
                    }else{
                        cout << "that user already exist";
                        _getch();
                    }
                    delete NewListWorkers;
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
void ListWorkers::Save(){
    ofstream file_w("D:/WorkFiles/listofworkers.txt", ios_base::out | ios_base::trunc);
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
            file_w << (*SelectedElement).GetPassword() + ' ';
            file_w << (*SelectedElement).GetRoot();
        }
        else{
            file_w << (*SelectedElement).GetName() + ' ';
            file_w << (*SelectedElement).GetPassword() + ' ';
            file_w << (*SelectedElement).GetRoot() << endl;
        }
    }
    file_w.close();
}




















