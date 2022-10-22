#include <chrono>
#include <fstream>
#include <iostream>

#include "ProbingHashTable.h"

// This should not be called. No logging here.
ProbingHashTable::ProbingHashTable()
{
    this->size = 383;    // Prime number close to middle of 2^9 and 2^8
    this->hashTable.resize(383);
    //cout << this->hashTable.at(382).getIdStr() << endl;
    this->currSize = 0;
    this->twoThirdsCap = 255;   // About (2/3) * 383
}

// This one logs! Call this!
ProbingHashTable::ProbingHashTable(string probingFile)
{
    // Log info
    float timeInMilliseconds;
    ofstream outFS;

    // Start timer...
    auto start = chrono::high_resolution_clock::now();

    this->size = 383;    // Prime number close to middle of 2^9 and 2^8
    this->hashTable.resize(383);
    this->currSize = 0;
    this->twoThirdsCap = 255;   // About (2/3) * 383

    // ... Stop timer.
    auto stop = chrono::high_resolution_clock::now();

    // Time between the timer's stop and start in microseconds.
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    // Time between the timer's stop and start in milliseconds.
    timeInMilliseconds = duration.count() / 1000.0;

    // Write results to file...
    outFS.open(probingFile, ios::app);
    if (!outFS.is_open()) {
        cout << "Unable to open " << probingFile << endl;
        return;
    }
    outFS << "It took " << timeInMilliseconds << " milliseconds to initialize the Probing Hash Table." << endl;
    outFS.close();
}

void ProbingHashTable::insert(Input insertInput, string probingFile)
{
    int id = insertInput.getId();
    Employee newEmployee(id, insertInput.getUsername(), insertInput.getPassword());
    int hashSlot = id % this->size;
    //int firstSlot = hashSlot;
    //cout << "hashSlot == " << hashSlot << endl;
    while(true)
    {
        if (this->hashTable.at(hashSlot).getId() == -1 ||
            this->hashTable.at(hashSlot).getId() == -2)
        {
            this->hashTable.at(hashSlot) = newEmployee;
            this->currSize++;
            if (this->currSize == this-> twoThirdsCap)
            {
                // Double vector.
                dbl(probingFile);
            }
            //cout << newEmployee.getIdStr() << " inserted at " << hashSlot << endl;
            return;
        }
        /*else
            cout << "Passing " << newEmployee.getIdStr() << "to the next hash slot." << endl;*/
        hashSlot++;
        if (hashSlot >= this->size)  // Loop back to 0 if end of vector is reached
            hashSlot = 0;
        /*
        if (hashSlot == firstSlot)  // Infinite loop prevention, shouldn't actually happen in practice
            break;
        */
    }

    return;
}

// Insert using Employee. Used by dbl()
void ProbingHashTable::insert(Employee newEmployee)
{
    int id = newEmployee.getId();
    int hashSlot = id % this->size;
    //int firstSlot = hashSlot;
    //cout << "hashSlot == " << hashSlot << endl;
    while(true)
    {
        if (this->hashTable.at(hashSlot).getId() == -1 ||
            this->hashTable.at(hashSlot).getId() == -2)
        {
            this->hashTable.at(hashSlot) = newEmployee;
            this->currSize++;
            /*
            if (this->currSize == this-> twoThirdsCap)
            {
                // Double vector. SHOULD NOT BE CALLED AGAIN
                dbl();
            }
            */
            //cout << newEmployee.getIdStr() << " inserted at " << hashSlot << endl;
            return;
        }
        /*else
            cout << "Passing " << newEmployee.getIdStr() << "to the next hash slot." << endl;*/
        hashSlot++;
        if (hashSlot >= this->size)  // Loop back to 0 if end of vector is reached
            hashSlot = 0;
        /*
        if (hashSlot == firstSlot)  // Infinite loop prevention, shouldn't actually happen in practice
            break;
        */
    }

    return;
}

// Returns index of the employee with id if found. Returns -1 if not found.
int ProbingHashTable::search(int id)
{
    int hashSlot = id % this->size;
    //int firstSlot = hashSlot;
    while(true)
    {
        if (this->hashTable.at(hashSlot).getId() == -1) // If we reach NULL, we couldn't find it. :(
        {
            //cout << "Not found!!" << endl;
            return -1;
        }
        else if (this->hashTable.at(hashSlot).getId() == id)
        {
            //cout << "Found at index " << hashSlot << endl;
            return hashSlot;
        }
        hashSlot++;
        if (hashSlot >= this->size)  // Loop back to 0 if end of vector is reached
            hashSlot = 0;
        /*
        if (hashSlot == firstSlot)  // Infinite loop prevention, shouldn't actually happen in practice
            break;
        */
    }

    return -1;
}

// Returns true if deleted correctly, returns false if not found by search
bool ProbingHashTable::dlt(int id)
{
    int index = this->search(id);
    if (index == -1)
        return false;
    //cout << "Deleting " << this->hashTable.at(index).getId() << endl;
    this->hashTable.at(index).setId(-2);    // -2 == DELETED
    this->currSize--;

    return true;
}

void ProbingHashTable::dbl(string probingFile)
{
    // Log info
    float timeInMilliseconds;
    ofstream outFS;

    // Start timer...
    auto start = chrono::high_resolution_clock::now();

    //cout << "DOUBLING VECTOR" << endl;
    vector<Employee> presentEmployees;
    for (int i = 0; i < size; i++)
    {
        if (this->hashTable.at(i).getId() != -1 &&
            this->hashTable.at(i).getId() != -2)
        {
            presentEmployees.push_back(this->hashTable.at(i));
            Employee newEmployee;
            this->hashTable.at(i) = newEmployee;
        }
    }
    this->size *= 2;
    this->hashTable.resize(this->size);
    this->currSize = 0;
    this->twoThirdsCap *= 2;

    for (int i = 0; i < presentEmployees.size(); i++)
        this->insert(presentEmployees.at(i));

    // ... Stop timer.
    auto stop = chrono::high_resolution_clock::now();

    // Time between the timer's stop and start in microseconds.
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    // Time between the timer's stop and start in milliseconds.
    timeInMilliseconds = duration.count() / 1000.0;

    // Write results to file...
    outFS.open(probingFile, ios::app);
    if (!outFS.is_open()) {
        cout << "Unable to open " << probingFile << endl;
        return;
    }
    outFS << "It took " << timeInMilliseconds << " milliseconds to double the Probing Hash Table." << endl;
    outFS.close();

    return;
}