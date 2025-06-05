#include <iostream>
#include <fstream>
#include <pqxx/pqxx>
#include <string>
#include "headers/GeneralFunctions.hpp"
#include "headers/DBConn.hpp"
#include "headers/DBFunctions.hpp"
#include "headers/BookList.hpp"


//We declare the menu function, the BDCOnn object for connections
// and we declare all the headers needed 
void Menu();
using namespace std;
DBConn db;
Book* headBook = nullptr;
Genre* headGenre = nullptr;
SubGenre* headSubGenre = nullptr;

//main :D
int main(){

    //we verify that the connection to the DataBase is corret
    //If it is true, we display the menu if something happened, we show the error
    string connString = GENERALFUNCTIONS_HPP::getConnString();

    if (db.connect(connString)) {
        pqxx::connection* conn = db.getConnection();

        try{

            Menu();

        }catch(const std::exception& e ){
            cout << "Query error: " << e.what() << endl;
        }
    }else{
        cout << "Error connecting. . ." << endl;
    }
    return 0;
}

//Menu
void Menu(){
    int option;
    while(option != 4){
        cout << "Basic Recommendation Alogorithm for Books using Amazon DB" << endl;
        cout << "1.- Search by Name" << endl;
        cout << "2.- Search by Genre" << endl;
        cout << "3.- Search by Genre and Sub Genre" << endl;
        cout << "4.- Exit console" << endl;
        cout << "Insert desired search" << endl;
    
        cin >> option;
        cin.ignore();
    
        switch (option)
        {
        case 1: {
            system("clear");

            //Search book by title, we get the name/title and search it
            headBook = loadBooks(db);
            cout << "type a title or word to search: " << endl;
            string titleSearch;
            getline(cin, titleSearch);
            searchByTitle(headBook, titleSearch);
        break;
        }    
        case 2: {
            //Search book by genre, we get the genre and search it
            system("clear");

            headGenre = loadGenres(db);
            headBook = loadBooks(db);
            int genreSelector;
            cout << "Select only 1 genre from the list: " << endl;
            cin.clear();
            cin >> genreSelector;
            string genreQuery = getGenre(headGenre, genreSelector);
            searchByGenre(headBook, genreQuery);
    
        break;
        }
    
        case 3: {
            system("clear");
            headGenre = loadGenres(db);
            headBook = loadBooks(db);
            int genreSelector;
            cout << "Select only 1 genre from the list: " << endl;
            cin.clear();
            cin >> genreSelector;
            string genreQuery = getGenre(headGenre, genreSelector);
            headSubGenre = loadSubGenres(db, genreQuery);
    
            int subgenreSelector;
            cout << "Select only 1 Sub genre from the list: " << endl;
            cin.clear();
            cin >> subgenreSelector;
            string subGenreQuery = getSubGenre(headSubGenre, subgenreSelector);
            searchBySubGenre(headBook, genreQuery,subGenreQuery);
        break;
        }
        case 4:
            return;
            break;
 
        default:
            cout << "Select a valid option" << endl;
            break;
        }
    }

}