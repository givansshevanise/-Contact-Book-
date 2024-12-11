#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>

using namespace std;
#include "Contact.h"

class Operations {
private:
    bool isValid(const string &email) {
        const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
        return regex_match(email, pattern);
    }

public:
    Contact NewContact;

    void addContact() {
        fstream myFile;
        myFile.open("contact.txt", ios::app);

        if (!myFile) {
            cout << "Failed to open the file." << endl;
            return;
        }

        string storeName, phoneNumber, email, address;
        cout << "Enter The Required Information\n" << endl;

        cout << "Name: ";
        cin >> storeName;

        cout << "Phone Number: ";
        cin >> phoneNumber;
        if (phoneNumber.length() != 11) {
            cout << "Incorrect Phone Format" << endl;
        }

        cout << "Email: ";
        cin >> email;
        if (!isValid(email)) {
            cout << "Incorrect Email Format" << endl;
            return;
        }

        cout << "Address: ";
        cin >> address;

        NewContact.SetStoreName(storeName);
        NewContact.SetPhoneNumber(phoneNumber);
        NewContact.SetEmail(email);
        NewContact.SetAddress(address);

        myFile << NewContact.GetStoreName() << ","
               << NewContact.GetPhoneNumber() << ","
               << NewContact.GetEmail() << ","
               << NewContact.GetAddress() << "\n";

        cout << "Contact added successfully!" << endl;
        myFile.close();
    }

    void updateContact() {
        fstream myFile;
        myFile.open("contact.txt", ios::in);

        if (!myFile) {
            cout << "Failed to open the file." << endl;
            return;
        }

        string storeName, phoneNumber;
        cout << "Welcome To The Update Menu\n" << endl;

        cout << "Enter name of the contact to update: ";
        cin >> storeName;

        cout << "Enter phone number of the contact to update: ";
        cin >> phoneNumber;

        vector<string> fileLines;
        string line;
        bool contactFound = false;

        while (getline(myFile, line)) {
            stringstream ss(line);
            string contactName, contactPhone, contactEmail, contactAddress;

            getline(ss, contactName, ',');
            getline(ss, contactPhone, ',');
            getline(ss, contactEmail, ',');
            getline(ss, contactAddress);

            if (contactName == storeName && contactPhone == phoneNumber) {
                contactFound = true;
                cout << "Contact found. Enter the new details:\n";

                cout << "New Name: ";
                cin >> contactName;

                cout << "New Phone Number: ";
                cin >> contactPhone;

                cout << "New Email: ";
                cin >> contactEmail;

                cout << "New Address: ";
                cin >> contactAddress;

                string updatedLine = contactName + "," + contactPhone + "," + contactEmail + "," + contactAddress;
                fileLines.push_back(updatedLine);
            } else {
                fileLines.push_back(line);
            }
        }

        myFile.close();

        if (!contactFound) {
            cout << "Contact not found." << endl;
            return;
        }

        myFile.open("contact.txt", ios::out);
        if (!myFile) {
            cout << "Failed to open the file for writing." << endl;
            return;
        }

        for (const string &fileLine : fileLines) {
            myFile << fileLine << "\n";
        }

        cout << "Contact updated successfully!" << endl;
        myFile.close();
    }

    void searchContact() {
        string searchName;

        cout << "Enter the name of the contact you would like to search: ";
        cin >> searchName;

        fstream myFile;
        myFile.open("contact.txt", ios::in);

        if (!myFile) {
            cout << "Failed to open the file." << endl;
            return;
        }

        string line;
        bool contactFound = false;

        while (getline(myFile, line)) {
            stringstream ss(line);
            string storeName, phoneNumber, email, address;

            getline(ss, storeName, ',');
            getline(ss, phoneNumber, ',');
            getline(ss, email, ',');
            getline(ss, address);

            if (storeName == searchName) {
                cout << "Contact Found:\n";
                cout << "Name: " << storeName << "\n";
                cout << "Phone Number: " << phoneNumber << "\n";
                cout << "Email: " << email << "\n";
                cout << "Address: " << address << "\n";
                contactFound = true;
                break;
            }
        }

        if (!contactFound) {
            cout << "Contact Not Found." << endl;
        }

        myFile.close();
    }

    void viewContactList() {
        cout << "Welcome To My Contact List\n" << endl;

        fstream myFile;
        myFile.open("contact.txt", ios::in);

        if (!myFile) {
            cout << "Failed to open the file." << endl;
            return;
        }

        string line;
        bool isEmpty = true;

        while (getline(myFile, line)) {
            isEmpty = false;
            stringstream ss(line);
            string storeName, phoneNumber, email, address;

            getline(ss, storeName, ',');
            getline(ss, phoneNumber, ',');
            getline(ss, email, ',');
            getline(ss, address);

            cout << "----------------------------------" << endl;
            cout << "Name: " << storeName << "\n";
            cout << "Phone Number: " << phoneNumber << "\n";
            cout << "Email: " << email << "\n";
            cout << "Address: " << address << "\n";
        }

        if (isEmpty) {
            cout << "No contacts found in the list." << endl;
        }

        cout << "----------------------------------" << endl;
        myFile.close();
    }

    void deleteContact() {
        string deleteContact;

        cout << "Enter the name of the contact you would like to delete: ";
        cin >> deleteContact;

        fstream myFile;
        myFile.open("contact.txt", ios::in);

        if (!myFile) {
            cout << "Failed to open the file." << endl;
            return;
        }

        vector<string> fileLines;
        string line;
        bool contactFound = false;

        while (getline(myFile, line)) {
            stringstream ss(line);
            string storeName, phoneNumber, email, address;

            getline(ss, storeName, ',');
            getline(ss, phoneNumber, ',');
            getline(ss, email, ',');
            getline(ss, address);

            if (storeName == deleteContact) {
                contactFound = true;
                cout << "Contact \"" << storeName << "\" deleted successfully!" << endl;
            } else {
                fileLines.push_back(line);
            }
        }

        myFile.close();

        if (!contactFound) {
            cout << "Contact not found." << endl;
            return;
        }

        myFile.open("contact.txt", ios::out);
        if (!myFile) {
            cout << "Failed to open the file for writing." << endl;
            return;
        }

        for (const string &fileLine : fileLines) {
            myFile << fileLine << "\n";
        }

        myFile.close();
    }
};
