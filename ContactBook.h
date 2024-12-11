#include <iostream>
using namespace std;
#include "Operations.h"

class ContactBook {
    private:
        Operations operations; 
    public:

    void run(){
          int option;
           do {
            cout << "Welcome To Your Online Contact Book\n"
                 << "Menu Option:\n"
                 << "1.  Add Contact\n"
                 << "2.  View Contact List\n"
                 << "3.  Search Contact\n"
                 << "4.  Update Contact\n"
                 << "5.  Delete Contact\n"
                 << "6.  Exit Contact Book\n"
                 << endl;
            cin >> option;

            switch (option) {
                case 1:
                    operations.addContact(); 
                    break;
                case 2:
                    operations.viewContactList(); 
                    break;
                case 3:
                    operations.searchContact(); 
                    break;
                case 4:
                    operations.updateContact(); 
                    break;
                case 5:
                    operations.deleteContact(); 
                    break;
                case 6:
                    cout << "Thank you for using your online contact book!" << endl;
                    break;
                default:
                    cout << "Incorrect Option. Please try again." << endl;
            }
        } while (option != 6); 
    }

};