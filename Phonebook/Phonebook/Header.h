#pragma once
#include <iostream>
#include <string>
using namespace std;

const int MAX_CONTACTS = 100;

string names[MAX_CONTACTS];
string phones[MAX_CONTACTS];
string notes[MAX_CONTACTS];
int contactCount = 0;

void addContact() {
    if (contactCount < MAX_CONTACTS) {
        cout << "Name: ";
        getline(cin, names[contactCount]);
        cout << "Phone: ";
        getline(cin, phones[contactCount]);
        cout << "Note (e.g. birthdate or short description, or leave empty): ";
        getline(cin, notes[contactCount]);
        contactCount++;
        cout << "Contact added successfully.\n";
    }
    else {
        cout << "Phone book is full.\n";
    }
}

void viewContacts() {
    if (contactCount == 0) {
        cout << "No contacts yet.\n";
    }
    else {
        cout << "\n--- CONTACT LIST ---\n";
        for (int i = 0; i < contactCount; i++) {
            cout << i + 1 << ". " << names[i] << " - " << phones[i];
            if (notes[i] != "") {
                cout << " (" << notes[i] << ")";
            }
            cout << "\n";
        }
    }
}

void searchContact() {
    string searchName;
    cout << "Enter name to search: ";
    getline(cin, searchName);
    bool found = false;
    for (int i = 0; i < contactCount; i++) {
        if (names[i] == searchName) {
            cout << "\nFound: " << names[i] << " - " << phones[i];
            if (notes[i] != "") {
                cout << " (" << notes[i] << ")";
            }
            cout << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Contact not found.\n";
    }
}

void deleteContact() {
    string deleteName;
    cout << "Enter the name of the contact to delete: ";
    getline(cin, deleteName);
    bool found = false;
    for (int i = 0; i < contactCount; i++) {
        if (names[i] == deleteName) {
            for (int j = i; j < contactCount - 1; j++) {
                names[j] = names[j + 1];
                phones[j] = phones[j + 1];
                notes[j] = notes[j + 1];
            }
            contactCount--;
            cout << "Contact deleted.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Contact not found.\n";
    }
}

void editContact() {
    string editName;
    cout << "Enter the name of the contact to edit: ";
    getline(cin, editName);
    bool found = false;
    for (int i = 0; i < contactCount; i++) {
        if (names[i] == editName) {
            cout << "Editing contact: " << names[i] << "\n";

            cout << "New name (leave blank to keep current): ";
            string newName;
            getline(cin, newName);
            if (newName != "") names[i] = newName;

            cout << "New phone (leave blank to keep current): ";
            string newPhone;
            getline(cin, newPhone);
            if (newPhone != "") phones[i] = newPhone;

            cout << "New note (leave blank to keep current): ";
            string newNote;
            getline(cin, newNote);
            if (newNote != "") notes[i] = newNote;

            cout << "Contact updated.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Contact not found.\n";
    }
}
