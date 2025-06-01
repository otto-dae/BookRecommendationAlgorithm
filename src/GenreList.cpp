#include "../headers/GenreList.hpp"
#include <iostream>
#include <string>
#include <algorithm> //to make strings to lower

using namespace std;



void insertGenre(Genre*& headGenre, Genre* newGenre){

    if(headGenre == nullptr || newGenre->Id < headGenre->Id){
        newGenre->next = headGenre;
        headGenre = newGenre;
        return;
    }
    Genre *actual=headGenre;
    while (actual->next != nullptr && actual->next->Id < newGenre->Id){
        actual = actual->next;
    }
    
    newGenre->next = actual->next;
    actual->next = newGenre;
}

void showGenres(Genre* headGenre){
    Genre *actual=headGenre;
    while (actual != nullptr){
        cout << actual->Id << " | "<<actual->Title << endl;
        actual = actual->next;
    }
    
}

string getGenre(Genre* headGenre, int& targetGenre){
    Genre *actual=headGenre;
    while (actual->next != nullptr){

        if(actual->Id == targetGenre){
            return actual->Title;
        }

        actual = actual->next;
    }

    return "Error. . . ";
}
