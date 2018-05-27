#include "square.hpp"
#include <iostream>
using namespace std;

/*
def ctor
*/
square::square(){}
/*
ctor
*/
square::square(char someChar){
     c = someChar;
}
/*
overloading operator <<
*/
ostream& operator<< (ostream& out,square& s){
   return cout <<s.c;
}
/*
overloading operator =
*/
char& square::operator=(char someChar){
    return c = someChar;  
}
/*
overloading operator char to convert from square to char
*/
square::operator char(){
   return c;
}
/*
overloading operator ==
*/
bool square::operator==(char someChar)const{
    if(c==someChar){
       return true;
   }
   return false;
}