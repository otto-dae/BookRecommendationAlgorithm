#ifndef GENRELIST_HPP
#define GENRELIST_HPP
#include <string>

struct Genre{
    int Id;
    std::string Title;
    Genre* next;
};

void insertGenre(Genre*& headGenre, Genre* newGenre);
void showGenres(Genre* headGenre);
std::string getGenre(Genre* headGenre, int& targetGenre);
#endif