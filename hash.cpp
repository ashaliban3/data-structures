// HashTable.cpp
#include "hash.h"

HashTable::HashTable(int size) : tableSize(size), table(size) {}

int HashTable::hashFunction(int key) {
    return key % tableSize;
}

void HashTable::insert(int key) {
    int index = hashFunction(key);
    table[index].push_back(key);
    cout << "Inserted " << key << " at bucket " << index << endl;
}

bool HashTable::search(int key) {
    int index = hashFunction(key);
    for ( int element : table[index]) {
        if (element == key) {
            cout << "Element " << key << " found at bucket " << index << endl;
            return true;
        }
    }
    cout << "Element " << key << " not found" << endl;
    return false;
}

bool HashTable::remove(int key) {
    int index = hashFunction(key);
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (*it == key) {
            table[index].erase(it);
            cout << "Element " << key << " removed from bucket " << index << endl;
            return true;
        }
    }
    cout << "Element " << key << " not found for removal" << endl;
    return false;
}

void HashTable::display() {
    for (int i = 0; i < tableSize; ++i) {
        cout << "Bucket " << i << ": ";
        for ( int element : table[i]) {
            cout << element << " -> ";
        }
        cout << "NULL" << endl;
    }
}