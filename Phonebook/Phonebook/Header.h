// Libraries
#pragma once
#include <iostream>
#include <string>
#include <windows.h> 
#include <cstdlib>
// Basics such as namespace for convenience and the structure array which will be used throughout the rest of the project
using namespace std;

// Initial capacity for the dynamic array
const int INITIAL_CAPACITY = 10;

// Contact struct for storing user data
struct Contact {
    string name;
    string phone;
    string note;
};

// Dynamic array and variables for it instead of a static one. The main difference is just the fact that it increases it's size each time I try to add a new contact instead of
// Just the array being like 100 indexes long
Contact* contacts = new Contact[INITIAL_CAPACITY];
int capacity = INITIAL_CAPACITY;
int contactCount = 0;

// Resizes the contact array when it's full
void resizeArray() {
    capacity *= 2;
    Contact* newContacts = new Contact[capacity];
    for (int i = 0; i < contactCount; i++) {
        newContacts[i] = contacts[i];
    }
    delete[] contacts;
    contacts = newContacts;
}

void addContact() {
    // Checks if the contact that the user is trying to enter isn't going to go over the limit
    if (contactCount >= capacity) {
        resizeArray();
    }
    // Entering the information via getline, due to the fact that getline reads the entire line instead of just the first word
    // After which it adds +1 to the contact count to not accidentally overwrite data.
    cout << "Name: ";
    getline(cin, contacts[contactCount].name);
    cout << "Phone: ";
    getline(cin, contacts[contactCount].phone);
    cout << "Note (e.g. birthdate or short description, or leave empty): ";
    getline(cin, contacts[contactCount].note);
    contactCount++;
    system("cls");
    cout << "Contact added successfully.\n";
}

// This one is a lot easier. It simply just goes over every single element in the array to find the one that matches, it's not
// rocket science really.
void viewContacts() {
    system("cls");
    if (contactCount == 0) {
        cout << "No contacts yet.\n";
    }
    else {
        cout << "\n--- CONTACT LIST ---\n";
        for (int i = 0; i < contactCount; i++) {
            cout << i + 1 << ". " << contacts[i].name << " - " << contacts[i].phone;
            // This if check exists so you can leave the note part empty
            if (contacts[i].note != "") {
                cout << " (" << contacts[i].note << ")";
            }
            cout << "\n";
        }
    }
}

// Creates a temporary string which you enter, then it tries to compare it to every name in the array to find it, when it does
// it prints out all the data at that index (If it doesnt find it, it just says it didnt, simple enough)
void searchContact() {
    string searchName;
    cout << "Enter name to search: ";
    getline(cin, searchName);
    system("cls");
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

// The most painful function I made, primarily works the same as the search contact, except when it finds it, it deletes it and then
// effectively pushes the rest of the array to the left
void deleteContact() {
    string deleteName;
    cout << "Enter the name of the contact to delete: ";
    getline(cin, deleteName);
    system("cls");
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

// This one also works on a similar basis. A string into which you enter the name you want, then it checks through the entire array
// When it finds it, it just gives you prompts to replace every single one in the same index, using new variables
// (You can leave the field empty to not change it)
void editContact() {
    string editName;
    cout << "Enter the name of the contact to edit: ";
    getline(cin, editName);
    system("cls");
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
// I primarily stole both over from some of our classworks, they work the same as they did before
void saveToFile() {
    FILE* out = nullptr;
    fopen_s(&out, "C:/Users/User/source/repos/Phonebook/contacts.txt", "w");
    if (out != nullptr) {
        for (int i = 0; i < contactCount; i++) {
            fprintf(out, "%s\n", contacts[i].name.c_str());
            fprintf(out, "%s\n", contacts[i].phone.c_str());
            fprintf(out, "%s\n", contacts[i].note.c_str());
        }
        fclose(out);
        cout << "Contacts saved to file.\n";
    }
    else {
        cout << "Unable to save contacts.\n";
    }
}

void loadFromFile() {
    FILE* in = nullptr;
    fopen_s(&in, "C:/Users/User/source/repos/Phonebook/contacts.txt", "r");
    if (in != nullptr) {
        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), in)) {
            if (contactCount >= capacity) resizeArray();

            buffer[strcspn(buffer, "\n")] = 0;
            contacts[contactCount].name = buffer;

            if (!fgets(buffer, sizeof(buffer), in)) break;
            buffer[strcspn(buffer, "\n")] = 0;
            contacts[contactCount].phone = buffer;

            if (!fgets(buffer, sizeof(buffer), in)) break;
            buffer[strcspn(buffer, "\n")] = 0;
            contacts[contactCount].note = buffer;

            contactCount++;
        }
        fclose(in);
        cout << "Contacts loaded from file.\n";
    }
    else {
        cout << "No file found. Starting with an empty phone book.\n";
    }
}
