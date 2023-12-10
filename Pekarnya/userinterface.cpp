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
                    WorkerList.Control();
                    exit = true;
                    break;
                case 'p':
                    cout << "pekar";
                    exit = true;
                    break;
                case 'w':
                    cout << "worker";
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
