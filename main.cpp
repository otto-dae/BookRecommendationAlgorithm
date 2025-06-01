#include <iostream>
#include <fstream>
#include <pqxx/pqxx>
#include <string>
#include "headers/GeneralFunctions.hpp"
#include "headers/DBConn.hpp"
#include "headers/DBFunctions.hpp"

//BEHOLD THE #INCLUDE HELL (it just keeps getting bigger)

//I swear to god I'm gonna do unspeakble things to whoever did pointes

using namespace std;

int main(){

    string connString = GENERALFUNCTIONS_HPP::getConnString();
    DBConn db;

    if (db.connect(connString)) {
        pqxx::connection* conn = db.getConnection();

        try{
            //Just for testing, ignore
            /*pqxx::work txn(*conn);
            pqxx::result r = txn.exec("SELECT Version()");
            cout << "PostgreSQL version: " << r[0][0].c_str() << std::endl;
            txn.commit();*/
            
            //Even more testing stuff
            //get10Books(db);


        }catch(const std::exception& e ){
            cout << "Query error: " << e.what() << endl;
        }
    }else{
        cout << "Error connecting. . ." << endl;
    }
    return 0;
}


