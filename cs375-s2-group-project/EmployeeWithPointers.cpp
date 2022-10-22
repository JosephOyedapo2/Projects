#include "EmployeeWithPointers.h"

EmployeeWithPointers::EmployeeWithPointers()
{
    // Impossible id meant to cause an error or stand for NULL in hash table. Only called directly in ProbingHashTable's dbl().
    this->id = -1;
    this->username = ":(";
    this->password = ":(";
    this->idStr = "-0001";
}

EmployeeWithPointers::EmployeeWithPointers(int id, string username, string password)
{
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

void EmployeeWithPointers::setId(int id)
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