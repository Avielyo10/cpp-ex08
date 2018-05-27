#include "Board.h"
#include <boost/functional/hash.hpp>
#include <iostream>
using namespace std;

/*
hash-code function to create unique name for every image
*/
int hashCode(string s){
    boost::hash<std::string> string_hash;
    return string_hash(s);
}
/*
ctor 
*/
Board::Board(int num){
    board = new square*[num];
    for(int i = 0; i < num;++i){
        board[i] = new square[num];
        for(int j = 0; j < num;++j){
            board[i][j] = '.';
        }
    }
    size = num;
    name="";
}
/*
copy ctor
*/
Board::Board(const Board& b){
    size = b.size;
    name = b.name;
    board = new square*[size];
    for(int i = 0; i < size;++i){
        board[i] = new square[size];
        for(int j = 0; j < size;++j){
            board[i][j] = b.board[i][j];
        }
    }
}
/*
dtor
*/
Board::~Board(){
    for(int i = 0; i < size;++i){
        delete[] board[i];
    }
    delete[] board;
}
/*
overloading operator <<
*/
ostream& operator<<(ostream& out,Board const &b){
    string res = "";
    for(int i = 0; i<b.size; ++i){
        for(int j = 0; j<b.size; ++j){
            res+=b.board[i][j];
        }
        res+="\n";
    }
    return out<<res;
}
/*
overloading operator >>
*/
istream& operator>>(istream& in,Board &b){
    int counter=0,tempSize=0;
    char c;
    bool flag = true;
    vector<char> allChars;
    while(cin.get(c)){
        if(flag&&(c=='\n')){
            tempSize = counter;
            flag = false;
        }
        counter++;
        allChars.push_back(c);
    }
    Board temp{tempSize};
    int k = 0;
    for(int i=0;i<temp.size;++i){
        temp.name+=allChars.at(k);
        for(int j=0;j<temp.size;++j){
            if(allChars.at(k)!='\n'){
                temp.board[i][j] = allChars.at(k);  
            }
            else{
                temp.board[i][j] = allChars.at(++k); 
            }
            k++;
        }
    }
    b = temp;
    b.name = to_string(hashCode(temp.name));
    return in;
}
/*

*/
int Board::theRightRatio(uint num, int size){
    while(num%size!=0){
        num++;
    }
    return num/size;
}
/*

*/
string Board::draw(uint num){ 
    string fileName = "img_"+name+".ppm";
    ofstream imageFile(fileName, ios::out | ios::binary);
    imageFile << "P6" << endl << num <<" " << num << endl << 255 << endl;
    RGB image[num*num];
    int ratio = theRightRatio(num,size);
    for (int j = 0; j < num; ++j){
        for (int i = 0; i < num; ++i){ 
            char boardChar=board[j/ratio][i/ratio];
            image[num*j+i].red = (boardChar%256);
            image[num*j+i].green = (boardChar%256);
            image[num*j+i].blue = (boardChar%256);
        }
    }  
    imageFile.write(reinterpret_cast<char*>(&image),3*num*num);
    imageFile.close();
    return fileName;
}
/*
overloading operator []
*/
square& Board::operator[](const pair<int,int>& someIndex){
    return board[someIndex.first][someIndex.second];
}
/*
overloading operator = ot char
*/
Board& Board::operator=(char c){
    for(int i = 0; i < size;++i){
        for(int j = 0; j < size;++j){
            board[i][j] = c;
        }
    } 
    return *this;
}
/*
overloading operator = to another board
*/
Board& Board::operator=(Board &b){
    if(size>0){
        this->~Board();
    }
    size=b.size;
    board = new square*[size];
    for(int i = 0; i < size;++i){
        board[i] = new square[size];
        for(int j = 0; j < size;++j){
            board[i][j] = b.board[i][j];
        }
    }
    return *this;
}
/*
overloading operator ==
*/
bool Board::operator==(Board &b)const{
    if(size!=b.size){
        return false;
    }
    bool flag = true;
    for(int i = 0;i < size; ++i){
        for(int j = 0;j < size; ++j){
            if(board[i][j]!=b.board[i][j]){
                flag = false;
            }
        }
    }
    return flag;
}
