#define CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <cstdlib>
#include "file_lab_2.hpp"

using namespace std;


str::str(const char* name) {
    n = new char[30];
    strcpy(n, name);
}

str::str(const str& constructor) {
    n = new char[30];
    strcpy(n, constructor.n);
}

str::~str() {
    delete[] n;
    cout << "\nУдаление завершено! \n";
}

void str::Print(void) {
    cout << "Строка: " << n << endl;
}

char* str::GetS() {
    return n;
}

void str::SetS(char* name) {
    strcpy(n, name);
}

string str::operator ++() {
    string p = this -> n;
    transform(p.begin(), p.end(), p.begin(), ::toupper);
    return p;
}

void str::operator --() {
    int count = 0;
    int size = 0;
    char* p = NULL;
    char* s = NULL;
    p = this -> n;
    
    while (*p != '\0') {
        if (*p != ' ') {
            while ((*p != ' ') && (*p != '\0')) {
                count++;
                p++;
            }
            if (count > size) {
                size = count;
                s = p - size;
            }
            count = 0;
            if (*p == '\0') break;
            p++;
        }
    }
    cout << "Самое длинное слово: ";
    while (size > 0) {
        cout << *s;
        s++;
        size--;
    }
    cout << endl;
}
