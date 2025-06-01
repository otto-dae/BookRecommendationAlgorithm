#ifndef SUBGENRELIST_HPP
#define SUBGENRELIST_HPP
#include <string>

struct SubGenre{
    int Id;
    std::string Title;
    SubGenre* next;
};

void insertSubGenre(SubGenre*& headGenre, SubGenre* newSubGenre);
void showSubGenres(SubGenre* headGenre);
std::string getSubGenre(SubGenre* headGenre, int targetSubGenre);
#endif