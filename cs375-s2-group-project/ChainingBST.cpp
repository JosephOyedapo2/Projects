#include "ChainingBST.h"

//Constructor
chainBST::chainBST(){

      for(int i = 0;i < 383;i++){
        hashTable[i]= nullptr;

  }
}
//  chainBST::chainBST(const chainBST & cpy){
//      if(this != &cpy){
//        for(int i = 0;i < 383;i++){
//         hashTable[i]= cpy.hashTable[i];

//          }
//      }
//  }

//Destructor
chainBST::~chainBST(){
   for(int i=0; i<383; i++){
        if(hashTable[i] != NULL){
         while(hashTable[i] != NULL){
               deleteNode(hashTable[i]->data);
            }
          }
       }      
}

//Intialize hash func
int chainBST::hashFunctionIni(Input data){
    if(data.getId() != -1){
  return data.getId() % 383;
    }
    else{
        return -1;
    }
}

void inOrderTraversal(BST* curr){
  if(curr == NULL){
    return;
  }
    inOrderTraversal(curr->left);
    inOrderTraversal(curr->right);
}
BST* createBSTNode(Input data){
  BST* newNode = new BST;
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

//Search implementation, search for g iven key in hashtable 
//and returns node if key is found else null\

BST* chainBST::searchTable(Input data){
  int index = hashFunctionIni(data);
  if(index != -1){
   if(hashTable[index] != NULL && index >= 0 && index <= 382){
        BST* curr = hashTable[index];
        while(curr != NULL){
            if(curr->data.getId() == data.getId()){
                return curr;
            }else{
                if(data.getId() < curr->data.getId()){
                    curr = curr->left;
                }else{
                    curr = curr->right;
                }
                //check if both left and right

            }
        }
            //cout << "ID: " << data.getId() << " is FOUND" << endl;

    }
  }
    return NULL;
  
}

//Insert Implementation
BST* Insert(BST* curr, Input data){
   if(curr == NULL){
        return createBSTNode(data);
    }
    if(data.getId() < curr->data.getId()&& curr->left == NULL){
        BST* leftChild = Insert(curr->left, data);
        curr->left = leftChild;
    }else if(data.getId() > curr->data.getId() && curr->right == NULL){
        BST* rightChild = Insert(curr->right, data);
        curr->right = rightChild;
    }
    return curr;
}
void chainBST::insertNode(Input data){
 int index= hashFunctionIni(data);
  BST* newNode = createBSTNode(data);
  if(hashTable[index] == NULL){
    hashTable[index]= newNode;
  }
  else{
    hashTable[index] = Insert(hashTable[index], data);
    //cout << "ID: " << data.getId() << " is INSERTED" << endl;
  }
}

//Delete Implementation
BST* minNode(BST* curr){
     while(curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

BST* delNode(BST* curr, Input data){
  if(curr->data.getId() == data.getId()){

        if(curr->left == NULL && curr->right == NULL){
            delete curr;
            curr = NULL;
            return NULL;
        }
        if(curr->right == NULL){
            BST* temp = curr->left;
            delete curr;
            curr = NULL;
            return temp;
        }

        if(curr->left == NULL){
            BST* temp = curr->right;
            delete curr;
            curr = NULL;
            return temp;
        }
         BST* temp = minNode(curr->right);
        curr->data = temp->data;
        curr->right = delNode(curr->right, temp->data);
        return curr;
       
    }
    if(data.getId() < curr->data.getId()){
        curr->left = delNode(curr->left, data);
    }
    if(data.getId() > curr->data.getId()){
        curr->right = delNode(curr->right, data);
    }
    return curr;

}

void chainBST::deleteNode(Input data){
 int index = hashFunctionIni(data);
  
BST* foundNode = searchTable(data);
    if(foundNode == NULL){
        return;
    }
    if(hashTable[index] != NULL){
    if(hashTable[index]->left == NULL && hashTable[index]->right == NULL){
       delete hashTable[index];
       //work on delete
        hashTable[index] = NULL;
    }else{
        hashTable[index] = delNode(hashTable[index], data);
            //cout << "ID: " << data.getId() << " is DELETED" << endl;

    }
    }
  
}