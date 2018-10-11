Objective: To implement Hash ADT with closed Hashing.

Further consider the field,Name N as a key. Assume that all keys at least 5 characters long and may discard keys/records
which are shorter than 5 characters. Implemented Hash table ADT with the necessary member
functions,

• to initialize the hash table (HT) with a specific size and specific collision resolving technique
• to insert a record with the given key
• to delete a record with the given key
• to find a record with the given key
• to rehash the hash table when load factor ? > 0.75
• to print the statistics of number of probes for unsuccessful U and successful S find operations
carried out so far and current load factor ?
format of execution:
./nameht option [SIZE] [KEY] [CR]
option:
1. to initialize hash table for specific SIZE and CR
2. to find a given KEY
3. to insert a given KEY
4. to delete a given KEY
5. to compute load factor
6. to rehash hash table to a given size SIZE
7. to display statistics
Arguments mentioned in [ ] brackets are optional.
Example:
./nameht 1 500 LP - to create a hash table with size 500 slots and linear probing resolving
technique
./nameht 2 “vijay kumar” - find the name “vijay kumar” in the hash table. If exists, print its
frequency
./nameht 4 arun - delete the record with Key “arun”