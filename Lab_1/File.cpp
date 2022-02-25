#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Header.h"


using namespace std;
Employee::Employee(const char* name, int age, int work_experience) {
    n = new char[30];
    strcpy(n, name);
    this -> age = age;
    this -> work_experience = work_experience;
}

Employee::Employee(const Employee& constructor) {
    n = new char[30];
    strcpy(n, constructor.n);
    age = constructor.age;
    work_experience = constructor.work_experience;
}

Employee::~Employee() {
    delete[] n;
    cout << "Удаление завершено\n" << endl;
}

void Employee::Print(void) {
    std::cout << "Имя: " << n << endl;
    std::cout << "Возраст: " << age << endl;
    std::cout << "Стаж: " << work_experience <<endl << endl;
}

char* Employee::GetName() {
    return n;
}
int Employee::GetAge() {
    return age;
}
int Employee::GetWork_Experience() {
    return work_experience;
}

void Employee::SetName(char* name) {
    strcpy(n, name);
}
void Employee::SetAge(int age) {
    age = age >= 0 ? age : 0;
}
void Employee::SetWork_Experience(int work_experience) {
    work_experience = work_experience >= 0 ? work_experience : 0;
}
