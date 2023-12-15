#include "worker.h"

Worker::Worker()
    {
        cout << "Vvedite login: " << endl;
        cin >> this->Login;
        cout << "Vvedite parol: " << endl;
        cin >> this->Password;
        cout << "Vvedite Root: " << endl;
        cin >> this->Root;
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

