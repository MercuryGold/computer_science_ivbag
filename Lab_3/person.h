#define _CRT_SECURE_NO_WARNINGS
#ifndef person_h
#define person_h
#include <cstring>


class Person {
protected:
    int age;
public:
    Person();
    virtual void Print();
    virtual void Input();
    virtual void get_info() = 0;
    virtual void show_info() = 0;
};

class Servant : public Person {
private:
    int wage;
public:
    Servant() : Person() {
        wage = 0;
    };
    void get_info();
    void show_info();
};

class Labor : public Person {
private:
    char code[30];
public:
    Labor() : Person() {
        strcpy(code, "not issued");
    };
    void get_info();
    void show_info();
};

class Engineer : public Person {
private:
    char projects[30];
public:
    Engineer() : Person() {
        strcpy(projects, "no projects");
        age = 0;
    };
    void get_info();
    void show_info();
};

#endif
