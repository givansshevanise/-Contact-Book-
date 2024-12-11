#include <iostream>
using namespace std;

class Contact {
    private:

        string storeName;
        string phoneNumber;
        string email;
        string address;

    public:
        //Getters
        string GetStoreName(void){return storeName;}
        string GetPhoneNumber(void){return phoneNumber;}
        string GetEmail(void){return email;}
        string GetAddress(void){return address;}

        //Setters
        void SetStoreName(string StoreName){storeName = StoreName;}
        void SetPhoneNumber(string PhoneNumber){phoneNumber = PhoneNumber;}
        void SetEmail(string Email){email = Email;}
        void SetAddress(string Address){address = Address;}

        void Display(){
            cout<<"Store Name: \n"<<storeName<<endl;
            cout<<"Phone Number: \n"<<phoneNumber<<endl;
            cout<<"Email: \n"<<email<<endl;
            cout<<"Address: \n"<<address<<endl;
        }

};