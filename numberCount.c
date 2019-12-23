#include <stdio.h>

void count(int input);

int main(){
    int time;
    scanf("%d", &time);
    for(int c = 0; c < time; c++){
        int input;
        scanf("%d", &input);
        count(input);
    }

    return 0;
}

void count(int input){
    int output[10];
    for(int count = 0; count < 10; count++){
        output[count] = 0;
    }
    int hun = input / 100;
    for(int count = 1; count <= hun; count++){
        output[count] += 100;
    }
    for(int count = 0; count < 10; count++){
        output[count] += hun;
    }
    int ten = (input / 10) % 10;
    for(int count = 0; count <= ten; count++){
        if(hun == 0 && count == 0){
            continue;
        }
        output[count]++;
    }
    int newten = input / 10;
    for(int count = 0; count < 10; count++){
        output[count] += newten;
    }
    int sin = input % 10;
    for(int count = 0; count <= sin; count++){
        output[count]++;
    }
    if(ten){
        output[ten] += sin;
    }
    output[0]--;
    for(int count = 0; count < 10; count++){
        printf("%d ", output[count]);
    }
    putchar('\n');
}