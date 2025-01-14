//Quadratic Probing with Modulo Hashing

//Main.cpp code 

#include <iostream>
#include "hashquadratic.h"
using namespace std;

int main() {
    // Create a hash table with an initial size of 10
    HashTable ht(10);
    int choice;

    // Main loop that displays the menu and handles user choices
    while (true) {
        // Display the menu options
         cout << "1. Insert" <<  endl;
         cout << "2. Search" <<  endl;
         cout << "3. Delete" <<  endl;
         cout << "4. Output" <<  endl;
         cout << "5. Exit" <<  endl;
         cout << "Choose an Option: ";
         cin >> choice;

        // Handle the user's choice
        switch (choice) {
        case 1: { // Insert an element into the hash table
            int data;
             cout << "Enter Integer to insert: ";
             cin >> data;
            ht.insert(data);
            break;
        }
        case 2: { // Search for an element in the hash table
            int data;
             cout << "Enter Integer to search: ";
             cin >> data;
            ht.search(data);
            break;
        }
        case 3: { // Delete an element from the hash table
            int data;
             cout << "Enter integer to delete: ";
             cin >> data;
            ht.deleteKey(data);
            break;
        }
        /*case 4: { // Display the contents of the hash table
            ht.display();
            break;
        }*/
        case 5: { // Exit the program
             cout << "Goodbye" <<  endl;
            return 0;
        }
        default: { // Handle invalid user input
             cout << "Invalid choice. Please try  again." <<  endl;
        }
        }
    }
}