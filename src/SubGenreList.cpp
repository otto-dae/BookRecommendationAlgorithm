#include "../headers/SubGenreList.hpp"
#include "../headers/GeneralFunctions.hpp"
#include <iostream>
#include <string>
#include <algorithm> //to make strings to lower

using namespace std;



void insertSubGenre(SubGenre*& headSubGenre, SubGenre* newSubGenre){

    if(headSubGenre == nullptr || newSubGenre->Id < headSubGenre->Id){
        newSubGenre->next = headSubGenre;
        headSubGenre = newSubGenre;
        incrementCount(3);
        return;
    }
    SubGenre *actual=headSubGenre;
    while (actual->next != nullptr && actual->next->Id < newSubGenre->Id){
        actual = actual->next;
        incrementCount(1);
    }
    
    newSubGenre->next = actual->next;
    actual->next = newSubGenre;    
    incrementCount(2);
}

void showSubGenres(SubGenre* headSubGenre){
    SubGenre *actual=headSubGenre;
    while (actual != nullptr){
        cout << actual->Id << " | "<<actual->Title << endl;
        actual = actual->next;
        incrementCount(2);
    }    
    incrementCount(1);
    
}

string getSubGenre(SubGenre* headSubGenre, int targetSubGenre){
    SubGenre *actual=headSubGenre;
    while (actual->next != nullptr){

        if(actual->Id == targetSubGenre){
            incrementCount(1);
            return actual->Title;
        }
        incrementCount(1);
        actual = actual->next;
    }

    return "Error. . . ";
}
