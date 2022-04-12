#include "./lib/standard_lib.h"
#include "./lib/manual.h"

int main(int argc, char* argv[]){

    if (int argc <=  1){
        Manual(ERROR);
        return 0;
    }
    else if(int argc >= 2 && argv =='-h'){
        Manual(HELP);
        return 0;
    }
    else if(int argc >= 2 && argv =='-l'){
        Manual(LIST);
        return 0;
    }
    else if(int argc >= 2 && argv =='-s'){
        Manual(start);
        
        return 0;
    }
    else{
        return EOF;
    }


    return 0;
}