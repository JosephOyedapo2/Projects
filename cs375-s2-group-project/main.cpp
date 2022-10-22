#include <chrono>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

#include "Employee.h"
#include "ProbingHashTable.h"
#include "HashChaining.h"
#include "ChainingBST.h"

using namespace std;

/*
Run the inputs with the hash table using chaining w/ BST.
Returns true if error, false otherwise.
*/
bool runBst(vector<Input> inputVec, string bstFile, string logFile)
{
    // Logs info
    float timeInMilliseconds;
    ofstream outFS;
    chainBST tree;
    

    // Start timer...
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < inputVec.size(); i++)
    {
        // Start input timer...
        auto inputStart = chrono::high_resolution_clock::now();

        if (inputVec.at(i).getInput() == "insert")
        {
            //Insert.
            tree.insertNode(inputVec.at(i));

            // ... Stop timer.
            auto inputStop = chrono::high_resolution_clock::now();

            // Time between the input timer's stop and start in microseconds.
            auto duration = chrono::duration_cast<chrono::microseconds>(inputStop - inputStart);

            // Time between the input timer's stop and start in milliseconds.
            timeInMilliseconds = duration.count() / 1000.0;

            // Write results to file...
            outFS.open(bstFile, ios::app);
            if (!outFS.is_open()) {
                cout << "Unable to open " << bstFile << endl;
                return true;
            }
            outFS << "It took " << timeInMilliseconds << " milliseconds to insert " << inputVec.at(i).getIdStr() << "." << endl;
            outFS.close();
        }
        else if (inputVec.at(i).getInput() == "search")
        {
            //Search.
            tree.searchTable(inputVec.at(i));

            // ... Stop timer.
            auto inputStop = chrono::high_resolution_clock::now();

            // Time between the input timer's stop and start in microseconds.
            auto duration = chrono::duration_cast<chrono::microseconds>(inputStop - inputStart);

            // Time between the input timer's stop and start in milliseconds.
            timeInMilliseconds = duration.count() / 1000.0;

            // Write results to file...
            outFS.open(bstFile, ios::app);
            if (!outFS.is_open()) {
                cout << "Unable to open " << bstFile << endl;
                return true;
            }
            outFS << "It took " << timeInMilliseconds << " milliseconds to search for " << inputVec.at(i).getIdStr() << "." << endl;
            outFS.close();
        }
        else if (inputVec.at(i).getInput() == "delete")
        {
            //Delete.
             tree.deleteNode(inputVec.at(i));

            // ... Stop timer.
            auto inputStop = chrono::high_resolution_clock::now();

            // Time between the input timer's stop and start in microseconds.
            auto duration = chrono::duration_cast<chrono::microseconds>(inputStop - inputStart);

            // Time between the input timer's stop and start in milliseconds.
            timeInMilliseconds = duration.count() / 1000.0;

            // Write results to file...
            outFS.open(bstFile, ios::app);
            if (!outFS.is_open()) {
                cout << "Unable to open " << bstFile << endl;
                return true;
            }
            outFS << "It took " << timeInMilliseconds << " milliseconds to delete " << inputVec.at(i).getIdStr() << "." << endl;
            outFS.close();
        }
    }

    // ... Stop timer.
    auto stop = chrono::high_resolution_clock::now();

    // Time between the timer's stop and start in microseconds.
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    // Time between the timer's stop and start in milliseconds.
    timeInMilliseconds = duration.count() / 1000.0;

    // Write results to file...
    outFS.open(logFile, ios::app);
    if (!outFS.is_open()) {
        cout << "Unable to open " << logFile << endl;
        return true;
    }
    outFS << "It took " << timeInMilliseconds << " milliseconds to run the input with the hash table using chaining with a BST." << endl;
    outFS.close();

    return false;
}

