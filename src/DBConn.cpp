#include "../headers/DBConn.hpp"
#include "../headers/GeneralFunctions.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

DBConn::DBConn(){
    conn = nullptr;
}

DBConn::~DBConn(){
    if (conn != nullptr){
        delete conn;
        conn = nullptr;
        incrementCount(3);
    }
}


bool DBConn::connect(const std::string& conn_str){
    try{
        conn = new pqxx::connection(conn_str);

        if(conn->is_open()){
            cout << "Connection was succesful!" << endl;
            incrementCount(2);
            return true;
        }else{
            cout << "Connection failed!" << endl;
            delete conn;
            conn = nullptr;
            incrementCount(4);
            return false;
        }

    }catch(const std::exception& e ){
        cout << "Connection failed: " << e.what() << endl;
        return false;
    }
}

pqxx::connection* DBConn::getConnection(){
    return conn;
}

