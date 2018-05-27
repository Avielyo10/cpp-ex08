#include <iostream>
using namespace std;

class square{
    private:
    char c;
    public:
    square();
    square(char someChar);
    friend ostream& operator<< (ostream& out,square& s);
    char& operator=(char someChar);
    operator char();
    bool operator==(char someChar)const;
};
