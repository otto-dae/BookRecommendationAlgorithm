#include "../headers/SubGenreList.hpp"
#include <iostream>
#include <string>
#include <algorithm> //to make strings to lower

using namespace std;



void insertSubGenre(SubGenre*& headSubGenre, SubGenre* newSubGenre){

    if(headSubGenre == nullptr || newSubGenre->Id < headSubGenre->Id){
        newSubGenre->next = headSubGenre;
        headSubGenre = newSubGenre;
        return;
    }
    SubGenre *actual=headSubGenre;
    while (actual->next != nullptr && actual->next->Id < newSubGenre->Id){
        actual = actual->next;
    }
    
    newSubGenre->next = actual->next;
    actual->next = newSubGenre;
}

void showSubGenres(SubGenre* headSubGenre){
    SubGenre *actual=headSubGenre;
    while (actual != nullptr){
        cout << actual->Id << " | "<<actual->Title << endl;
        actual = actual->next;
    }
    
}

string getSubGenre(SubGenre* headSubGenre, int targetSubGenre){
    SubGenre *actual=headSubGenre;
    while (actual->next != nullptr){

        if(actual->Id == targetSubGenre){
            return actual->Title;
        }

        actual = actual->next;
    }

    return "Error. . . ";
}
