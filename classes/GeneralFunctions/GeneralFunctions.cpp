#include "../../headers/GeneralFunctions.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string getConnString(){
    string connstring;

    fstream envFile("env.txt");
    
    if(envFile.is_open()){
        getline(envFile, connstring);
        envFile.close();
        return connstring;
    }else{
        cout << "FIle could not be opened" << endl;
    }
}