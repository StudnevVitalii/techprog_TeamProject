#include "worker.h"

Worker::Worker()
    {
        string temp_password, temp_root;
        char mas[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        unsigned int count = 0;
        cout << "Vvedite login: " << endl;
        cin >> this->Login;
        cout << "Vvedite parol: " << endl;
        cin >> temp_password;
        _flushall();
        for(unsigned int i = 0; i < temp_password.size(); ++i){
        bool exists = false;
            for (int j: mas){
                if (j == temp_password[i]) {
                    exists = true;
                    break;
                }
            }
            if(exists){
                count++;
            }
        }
        if(count == temp_password.size()){
            Password = temp_password;
            cout << "Neobhodimo ukazat prava dostupa." << endl;
            cout << "Prava dostupa: 1 - pekar, 2 - rabochiy.(ukazhite cifru)" << endl;
            cout << "Prava dostupa: ";
            cin >> temp_root;
            _flushall();
            if(temp_root == "1"){
                Root = "pekar";
            }
            else if(temp_root == "2"){
                Root = "rabochiy";
            }
            else{
                Root = "";
                cout << "Vy vveli nekorrektnoe chislo!!!" << endl;
                system("pause");
            }
        }
        else{
            Password = "";
            Root = "";
            cout << "Vy vveli nekorrektnij parol!!!" << endl;
            system("pause");
        }
    }
Worker::Worker(string L,string P, string R)
   {
        Login = L;
        Password = P;
        Root = R;
   }
Worker::Worker(ifstream *file)
{
    string L;
    string P;
    string R;

    getline(*file, L, ' ');
    getline(*file, P, ' ');
    getline(*file, R);
    Login = L;
    Password = P;
    Root = R;
}
string Worker::GetName()
   {
       return Login;
   }
string Worker::GetPassword()
   {
       return Password;
   }
string Worker::GetRoot(){
    return Root;
}
void Worker::shou()
   {
       cout << Login << "   " << Password << "   " << Root;
   }
Worker* Worker::GetPointr(){ //итератор сам не даёт указатель
    return this;
    }

