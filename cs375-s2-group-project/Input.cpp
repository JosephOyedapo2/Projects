#include "Input.h"

Input::Input()
{
    // Impossible input and id meant to cause an error. The default constructor should never be called directly.
    this->input = "badinput";
    this->id = -1;
    this->username = ":(";
    this->password = ":(";
    this->idStr = "-0001";
}

Input::Input(string input, int id)
{
    // input is either delete or search. username and password won't matter.
    this->input = input;
    this->id = id;
    this->username = "searchdelete";
    this->password = "searchdelete";

    string prependZeros = "";
    if (id < 10)
        prependZeros = "000";
    else if (id < 100)
        prependZeros = "00";
    else if (id < 1000)
        prependZeros = "0";
    this->idStr = prependZeros + to_string(id);
}

Input::Input(string input, int id, string username, string password)
{
    this->input = input;
    this->id = id;
    this->username = username;
    this->password = password;

    string prependZeros = "";
    if (id < 10)
        prependZeros = "000";
    else if (id < 100)
        prependZeros = "00";
    else if (id < 1000)
        prependZeros = "0";
    this->idStr = prependZeros + to_string(id);
}

void Input::setId(int id)
{
    this->id = id;

    string prependZeros = "";
    if (id < 10)
        prependZeros = "000";
    else if (id < 100)
        prependZeros = "00";
    else if (id < 1000)
        prependZeros = "0";
    this->idStr = prependZeros + to_string(id);
}