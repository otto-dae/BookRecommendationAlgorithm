#ifndef DBFUNCTIONS_HPP
#define DBFUNCTIONS_HPP

#include "DBConn.hpp"
#include "BookList.hpp"
#include "GenreList.hpp"
#include "SubGenreList.hpp"

/*void get10Books(DBConn& db);
void get10FantasyBooks(DBConn& db);*/
Book* loadBooks(DBConn& db);
Genre* loadGenres(DBConn& db);
SubGenre* loadSubGenres(DBConn& db, std::string Genre);
#endif