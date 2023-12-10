#include "userinterface.h"

UserInterface::UserInterface()
{

}

void UserInterface::Login(){
    Worker Vadim("Vadim","1234","admin");
    Worker Andrey("Andrey","1234","pekar");
    Worker Ivan("Ivan","1234","worker");
    ListWorkers WorkerList("Spisok Rabochich");
    WorkerList.AddElement(Vadim);
    WorkerList.AddElement(Andrey);
    WorkerList.AddElement(Ivan);



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
                    cout << "admin";
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
