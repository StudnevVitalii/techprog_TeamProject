#include "controller.h"

Controller::Controller(ListIngredients* ptr_list_ingredients, ListRecepi* ptr_list_recepi, ListReports* ptr_list_reports){
    Sklad = ptr_list_ingredients;
    Kniga_receptov = ptr_list_recepi;
    Spisok_Otchetov = ptr_list_reports;
}

bool Controller::AddElemet(IngredientForRecepi* ptr_ingredient_for_recepi){
    if(Sklad->Check(ptr_ingredient_for_recepi->GetName()) == nullptr){
        return false;
    }
    else{
        return true;
    }
}

bool Controller::AddElemet(Product* ptr_product, int amount){
    ListIngredientForRecepi* recept = Kniga_receptov->Check(ptr_product->GetName());
    unsigned count = 0;
    if(recept != nullptr){ //ввели правильный продукт(рецепт), такой есть в списке рецептов
        list<IngredientForRecepi> Spisok = recept->GetSpisok();
        list<IngredientForRecepi>::iterator SelectedElement;
        for(SelectedElement = Spisok.begin(); SelectedElement != Spisok.end(); ++SelectedElement){
            if(Sklad->Check((*SelectedElement).GetName()) != nullptr){ //есть ингредиент из рецепта на складе
                if(Sklad->Check((*SelectedElement).GetName())->GetValue() >= (amount * (*SelectedElement).GetValue())){//на складе достаточно ингредиентов для добавления готовой продукции
                    ++count;
                }
            }
        }
        if(count == Spisok.size()){
            for(SelectedElement = Spisok.begin(); SelectedElement != Spisok.end(); ++SelectedElement){
                Sklad->Check((*SelectedElement).GetName())->SetValue(Sklad->Check((*SelectedElement).GetName())->GetValue() - ((amount * (*SelectedElement).GetValue())));
            }
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

