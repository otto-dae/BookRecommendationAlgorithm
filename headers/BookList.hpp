#ifndef BOOKLIST_HPP
#define BOOKLIST_HPP
#include <string>

struct Book{
    int Id;
    std::string Title;
    std::string Main_Genre;
    std::string Sub_Genre;
    float Rating;
    float matchScore;
    Book* next;
};

void insertBook(Book*& head, Book* newBook);
void showBooks(Book* head);
void searchByTitle(Book* head, std::string& keyword);
void searchByGenre(Book* head, std::string& keyword);
void searchBySubGenre(Book* head, std::string& keywordGenre, std::string& keywordSubgenre);


Book* mergeSort(Book* head);
Book* merge(Book* left, Book* right);
void split(Book* source, Book** frontRef, Book** backRef);
void showMatches(Book* head, float minScoreMatch);


#endif