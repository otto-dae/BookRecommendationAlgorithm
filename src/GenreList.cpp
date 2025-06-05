#include "../headers/GenreList.hpp"
#include "../headers/GeneralFunctions.hpp"
#include <iostream>
#include <string>
#include <algorithm> //to make strings to lower

using namespace std;



void insertGenre(Genre*& headGenre, Genre* newGenre){

    if(headGenre == nullptr || newGenre->Id < headGenre->Id){
        newGenre->next = headGenre;
        headGenre = newGenre;
        incrementCount(3);
        return;
    }
    Genre *actual=headGenre;
    while (actual->next != nullptr && actual->next->Id < newGenre->Id){
        actual = actual->next;
        incrementCount(1);
    }
    
    newGenre->next = actual->next;
    actual->next = newGenre;
    incrementCount(2);
}

void showGenres(Genre* headGenre){
    Genre *actual=headGenre;
    while (actual != nullptr){
        cout << actual->Id << " | "<<actual->Title << endl;
        actual = actual->next;
        incrementCount(2);

    }
    incrementCount(1);

}

string getGenre(Genre* headGenre, int& targetGenre){
    Genre *actual=headGenre;
    incrementCount(1);
    while (actual->next != nullptr){

        if(actual->Id == targetGenre){
            incrementCount(1);
            return actual->Title;
        }

        actual = actual->next;
        incrementCount(1);
    }

    return "Error. . . ";
}
