#include <iostream>
#include "file_lab_2.hpp"

using namespace std;


int main(void) {
    cout << "\nКонструктор по умолчанию \n";
    str a;
    a.Print();
    cout << "\nКонструктор с параметрами \n";
    str b("Абдурахман");
    b.Print();
    cout << "\nУказатель \n";
    str* p = new str("Кощей");
    (*p).Print();
    delete p;
    cout << "\nКопирование \n";
    str c = b;
    c.Print();
    cout << "\nПерегруженные операторы \n";
    cout << ++b << endl;
    --b;
    
    return 0;
}
