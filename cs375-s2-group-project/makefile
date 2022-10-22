# Specifiy the target
all:	main

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
main:	main.o Input.o Employee.o ProbingHashTable.o HashChaining.o EmployeeWithPointers.o ChainingBST.o
	g++ main.o Input.o Employee.o ProbingHashTable.o HashChaining.o EmployeeWithPointers.o ChainingBST.o -o program4

# Specify how the object files should be created from source files
main.o: main.cpp
				g++ -c main.cpp

Input.o: Input.cpp Input.h
				g++ -c Input.cpp

Employee.o: Employee.cpp Employee.h
				g++ -c Employee.cpp

ProbingHashTable.o:	ProbingHashTable.cpp ProbingHashTable.h
				g++ -c ProbingHashTable.cpp

HashChaining.o:	HashChaining.cpp HashChaining.h
				g++ -c HashChaining.cpp

EmployeeWithPointers.o:	EmployeeWithPointers.cpp EmployeeWithPointers.h
				g++ -c EmployeeWithPointers.cpp
        
ChainingBST.o: ChainingBST.cpp ChainingBST.h
				g++ -c ChainingBST.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o *.log.txt *.chaining.txt *.probing.txt *.bst.txt program4.exe program4