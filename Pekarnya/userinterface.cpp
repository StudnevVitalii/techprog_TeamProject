#include "userinterface.h"

UserInterface::UserInterface()
{

}

void UserInterface::Login(){

    ifstream file;
    file.open("D:/Team_project_ver2.0/Pekarnya/listofworkers.txt", ios_base::in);
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

}

void UserInterface::Pekar(){

}

void UserInterface::Sklader(){

}
