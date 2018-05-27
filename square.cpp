#include "square.hpp"
#include <iostream>
using namespace std;

square::square(){}
square::square(char someChar){
     c = someChar;
}
ostream& operator<< (ostream& out,square& s){
   return cout <<s.c;
}
char& square::operator=(char someChar){
    return c = someChar;  
}
square::operator char(){
   return c;
}
bool square::operator==(char someChar)const{
    if(c==someChar){
       return true;
   }
   return false;
}