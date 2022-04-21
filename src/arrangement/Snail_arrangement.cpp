#include <iostream>
#include <cstdlib>
#include <string>

using std::cout;
using std::cin;
using std::endl;

enum{LEFT,RIGHT};

class Snail_Arrangement{
    int number,sign=1, count=0;
    int Col,Row;
    int k,Max;
    int *arr[];

public:
    Snail_Arrangement(int Max,int Start_Dir){
        number = this->Max = Max;
        k = number;

        *arr = new int[Max];

        for(int i = 0; i < Max; i++)
            arr[i] = new int[Max];
        
        if(RIGHT == Start_Dir) sign = -sign;

        while(true){
                for(Col = 0; Col < number; Col++){
                    Col += sign; 
                    arr[Row][Col] = ++count;
                }

                for(Row = 0; Row < number; Row++){
                    Col += sign; 
                    arr[Row][Col] = ++count;
                }
        }
        
    }

    ~Snail_Arrangement(){
        delete[] arr;
    }
};


int main(void){

    Snail_Arrangement Snail(10,LEFT);
}