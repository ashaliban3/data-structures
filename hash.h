// HashTable.h
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class HashTable {
private:
    int tableSize;
    vector<list<int>> table;

    int hashFunction(int key);

public:
    HashTable(int size);
    void insert(int key);
    bool search(int key);
    bool remove(int key);
    void display();
};

#endif