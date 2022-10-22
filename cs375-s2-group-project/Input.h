#pragma once
#include <string>

using namespace std;

class Input
{
public:
    Input();
    Input(string input, int id);
    Input(string input, int id, string username, string password);
    string getInput() {return input; }
    int getId() {return id; }
    string getUsername() {return username; }
    string getPassword() {return password; }
    string getIdStr() {return idStr; }
    void setInput(string input) {this->input = input; }
    void setId(int id);
    void setUsername(string username) {this->username = username; }
    void setPassword(string password) {this->password = password; }

private:
    string input;
    int id;
    string username;
    string password;

    string idStr;
};