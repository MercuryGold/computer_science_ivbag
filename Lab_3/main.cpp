#define _CRT_SECURE_NO_WARNINGS
#include "person.h"
#include <iostream>

using namespace std;


int main() {
    cout << "Default constructor called" << endl;
    Servant a;
    a.show_info();
    cout << endl;
    Person* Person[20];
    int i = 0;
    int choice;
    
    do {
        cout << "What do you want to add to the list?" << endl;
        cout << "1) Servant;  2) Labor;  3) Engineer " << endl;
        cin >> choice;
        if (choice == 1) {
            Person[i] = new Servant;
            Person[i++] -> get_info();
        } else if (choice == 2) {
            Person[i] = new Labor;
            Person[i++] -> get_info();
        } else if (choice == 3) {
            Person[i] = new Engineer;
            Person[i++] -> get_info();
        } else {
            cout << "Incorrect input" << endl;
            cout << "Try again?" << endl;
            cout << "1) Yes;  2) No" << endl;
            cin >> choice;
            cout << endl;
        }
    } while (choice == 1);

    for (int a = 0; a < i; a++) {
        delete Person[a];
    }
    
}
