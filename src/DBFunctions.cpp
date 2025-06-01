#include "../headers/DBFunctions.hpp" 
#include <string>
#include <pqxx/pqxx>
#include <iostream>

using namespace std;

void executeQuery(DBConn& db, const function<void(pqxx::work&)>& fnQuery){

    pqxx::connection* conn = db.getConnection();

    if(!conn || !conn->is_open()){
        cout << "No valid connection to DB" << endl;
        return;
    }
    try{
    pqxx::work txn(*conn);
    fnQuery(txn);
    }catch(const std::exception& e ){
        cout << "Query error: " << e.what() << endl;
    }
}

Book* loadBooks(DBConn& db){

    Book* head = nullptr;

    executeQuery(db, [&head](pqxx::work& txn){
        pqxx::result r = txn.exec(
            "SELECT \"Id\", \"Title\", \"Main_Genre\", \"Sub_Genre\", \"Rating\" "
            "FROM \"public\".\"Books\" "
        );
                
        for(const auto& row : r){
            Book* new_Book = new Book();
            new_Book->Id = row["\"Id\""].as<int>();
            new_Book->Title = row["\"Title\""].c_str();
            new_Book->Main_Genre = row["\"Main_Genre\""].c_str();
            new_Book->Sub_Genre = row["\"Sub_Genre\""].c_str();
            new_Book->Rating = row["\"Rating\""].as<float>();
            new_Book->matchScore = 0.0f;
            new_Book->next = nullptr;

            insertBook(head, new_Book);

        }
    });

    return head;
}

/*
void get10FantasyBooks(DBConn& db){
    executeQuery(db, [](pqxx::work& txn){
        pqxx::result r = txn.exec("SELECT \"Id\", \"Title\", \"Sub_Genre\" FROM \"public\".\"Books\" WHERE \"Sub_Genre\" = 'Fantasy' LIMIT 50");

        for(const auto& row : r){
            for(const auto& field : row){
                cout << field.c_str() << " | ";
            }
            cout << endl;
        }
    });
}
}

void get10Books(DBConn& db){
    pqxx::connection* conn = db.getConnection();

    if(!conn || !conn->is_open()){
        cout << "No valid connection to DB" << endl;
        return;
    }

    try{
    pqxx::work txn(*conn);
    pqxx::result r = txn.exec("SELECT * FROM \"public\".\"Books\" LIMIT 10");

    for(const auto& row : r){
        for (const auto& field : row){
            cout << field.c_str() << "|";
        }
        cout << endl;
    }

    txn.commit();
    }catch(const std::exception& e ){
        cout << "Query error: " << e.what() << endl;
    }*/