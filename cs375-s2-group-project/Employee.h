#pragma once
#include <string>

using namespace std;

class Employee
{
public:
    Employee();
    Employee(int id, string username, string password);
    int getId() {return id; }
    string getUsername() {return username; }
    string getPassword() {return password; }
    string getIdStr() {return idStr; }
    void setId(int id);
    void setUsername(string username) {this->username = username; }
    void setPassword(string password) {this->password = password; }

private:
    int id;
    string username;
    string password;

    string idStr;
};