#ifndef DBFUNCTIONS_HPP
#define DBFUNCTIONS_HPP

#include "DBConn.hpp"
#include "BookList.hpp"

/*void get10Books(DBConn& db);
void get10FantasyBooks(DBConn& db);*/
Book* loadBooks(DBConn& db);
#endif