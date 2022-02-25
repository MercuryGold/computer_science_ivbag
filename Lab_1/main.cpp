#include <iostream>
#include "Header.h"


using namespace std;
int main() {
    cout << "Конструктор по умолчанию:\n";
    Employee a;
    a.Print();
    cout << "Конструктор с параметрами:\n";
    Employee b("Агафья", 90, 67);
    b.Print();
    cout << "Указатель:";
    Employee* c = new Employee("Прохор", 50, 26);
    cout << endl;
    (*c).Print();
    delete c;
    cout << "Копирование:";
    Employee d = b;
    cout << endl;
    d.Print();
    
    return 0;
}
