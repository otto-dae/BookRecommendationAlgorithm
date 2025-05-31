#include <iostream>
#include <fstream>
#include <pqxx/pqxx>
#include <string>


using namespace std;

int main(){

    string name = "Otto";

    sayHello(name);
    return 0;
}