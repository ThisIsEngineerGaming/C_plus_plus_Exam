#pragma once
#include <iostream>
#include <string>
#include <fstream> 
using namespace std;

const int MAX_CONTACTS = 100;
const string FILE_PATH = "C:/Users/User/source/repos/Phonebook/contacts.txt";
struct Contact {
    string name;
    string phone;
    string note;
};

Contact contacts[MAX_CONTACTS];
int contactCount = 0;

void addContact() {
    if (contactCount < MAX_CONTACTS) {
        cout << "Name: ";
        getline(cin, contacts[contactCount].name);
        cout << "Phone: ";
        getline(cin, contacts[contactCount].phone);
        cout << "Note (e.g. birthdate or short description, or leave empty): ";
        getline(cin, contacts[contactCount].note);
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
            cout << i + 1 << ". " << contacts[i].name << " - " << contacts[i].phone;
            if (contacts[i].note != "") {
                cout << " (" << contacts[i].note << ")";
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
        if (contacts[i].name == searchName) {
            cout << "\nFound: " << contacts[i].name << " - " << contacts[i].phone;
            if (contacts[i].note != "") {
                cout << " (" << contacts[i].note << ")";
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
        if (contacts[i].name == deleteName) {
            for (int j = i; j < contactCount - 1; j++) {
                contacts[j] = contacts[j + 1];
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
        if (contacts[i].name == editName) {
            cout << "Editing contact: " << contacts[i].name << "\n";

            cout << "New name (leave blank to keep current): ";
            string newName;
            getline(cin, newName);
            if (newName != "") contacts[i].name = newName;

            cout << "New phone (leave blank to keep current): ";
            string newPhone;
            getline(cin, newPhone);
            if (newPhone != "") contacts[i].phone = newPhone;

            cout << "New note (leave blank to keep current): ";
            string newNote;
            getline(cin, newNote);
            if (newNote != "") contacts[i].note = newNote;

            cout << "Contact updated.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Contact not found.\n";
    }
}
void saveToFile() {
    ofstream out("C:/Users/User/source/repos/Phonebook/contacts.txt");
    if (out.is_open()) {
        for (int i = 0; i < contactCount; i++) {
            out << contacts[i].name << "\n";
            out << contacts[i].phone << "\n";
            out << contacts[i].note << "\n";
        }
        out.close();
        cout << "Contacts saved to file.\n";
    }
    else {
        cout << "Unable to save contacts.\n";
    }
}

void loadFromFile() {
    ifstream in("C:/Users/User/source/repos/Phonebook/contacts.txt");
    if (in.is_open()) {
        string line;
        while (getline(in, line)) {
            if (contactCount >= MAX_CONTACTS) break;
            contacts[contactCount].name = line;
            if (!getline(in, contacts[contactCount].phone)) break;
            if (!getline(in, contacts[contactCount].note)) break;
            contactCount++;
        }
        in.close();
        cout << "Contacts loaded from file.\n";
    }
    else {
        cout << "No file found. Starting with an empty phone book.\n";
    }
}