/*
Run the inputs with the hash table using chaining w/ linked list.
Returns true if error, false otherwise.
*/
bool runChaining(vector<Input> inputVec, string chainingFile, string logFile)
{
    // Logs info
    float timeInMilliseconds;
    ofstream outFS;

    // New table
    HashChaining newTable;

    // Start timer...
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < inputVec.size(); i++)
    {
        // Start input timer...
        auto inputStart = chrono::high_resolution_clock::now();

        if (inputVec.at(i).getInput() == "insert")
        {
            //Insert
            newTable.Insert(inputVec.at(i));

            // ... Stop timer.
            auto inputStop = chrono::high_resolution_clock::now();

            // Time between the input timer's stop and start in microseconds.
            auto duration = chrono::duration_cast<chrono::microseconds>(inputStop - inputStart);

            // Time between the input timer's stop and start in milliseconds.
            timeInMilliseconds = duration.count() / 1000.0;

            // Write results to file...
            outFS.open(chainingFile, ios::app);
            if (!outFS.is_open()) {
                cout << "Unable to open " << chainingFile << endl;
                return true;
            }
            outFS << "It took " << timeInMilliseconds << " milliseconds to insert " << inputVec.at(i).getIdStr() << "." << endl;
            outFS.close();
        }
        else if (inputVec.at(i).getInput() == "search")
        {
            //Search.
            newTable.Search(inputVec.at(i));

            // ... Stop timer.
            auto inputStop = chrono::high_resolution_clock::now();

            // Time between the input timer's stop and start in microseconds.
            auto duration = chrono::duration_cast<chrono::microseconds>(inputStop - inputStart);

            // Time between the input timer's stop and start in milliseconds.
            timeInMilliseconds = duration.count() / 1000.0;

            // Write results to file...
            outFS.open(chainingFile, ios::app);
            if (!outFS.is_open()) {
                cout << "Unable to open " << chainingFile << endl;
                return true;
            }
            outFS << "It took " << timeInMilliseconds << " milliseconds to search for " << inputVec.at(i).getIdStr() << "." << endl;
            outFS.close();
        }
        else if (inputVec.at(i).getInput() == "delete")
        {
            //Delete.
            newTable.Delete(inputVec.at(i));

            // ... Stop timer.
            auto inputStop = chrono::high_resolution_clock::now();

            // Time between the input timer's stop and start in microseconds.
            auto duration = chrono::duration_cast<chrono::microseconds>(inputStop - inputStart);

            // Time between the input timer's stop and start in milliseconds.
            timeInMilliseconds = duration.count() / 1000.0;

            // Write results to file...
            outFS.open(chainingFile, ios::app);
            if (!outFS.is_open()) {
                cout << "Unable to open " << chainingFile << endl;
                return true;
            }
            outFS << "It took " << timeInMilliseconds << " milliseconds to delete " << inputVec.at(i).getIdStr() << "." << endl;
            outFS.close();
        }
    }

    // ... Stop timer.
    auto stop = chrono::high_resolution_clock::now();

    // Time between the timer's stop and start in microseconds.
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    // Time between the timer's stop and start in milliseconds.
    timeInMilliseconds = duration.count() / 1000.0;

    // Write results to file...
    outFS.open(logFile, ios::app);
    if (!outFS.is_open()) {
        cout << "Unable to open " << logFile << endl;
        return true;
    }
    outFS << "It took " << timeInMilliseconds << " milliseconds to run the input with the hash table using chaining with a linked list." << endl;
    outFS.close();

    return false;
}

/*
Run the inputs with the hash table using probing.
Returns true if error, false otherwise.
*/
bool runProbing(vector<Input> inputVec, string probingFile, string logFile)
{
    // Logs info
    float timeInMilliseconds;
    ofstream outFS;

    // Start timer...
    auto start = chrono::high_resolution_clock::now();

    // Create Probing Hash Table.
    ProbingHashTable pHT(probingFile);

    for (int i = 0; i < inputVec.size(); i++)
    {
        // Start input timer...
        auto inputStart = chrono::high_resolution_clock::now();

        if (inputVec.at(i).getInput() == "insert")
        {
            //Insert.
            pHT.insert(inputVec.at(i), probingFile);

            // ... Stop timer.
            auto inputStop = chrono::high_resolution_clock::now();

            // Time between the input timer's stop and start in microseconds.
            auto duration = chrono::duration_cast<chrono::microseconds>(inputStop - inputStart);

            // Time between the input timer's stop and start in milliseconds.
            timeInMilliseconds = duration.count() / 1000.0;

            // Write results to file...
            outFS.open(probingFile, ios::app);
            if (!outFS.is_open()) {
                cout << "Unable to open " << probingFile << endl;
                return true;
            }
            outFS << "It took " << timeInMilliseconds << " milliseconds to insert " << inputVec.at(i).getIdStr() << "." << endl;
            outFS.close();
        }
        else if (inputVec.at(i).getInput() == "search")
        {
            //Search.
            pHT.search(inputVec.at(i).getId());

            // ... Stop timer.
            auto inputStop = chrono::high_resolution_clock::now();

            // Time between the input timer's stop and start in microseconds.
            auto duration = chrono::duration_cast<chrono::microseconds>(inputStop - inputStart);

            // Time between the input timer's stop and start in milliseconds.
            timeInMilliseconds = duration.count() / 1000.0;

            // Write results to file...
            outFS.open(probingFile, ios::app);
            if (!outFS.is_open()) {
                cout << "Unable to open " << probingFile << endl;
                return true;
            }
            outFS << "It took " << timeInMilliseconds << " milliseconds to search for " << inputVec.at(i).getIdStr() << "." << endl;
            outFS.close();
        }
        else if (inputVec.at(i).getInput() == "delete")
        {
            //Delete.
            pHT.dlt(inputVec.at(i).getId());

            // ... Stop timer.
            auto inputStop = chrono::high_resolution_clock::now();

            // Time between the input timer's stop and start in microseconds.
            auto duration = chrono::duration_cast<chrono::microseconds>(inputStop - inputStart);

            // Time between the input timer's stop and start in milliseconds.
            timeInMilliseconds = duration.count() / 1000.0;

            // Write results to file...
            outFS.open(probingFile, ios::app);
            if (!outFS.is_open()) {
                cout << "Unable to open " << probingFile << endl;
                return true;
            }
            outFS << "It took " << timeInMilliseconds << " milliseconds to delete " << inputVec.at(i).getIdStr() << "." << endl;
            outFS.close();
        }
    }

    // ... Stop timer.
    auto stop = chrono::high_resolution_clock::now();

    // Time between the timer's stop and start in microseconds.
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    // Time between the timer's stop and start in milliseconds.
    timeInMilliseconds = duration.count() / 1000.0;

    // Write results to file...
    outFS.open(logFile, ios::app);
    if (!outFS.is_open()) {
        cout << "Unable to open " << logFile << endl;
        return true;
    }
    outFS << "It took " << timeInMilliseconds << " milliseconds to run the input with the hash table using probing." << endl;
    outFS.close();

    return false;
}

