// HashTableQp.h
#ifndef HASHQUADRATIC_H
#define HASHQUADRATIC_H
using namespace std;

#include <vector>
#include <iostream>

// HashTable class definition
class HashTable {
private:
    // Private member variables
    int table_size;                 // Size of the hash table
    vector<int> data;          // Vector to store the hash table elements

    // Private member functions
    // Hash function to calculate the initial index in the hash table
    int hash(int key);

    // Quadratic probing function to find the next available slot
    int quadraticProbing(int key, int i);

public:
    // Constructor that initializes the table size and the data vector
    HashTable(int size);

    // Member functions
    // Insert a new key into the hash table
    void insert(int key);

    // Search for a key in the hash table
    void search(int key);

    // Delete a key from the hash table
    void deleteKey(int key);

    // Display the contents of the hash table
    void display();
};

#endif // HASHTABLEQP_H
