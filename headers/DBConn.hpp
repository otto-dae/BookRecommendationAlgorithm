#ifndef DBCONN_HPP
#define DBCONN_HPP

#include <pqxx/pqxx>
#include <string>

class DBConn
{
public:
    DBConn();
    ~DBConn();

    bool connect(const std::string& conn_str);

    pqxx::connection* getConnection();

private:
    pqxx::connection* conn;
};
#endif