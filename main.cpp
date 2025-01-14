// main.cpp
#include "hash.h"

int main() {
    int size;
    cout << "Enter the size of the hash table: ";
    cin >> size;
    HashTable hashTable(size);

    int choice, key;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            hashTable.insert(key);
            break;
        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            hashTable.search(key);
            break;
        case 3:
            cout << "Enter key to delete: ";
            cin >> key;
            hashTable.remove(key);
            break;
        case 4:
            hashTable.display();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}