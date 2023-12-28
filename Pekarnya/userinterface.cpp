#include "userinterface.h"

using namespace std;

UserInterface::UserInterface()
{

}

void UserInterface::Login(){

    ifstream file;
    file.open("D:/WorkFiles/listofworkers.txt", ios_base::in);
    ListWorkers WorkerList(&file);




    string login;
    string password;
    bool exit = false;
    do{
        cout << "Login: ";
        cin >> login;
        Worker* buff = WorkerList.Check(login);
        if(buff == nullptr){
            cout << "Takogo polzovatelya ne sushchestvuet!!" << endl;
        }
        else{
            cout << "Parol: ";
            cin >> password;
            if(buff->GetPassword() == password){
                switch (buff->GetRoot()[0]) {
                case 'a':
                    UserInterface::Admin();
                    exit = true;
                    break;
                case 'p':
                    UserInterface::Pekar();
                    exit = true;
                    break;
                case 'r':
                    UserInterface::Sklader();
                    exit = true;
                    break;
                }
            }
            else{
                cout << "Vveden nevernyj parol polzovatelya!!" << endl;
            }
        }
    }while(!exit);
}

void UserInterface::Admin(){
    ifstream fileW;
    fileW.open("D:/WorkFiles/listofworkers.txt", ios_base::in);
    ListWorkers WorkerList(&fileW);
    fileW.close();

    ifstream fileS;
    fileS.open("D:/WorkFiles/sklad.txt", ios_base::in);
    ListIngredients Sklad(&fileS);
    fileS.close();

    ifstream fileR;
    fileR.open("D:/WorkFiles/listofrecepi.txt", ios_base::in);
    ListRecepi ListOfRecepi(&fileR);
    fileR.close();

    ifstream fileP;
    fileP.open("D:/WorkFiles/listofproducts.txt", ios_base::in);
    ListReports ListOfReports(&fileP);
    fileP.close();

    time_t t = time(nullptr);
    tm* now = localtime(&t);
    string today = to_string(now->tm_mday) + '.' + to_string((now->tm_mon + 1)) + '.' + to_string((now->tm_year + 1900));
    if (ListOfReports.Check(today) == nullptr)
    {
        ListProducts* NewListProducts = new ListProducts(today);
        ListOfReports.AddElement(*NewListProducts);
        delete NewListProducts;
    }




    string root = "admin";
    bool conec = true;
    while (conec) {
        system("cls");
        cout << "W - workers " << endl;
        cout << "S - sklad " << endl;
        cout << "R - recepi " << endl;
        cout << "O - otchety " << endl;
        switch (_getch()){
            case 'w':
                    WorkerList.Control(root);
                    break;
            case 's':
                    Sklad.Control(root);
                    break;
            case 'r':
                    ListOfRecepi.Control(&Sklad, root);
                    break;
            case 'o':
                    ListOfReports.Control(&ListOfRecepi,&Sklad);
                    break;
            case 27: // esc
                conec = false;
                WorkerList.Save();
                Sklad.Save();
                ListOfRecepi.Save();
                ListOfReports.Save();
                break;
            default:{}
            }
    }
}

void UserInterface::Pekar(){


    ifstream fileS;
    fileS.open("D:/WorkFiles/sklad.txt", ios_base::in);
    ListIngredients Sklad(&fileS);
    fileS.close();

    ifstream fileR;
    fileR.open("D:/WorkFiles/listofrecepi.txt", ios_base::in);
    ListRecepi ListOfRecepi(&fileR);
    fileR.close();

    ifstream fileP;
    fileP.open("D:/WorkFiles/listofproducts.txt", ios_base::in);
    ListReports ListOfReports(&fileP);
    fileP.close();

    time_t t = time(nullptr);
    tm* now = localtime(&t);
    string today = to_string(now->tm_mday) + '.' + to_string((now->tm_mon + 1)) + '.' + to_string((now->tm_year + 1900));
    if (ListOfReports.Check(today) == nullptr)
    {
        ListProducts* NewListProducts = new ListProducts(today);
        ListOfReports.AddElement(*NewListProducts);
        delete NewListProducts;
    }




    string root = "pekar";
    bool conec = true;
    while (conec) {
        system("cls");

        cout << "S - sklad " << endl;
        cout << "R - recepi " << endl;
        cout << "O - otchet " << endl;
        switch (_getch()){
            case 's':
                    Sklad.Control(root);
                    break;
            case 'r':
                    ListOfRecepi.Control(&Sklad, root);
                    break;
            case 'o':
                    ListOfReports.Check(today)->Control(&ListOfRecepi,&Sklad);
                    break;
            case 27: // esc
                conec = false;

                Sklad.Save();
                ListOfRecepi.Save();
                ListOfReports.Save();
                break;
            default:{}
            }
    }

}

void UserInterface::Sklader(){
    ifstream fileS;
    fileS.open("D:/WorkFiles/sklad.txt", ios_base::in);
    ListIngredients Sklad(&fileS);
    fileS.close();
    string root = "rabochiy";
    Sklad.Control(root);
    Sklad.Save();
}
