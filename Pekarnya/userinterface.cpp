#include "userinterface.h"

using namespace std;

UserInterface::UserInterface()
{

}

void UserInterface::Login(){

    ifstream file;
    file.open("D:/Isxodniki/teamProject/techprog_TeamProject/Pekarnya/listofworkers.txt", ios_base::in);
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
                case 'w':
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
    fileW.open("D:/Isxodniki/teamProject/techprog_TeamProject/Pekarnya/listofworkers.txt", ios_base::in);
    ListWorkers WorkerList(&fileW);

    ifstream fileS;
    fileS.open("D:/Isxodniki/teamProject/techprog_TeamProject/Pekarnya/sklad.txt", ios_base::in);
    ListIngredients Sklad(&fileS);

    bool conec = true;
    while (conec) {
        system("cls");
        cout << "W - workers " << endl;
        cout << "S - sklad " << endl;
        switch (_getch()){
            case 'w':
                    WorkerList.Control();
                    break;
            case 's':
                    Sklad.Control();
                    break;
            case 27: // esc
                conec = false;
                break;
            default:{}
            }
    }

}

void UserInterface::Pekar(){

}

void UserInterface::Sklader(){

}
