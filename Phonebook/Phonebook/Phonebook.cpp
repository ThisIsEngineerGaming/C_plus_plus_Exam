#include <iostream>
#include <string>
// I will start working on the visuals later down the line
using namespace std;

const int MAX_CONTACTS = 100;

int main() {
    string names[MAX_CONTACTS];
    string phones[MAX_CONTACTS];
    int contactCount = 0;
    int choice;

    while (true) {
        cout << "What would you like to do?\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search by Name\n";
        cout << "4. Delete contacts(WIP as of now)\n";
        cout << "5. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            if (contactCount < MAX_CONTACTS) {
                cout << "Name: ";
                getline(cin, names[contactCount]);
                cout << "Phone: ";
                getline(cin, phones[contactCount]);
                contactCount++;
            }
            else {
                cout << "Phone book full.\n";
            }
        }

        else if (choice == 2) {
            if (contactCount == 0) {
                cout << "You do not have any contacts as of now...\n\n";
            }
            else {
                for (int i = 0; i < contactCount; i++) {
                    cout << "These are your current contacts:\n";
                    cout << i + 1 << ". " << names[i] << " - " << phones[i] << "\n\n";
                }
            }
        }

        else if (choice == 3) {
            cout << "Searching...";
            string searchName;
            cout << "Enter name: ";
            getline(cin, searchName);
            bool found = false;
            for (int i = 0; i < contactCount; i++) {
                if (names[i] == searchName) {
                    cout << "Found: " << names[i] << " - " << phones[i] << "\n\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Not found.\n";
            }
        }
        //else if (choice == 4) {

        //}
        else if (choice == 5) {
            break;
        }

        else {
            cout << "Invalid.\n";
        }
    }
}