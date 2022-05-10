#define _CRT_SECURE_NO_WARNINGS
#include "person.h"
#include <iostream>


using namespace std;


Person::Person() {
    age = 0;
}
void Person::Print() {
    cout << "Age: " << age << endl;
}
void Person::Input() {
    cout << "Age: ";
    cin >> age;
}

void Servant::get_info() {
    Person::Input();
    cout << "Wage: ";
    cin >> wage;
    cout << endl;
}
void Servant::show_info() {
    Person::Print();
    cout << "Wage: " << wage << endl;
}

void Labor::get_info() {
    Person::Input();
    cout << "Code: ";
    cin >> code;
    cout << endl;
}
void Labor::show_info() {
    Person::Print();
    cout << "Code: " << code << endl;
}

void Engineer::get_info() {
    Person::Input();
    cout << "Projects: ";
    cin >> projects;
    cout << endl;
}
void Engineer::show_info() {
    Person::Print();
    cout << "Projects: " << projects << endl;
}
