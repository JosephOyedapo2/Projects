#pragma once
#include <string>
#include <vector>

#include "Input.h"
#include "Employee.h"

using namespace std;

class ProbingHashTable
{
public:
    ProbingHashTable();
    ProbingHashTable(string probingFile);
    void insert(Input insertInput, string probingFile);
    void insert(Employee newEmployee);
    int search(int id);
    bool dlt(int id);   // "delete" is a keyword.
    void dbl(string probingFile);         // "double" is also a keyword.

private:
    vector<Employee> hashTable;
    int size;    // Also == capacity
    int currSize;
    int twoThirdsCap;
};