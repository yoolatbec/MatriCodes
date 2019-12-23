#include <stdio.h>

void count(int input);

int main(){


    return 0;
}

void count(int input){
    int output[10];
    for(int count = 0; count < 10; count++){
        output[count] = 0;
    }
    int single = input % 10;
    for(int count = 0; count <= single; count++){
        output[count]++;
    }
    int tentime = input / 10;
    for(int count = 0; count < 10; count++){
        output[count] += tentime;
    }
    int tennum = tentime % 10;
    for(int count = 0; count <= tennum; count++){
        output[count]++;
    }
}