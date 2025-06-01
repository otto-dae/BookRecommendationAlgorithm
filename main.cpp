#include <iostream>
#include <fstream>
#include <pqxx/pqxx>
#include <string>
#include "headers/GeneralFunctions.hpp"
#include "headers/DBConn.hpp"
#include "headers/DBFunctions.hpp"
#include "headers/BookList.hpp"

//BEHOLD THE #INCLUDE HELL (it just keeps getting bigger)

//I swear to god I'm gonna do unspeakble things to whoever did pointers
void Menu();
using namespace std;
DBConn db;

int main(){

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


void Menu(){
    cout << "Basic Recommendation Alogorithm for Books using Amazon DB" << endl;
    cout << "1.- Search by name" << endl;
    cout << "Insert desired search" << endl;

    int option;
    cin >> option;
    cin.ignore();

    switch (option)
    {
    case 1: {
        Book* head = loadBooks(db);
        cout << "type a title or word to search: " << endl;
        string titleSearch;
        getline(cin, titleSearch);
        searchByTitle(head, titleSearch);
    break;
    }

    
    default:
        break;
    }
}