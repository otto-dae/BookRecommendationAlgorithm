#include "../headers/BookList.hpp"
#include <iostream>
#include <string>
#include <algorithm> //to make strings to lower

using namespace std;


void insertBook(Book*& head, Book* newBook){

    if(head == nullptr || newBook->Id < head->Id){
        newBook->next = head;
        head = newBook;
        return;
    }
    Book *actual=head;
    while (actual->next != nullptr && actual->next->Id < newBook->Id){
        actual = actual->next;
    }
    
    newBook->next = actual->next;
    actual->next = newBook;
}

void split(Book* source, Book** frontRef, Book** backRef){
    if (!source || !source->next) {
        *frontRef = source;
        *backRef = nullptr;
        return;
    }

    Book* slow = source;
    Book* fast = source->next;

    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = nullptr;
}


Book* mergeSort(Book* head){
    if(!head || !head->next){
        return head;
    }

    Book* leftHalf;
    Book* rightHalf;

    split(head, &leftHalf, &rightHalf);

    leftHalf = mergeSort(leftHalf);
    rightHalf = mergeSort(rightHalf);

    return merge(leftHalf, rightHalf);
}
Book* merge(Book* left, Book* right){
    if (!left) return right;
    if (!right) return left;

    Book* result = nullptr;

    if (left->matchScore >= right->matchScore){
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}


void showBooks(Book* head){
    Book *actual=head;
    while (actual != nullptr){
        cout << actual->Id << " | "<<actual->Title << endl;
        actual = actual->next;
    }
    
}

void showMatches(Book* head, float minScoreMatch){

    if (!head) {
        cout << "No books found." << endl;
        return;
    }
    
    head = mergeSort(head);
    Book* actual=head;
    while (actual != nullptr){

        if(actual->matchScore >= minScoreMatch)
        cout << "Book Title: " << actual->Title << " | " << "Book Main genre: " << actual->Main_Genre  << "Book Sub Genres: " << actual->Sub_Genre << " | " << "Book Rating: " << actual->Rating << endl; 
        actual = actual->next;
    }
}

//Uses linear search algorith as its... O(n) simple, fast no need for anything else
void searchByTitle(Book* head, std::string& keyword){
    Book* current = head;


    while (current->next != nullptr){

        string currentTitle = current->Title;
        transform(currentTitle.begin(), currentTitle.end(), currentTitle.begin(), ::tolower);
        transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);       
        
        //std::string::npos represents not found whilst searching a string  
        if(currentTitle.find(keyword) != string::npos){
            current->matchScore += 2.0f;
            current->matchScore += current->Rating;
        }

        current = current->next;
    }

    showMatches(head, 1.0);
    
}

void searchByGenre(Book* head, std::string& keyword){
    Book* current = head;


    while (current->next != nullptr){

        string currentGenre = current->Main_Genre;
        transform(currentGenre.begin(), currentGenre.end(), currentGenre.begin(), ::tolower);
        transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);       
        
        //std::string::npos represents not found whilst searching a string  
        if(currentGenre.find(keyword) != string::npos){
            current->matchScore += 2.0f;
            current->matchScore += current->Rating;
        }

        current = current->next;
    }

    showMatches(head, 5.5);
    
}

void searchBySubGenre(Book* head, std::string& keywordGenre, std::string& keywordSubgenre){
    Book* current = head;


    while (current->next != nullptr){

        bool genreTrue, subTrue;
        string currentGenre = current->Main_Genre;
        string currentSubGenre = current->Sub_Genre;
        transform(currentGenre.begin(), currentGenre.end(), currentGenre.begin(), ::tolower);
        transform(keywordGenre.begin(), keywordGenre.end(), keywordGenre.begin(), ::tolower);
        transform(keywordSubgenre.begin(), keywordSubgenre.end(), keywordSubgenre.begin(), ::tolower);              
        

        if(currentGenre.find(keywordGenre) != string::npos){
            current->matchScore += 1.0f;
            current->matchScore += current->Rating;
            if(currentSubGenre.find(keywordSubgenre) != string::npos){
                current->matchScore += 2.0f;
            }
        }

        current = current->next;
    }

    showMatches(head, 5.5);
    
}