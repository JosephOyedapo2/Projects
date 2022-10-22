#pragma once
#include <iostream>
#include"Input.h"
#include"EmployeeWithPointers.h"

class HashChaining
{
    public:
    // Constructor and Destructor
    HashChaining();
    HashChaining(const HashChaining & source);
    ~HashChaining();
    // Methods
    void Insert(Input data);
    void Search(Input data);
    void Delete(Input data);
    int Hash(Input data);

    private:
    // Counters
    int counter = 0;
    // Hash table
    EmployeeWithPointers * hashTable[383];
};