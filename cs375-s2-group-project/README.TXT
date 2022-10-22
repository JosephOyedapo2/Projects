# cs375-s2-group-project
TO RUN THIS PROGRAM:
    make
    ./program4 <input-file> <output-file>
Both input-file and output-file should end in .txt.
Running
    make clean
will remove the executable as well as the log files, so be careful.
PROGRAM OUTPUT:
    4 files:
        <output-file>.bst.txt       (runtimes for each insert, search, and delete for hash table using chaining with BST)
        <output-file>.chaining.txt  (runtimes for each insert, search, and delete for hash table using chaining with linked list)
        <output-file>.log.txt       (runtimes for parsing the input file and running the input on each of the hash tables)
        <output-file>.probing.txt   (runtimes for each insert, search, and delete for hash table using linear probing)
