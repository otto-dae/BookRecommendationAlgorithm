#include "../../headers/DBFunctions.hpp" 
#include <string>
#include <pqxx/pqxx>
#include <iostream>

using namespace std;

void executeQuery(DBConn& db, )

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
}*/