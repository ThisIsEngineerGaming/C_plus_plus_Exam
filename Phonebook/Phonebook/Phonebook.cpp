#include "header.h"

int main() {
    int choice;
    bool running = true;

    while (running) {
        cout << "\n--- PHONE BOOK MENU ---\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search by Name\n";
        cout << "4. Delete Contact\n";
        cout << "5. Edit Contact\n";
        cout << "6. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: addContact(); break;
        case 2: viewContacts(); break;
        case 3: searchContact(); break;
        case 4: deleteContact(); break;
        case 5: editContact(); break;
        case 6:
            cout << "Goodbye!\n";
            running = false;
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    }
}