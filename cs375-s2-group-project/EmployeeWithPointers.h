#pragma once
#include <string>

using namespace std;

class EmployeeWithPointers
{
public:
    EmployeeWithPointers();
    EmployeeWithPointers(int id, string username, string password);
    int getId() {return id; }
    EmployeeWithPointers * getLeft() {return left; }
    EmployeeWithPointers * getRight() {return right; }
    string getUsername() {return username; }
    string getPassword() {return password; }
    string getIdStr() {return idStr; }
    void setLeft(EmployeeWithPointers * newLeft) {this->left = newLeft; }
    void setRight(EmployeeWithPointers * newRight) {this->right = newRight; }
    void setId(int id);
    void setUsername(string username) {this->username = username; }
    void setPassword(string password) {this->password = password; }

private:
    EmployeeWithPointers * left = NULL;
    EmployeeWithPointers * right = NULL;

    int id;
    string username;
    string password;

    string idStr;
};
