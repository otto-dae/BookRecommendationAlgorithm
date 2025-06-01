#include "../../headers/DBConn.hpp"
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
    }
}


bool DBConn::connect(const std::string& conn_str){
    try{
        conn = new pqxx::connection(conn_str);

        if(conn->is_open()){
            cout << "Connection was succesful!" << endl;
            return true;
        }else{
            cout << "Connection failed!" << endl;
            delete conn;
            conn = nullptr;
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

