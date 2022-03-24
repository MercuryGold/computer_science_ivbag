#ifndef file_lab_2_hpp
#define file_lab_2_hpp

#include <string>

using namespace std;


class str {
public:
    char* n;
    str(const char* name = " ");
    str(const str& constructor);
    ~str();
    char* GetS();
    void SetS(char* n);
    void Print();
    string operator ++ ();
    void operator -- ();
};
#endif