// Parses the input file and stores its data in a vector of Inputs.
vector<Input> parseInput(string inputFile, string logFile)
{
    vector<Input> inputVec;

    ifstream inFS;

    inFS.open(inputFile);
    if (!inFS.is_open())
    {
        cout << "Unable to open " << inputFile << endl;
        return inputVec;
    }

    // Input info
    string input;
    int id;
    string username;
    string password;

    // Log info
    float timeInMilliseconds;

    // Start timer...
    auto start = chrono::high_resolution_clock::now();

    for (string line; getline(inFS, line); )
    {
        istringstream inSS(line);
        
        inSS >> input;
        inSS >> id;
        if (input == "insert")
        {
            inSS >> username;
            inSS >> password;
            Input newInput(input, id, username, password);
            inputVec.push_back(newInput);
        }
        else
        {
            Input newInput(input, id);
            inputVec.push_back(newInput);
        }

    }

    // ... Stop timer.
    auto stop = chrono::high_resolution_clock::now();

    // Time between the timer's stop and start in microseconds.
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    // Time between the timer's stop and start in milliseconds.
    timeInMilliseconds = duration.count() / 1000.0;

    // Write results to file...
    ofstream outFS;
    outFS.open(logFile, ios::app);
    if (!outFS.is_open()) {
        cout << "Unable to open " << logFile << endl;
        return inputVec;
    }
    outFS << "It took " << timeInMilliseconds << " milliseconds to parse input file " << inputFile << "." << endl;
    outFS.close();

    return inputVec;
}

/*
First, checks for input parameter amount and format.
Then calls function to parse the input file and the functions to start the hash tables.
*/
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Parameter amount incorrect. Aborting." << endl;
        return 1;
    }

    string inputFile(argv[1]);
    string outputFile(argv[2]);

    if (inputFile.length() < 5 || outputFile.length() < 5 ||
        inputFile.substr(inputFile.length() - 4, 4) != ".txt" ||
        outputFile.substr(outputFile.length() - 4, 4) != ".txt")
    {
        cout << "Parameter format incorrect. Aborting." << endl;
        return 1;
    }

    string logFile = outputFile.substr(0, outputFile.size() - 4) + ".log.txt";
    string chainingFile = outputFile.substr(0, outputFile.size() - 4) + ".chaining.txt";
    string probingFile = outputFile.substr(0, outputFile.size() - 4) + ".probing.txt";
    string bstFile = outputFile.substr(0, outputFile.size() - 4) + ".bst.txt";

    // Truncate the files once, then use ios::app to append in every other output.
    ofstream outFS;
    outFS.open(logFile, ios::trunc);
    if (!outFS.is_open()) {
        cout << "Unable to open " << logFile << endl;
        return 1;
    }
    outFS.close();
    outFS.open(chainingFile, ios::trunc);
    if (!outFS.is_open()) {
        cout << "Unable to open " << chainingFile << endl;
        return 1;
    }
    outFS.close();
    outFS.open(probingFile, ios::trunc);
    if (!outFS.is_open()) {
        cout << "Unable to open " << probingFile << endl;
        return 1;
    }
    outFS.close();
    outFS.open(bstFile, ios::trunc);
    if (!outFS.is_open()) {
        cout << "Unable to open " << bstFile << endl;
        return 1;
    }
    outFS.close();

    // Inputs are stored in inputVec.
    vector<Input> inputVec = parseInput(inputFile, logFile);
    if (inputVec.empty())
        return 1;

    if(runProbing(inputVec, probingFile, logFile))
        return 1;
    if(runChaining(inputVec, chainingFile, logFile))
        return 1;
    if(runBst(inputVec, bstFile, logFile))
        return 1;
    
    return 0;
}