#include "square.hpp"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

struct RGB {
  uint8_t red, green, blue;
public:
  RGB() {}
  RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};

class Board{
    public:
    int size;
    string name;
    square** board;
    Board(){}
    Board(int num);
    Board(const Board& b);
    ~Board();
    friend ostream& operator<<(ostream& out,Board const &b);
    friend istream& operator>>(istream& in,Board &b);
    square& operator[](const pair<int,int>& someIndex);
    Board& operator=(char c);
    Board& operator=(Board &b);
    bool operator==(Board &b)const;
    string draw(uint num);
    int theRightRatio(uint num, int size);
    string random_string(int length);
};

