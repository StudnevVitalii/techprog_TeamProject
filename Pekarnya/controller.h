#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "listingredients.h"
#include "listrecepi.h"
#include "listreports.h"

class Controller
{
private:
    ListIngredients* Sklad;
    ListRecepi* Kniga_receptov;
    ListReports* Spisok_Otchetov;
public:
    Controller(ListIngredients*,ListRecepi*,ListReports*);
    bool AddElemet(IngredientForRecepi*);
    bool AddElemet(Product*, int);

};

#endif // CONTROLLER_H
