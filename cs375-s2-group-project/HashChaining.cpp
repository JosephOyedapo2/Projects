#include"HashChaining.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor and Destructor
///////////////////////////////////////////////////////////////////////////////////////////////////

HashChaining::HashChaining(void)
{ 
    // Initialize list
    for(int x = 0; x < 383; x++)
    {
        // Initialize each
        hashTable[x] = NULL;
    }
}

HashChaining::HashChaining(const HashChaining & source)
{
    // Check for not a copy
    if(this != &source)
    {
        // Copy counter
        counter = source.counter;

        // Loop to copy chained list
        for(int x = 0; x < 383; x++)
        {
            // Copy lists
            hashTable[x] = source.hashTable[x];
        }
    }
}

HashChaining::~HashChaining(void)
{
    // Loop to delete chained list
    for(int x = 0; x < 383; x++)
    {
        if(hashTable[x] != NULL)
        {
            if(hashTable[x]->getRight() != NULL)
            {
                EmployeeWithPointers * temp = NULL;

                while(hashTable[x]->getRight()!= NULL)
                {
                    temp = hashTable[x]->getRight();
                    hashTable[x]->setRight(hashTable[x]->getRight()->getRight());
                    delete temp;
                }

                delete hashTable[x];
            }
            else
            {
                delete hashTable[x];
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Method
///////////////////////////////////////////////////////////////////////////////////////////////////
void HashChaining::Insert(Input data)
{
    // Hash function call for item position
    int position = Hash(data);

    // Check for valid id
    if(position != -1)
    {
        // New node
        EmployeeWithPointers * newNode = new EmployeeWithPointers;

        // Extract information
        newNode->setId(data.getId());
        newNode->setUsername(data.getUsername());
        newNode->setUsername(data.getPassword());

        // Check if current position is used
        if(hashTable[position] != NULL)
        {
            // Get temporary node
            EmployeeWithPointers * current = hashTable[position];
            
            // Check for end of list
            while(current->getRight() != NULL)
            {
                // Traverse down the chained list
                current = current->getRight();
            }

            // Insert new node
            current->setRight(newNode);

            // Output for testing
            //cout << "Id: " << data.getId() << " is INSERTED." << endl;
        }
        else
        {
            // Set new node
            hashTable[position] = newNode;
            
            // Output for testing
            //cout << "Id: " << data.getId() << " is INSERTED." << endl;
        }
    }
}

void HashChaining::Search(Input data)
{
    // Hash function call for item position
    int position = Hash(data);

    // Check for valid id
    if(position != -1)
    {
        // Check if current position is used
        if(hashTable[position] != NULL)
        {
            // Get temporary node
            EmployeeWithPointers * current = hashTable[position];

            // Check for end of list
            while((current->getRight() != NULL) && (current->getId() != data.getId()))
            {
                // Traverse down the chained list
                current = current->getRight();
            }

            // Check for if id are equal
            if(current->getId() == data.getId())
            {
                // Output for testing
                //cout << "Id: " << data.getId() << " is FOUND." << endl;
            }
        }
    }
}

void HashChaining::Delete(Input data)
{
    // Hash function call for item position
    int position = Hash(data);

    // Check for valid
    if(hashTable[position] != NULL)
    {
        if(hashTable[position]->getId() != data.getId())
        {
            /// Get temporary node
            EmployeeWithPointers * current = hashTable[position];

            // Check for end of list
            while((current->getRight() != NULL) && (current->getRight()->getId() != data.getId()))
            {
                // Traverse down the chained list
                current = current->getRight();
            }

            // Check for if id are equal
            if(current->getRight()->getId() == data.getId() && current->getRight()->getRight() != NULL)
            {
                // Temporary storage
                EmployeeWithPointers * temp = current->getRight();

                // Set link node
                current->setRight(current->getRight()->getRight());

                // Delete node
                delete(temp);

              
                // Output for testing
                //cout << "Id: " << data.getId() << " is DELETED." << endl;
            }
            else if(current->getRight()->getId() == data.getId())
            {
                // Delete node
                delete(current->getRight());
                
                // Set link node
                current->setRight(NULL);

                // Output for testing
                //cout << "Id: " << data.getId() << " is DELETED." << endl;
            }
        }
        else
        {
            if(hashTable[position]->getRight() != NULL)
            {
                EmployeeWithPointers * temp = hashTable[position]->getRight();   
                hashTable[position] = NULL;
                hashTable[position] = temp;
            }
            else
            {
                // Set Node to NULL
                hashTable[position] = NULL;
            }

            // Output for testing
            //cout << "Id: " << data.getId() << " is DELETED." << endl;
        }
    }
}

int HashChaining::Hash(Input data)
{
    // Check for valid id
    if(data.getId() != -1)
    {
        // return with position key
        return data.getId() % 383;
    }
    else
    {
        // Invalid id
        return -1;
    }
}
