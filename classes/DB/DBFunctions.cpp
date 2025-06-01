#include "../../headers/DBFunctions.hpp" 
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



//Ignore testing stuff
/*void get10Books(DBConn& db){
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
    }


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
}*/