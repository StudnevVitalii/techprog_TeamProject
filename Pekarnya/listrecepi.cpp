#include "listrecepi.h"

ListRecepi::ListRecepi(){

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
       ListIngredientForRecepi* NewListRecepi = new ListIngredientForRecepi(file);
       ListRecepi::AddElement(*NewListRecepi);
       delete NewListRecepi;
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

void ListRecepi::Control(ListIngredients *sklad, string root){
    SelectedElement = Spisok.begin();
    bool conec = true;
    while (conec) {
        system("cls");

        if(root == "admin"){
            cout << "d - delete recepi " << endl;
            cout << "a - add recepi " << endl;
        }

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
                    break;
            case 'd':
                    if(!Spisok.empty() && root == "admin"){
                        Spisok.erase(SelectedElement);
                        SelectedElement = Spisok.begin();
                    }
                    break;
            case 'a':{if(root == "admin"){
                    ListIngredientForRecepi* NewListRecepi = new ListIngredientForRecepi;
                    ListIngredientForRecepi* TestListRecepi = ListRecepi::Check(NewListRecepi->GetName());
                    if (TestListRecepi == nullptr){
                        ListRecepi::AddElement(*NewListRecepi);
                    }
                    delete NewListRecepi;}
                    break;}
            case 13:
                    (*SelectedElement).Control(sklad, root);
                    break;
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


void ListRecepi::Save(){
    ofstream file_w("D:/WorkFiles/listofrecepi.txt", ios_base::out | ios_base::trunc);
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
