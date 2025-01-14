// HashTableQp.cpp
#include "hashquadratic.h"

// Constructor that initializes the table size and the data vector
HashTable::HashTable(int size) : table_size(size), data(size, -1) {}

// Hash function to calculate the initial index in the hash table
int HashTable::hash(int key) {
    return key % table_size;
}

// Quadratic probing function to find the next available slot
int HashTable::quadraticProbing(int key, int i) {
    // Constants for quadratic probing
    const int c1 = 1; // Programmer-defined constant
    const int c2 = 3; // Programmer-defined constant

    // Recompute the index using the quadratic probing formula
    return (hash(key) + c1 * i + c2 * i * i) % table_size;
}

// Insert a new key into the hash table
void HashTable::insert(int key) {
    int i = 0;
    int index = hash(key);
    int bucketsProbed = 0;

    // Probe until an empty slot is found or the table is full
    while (data[index] != -1 && data[index] != -2 && bucketsProbed < table_size) {
        // Increment i and recompute the index using quadratic probing
        i++;
        index = quadraticProbing(key, i);
        bucketsProbed++;
    }

    // Insert the key if an empty slot is found
    if (data[index] == -1 || data[index] == -2) {
        data[index] = key;
        std::cout << "Inserted successfully." << std::endl;
    } else {
        // If the table is full, report that the insertion failed
        std::cout << "Insertion failed. Table is full." << std::endl;
    }
}

// Search for a key in the hash table
void HashTable::search(int key) {
    int i = 0;
    int index = hash(key);
    int bucketsProbed = 0;

    // Probe while the slot is not empty since the start and the table is not fully probed
    while (data[index] != -1 && bucketsProbed < table_size) {
        // If the key is found, report it
        if (data[index] == key) {
            std::cout << "Element found at index " << index << "." << std::endl;
            return;
        }

        // Increment i and recompute the index using quadratic probing
        i++;
        index = quadraticProbing(key, i);
        bucketsProbed++;
    }

    // If the key is not found, report it
    std::cout << "Element not found." << std::endl;
}

// Delete a key from the hash table
void HashTable::deleteKey(int key) {
    int i = 0;
    int index = hash(key);
    int bucketsProbed = 0;

    // Probe while the slot is not empty since the start and the table is not fully probed
    while (data[index] != -1 && bucketsProbed < table_size) {
        // If the key is found, delete it
        if (data[index] == key) {
            data[index] = -2; // Mark as "empty after removal"
            std::cout << "Element deleted." << std::endl;
            return;
        }

        // Increment i and recompute the index using quadratic probing
        i++;
        index = quadraticProbing(key, i);
        bucketsProbed++;
    }

    // If the key is not found, report it
    std::cout << "Element not found." << std::endl;
}
