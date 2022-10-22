
#pragma once
#include "Input.h"
#include "EmployeeWithPointers.h"
#include "Employee.h"
#include <iostream>
#include "stdlib.h"

using namespace std;

struct BST{
  Input data;
  BST* left;
  BST* right;

};

class chainBST{
  private:
  Input data;
  BST* hashTable[383];
  // bool hashCheck;
  // int counter;

  public:
  chainBST();
  // chainBST(const chainBST & cpy);
  ~chainBST();
  int hashFunctionIni(Input data);
  BST* searchTable(Input node);
  void insertNode(Input data);
  void deleteNode(Input data);

};