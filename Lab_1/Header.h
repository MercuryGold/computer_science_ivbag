#ifndef Header_h
#define Header_h


class Employee {
private:
    char* n;
    int age;
    int work_experience;
public:
    Employee(const char* name = "Имя", int age = 0, int work_experience = 0);
    Employee(const Employee& copy);
    ~Employee();
    char* GetName();
    int GetAge();
    int GetWork_Experience();
    void SetName(char* n);
    void SetAge(int age);
    void SetWork_Experience(int work_experince);
    void Print();
};
#endif
