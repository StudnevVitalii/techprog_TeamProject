#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include <fstream>
#include <string>
#include "listworkers.h"
#include "listingredients.h"
#include "listrecepi.h"
#include "listreports.h"

using namespace std;

class UserInterface
{
public:
    UserInterface();
    void Login();
    void Admin();
    void Pekar();
    void Sklader();
};

#endif // USERINTERFACE_H
