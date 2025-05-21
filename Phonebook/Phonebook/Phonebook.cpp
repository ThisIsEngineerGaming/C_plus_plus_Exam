
// My very cool and awesome library
#include "header.h"
// I also added system clear to just make the code look
int main() {
    // Some basic variables to get the code running
    int choice;
    bool running = true;
    loadFromFile(); // Runs the function to load in the file
    // The menu for the program, using a bool variable as a condition.
    while (running) {
        cout << "\n--- PHONE BOOK MENU ---\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search by Name\n";
        cout << "4. Delete Contact\n";
        cout << "5. Edit Contact\n";
        cout << "6. Exit+Save\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore(); // This thing ignores the last leftover character(Primarily a space or newline)
        // Switch to call out the functions to get them running upon the user's choice
        switch (choice) {
        case 1: addContact(); break;
        case 2: viewContacts(); break;
        case 3: searchContact(); break;
        case 4: deleteContact(); break;
        case 5: editContact(); break;
        case 6:
            // Saves the data to a .txt file and changes the value of the bool variable to end the program.
            saveToFile(); 
            cout << "Goodbye!\n";
            running = false;
            break;
        // If you enter something which you weren't supposed to, it will just re-do the prompt and tell you did something wrong
        default:
            cout << "Invalid choice.\n";
            break;
        }
    }
}