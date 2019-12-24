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

    int ten = input % 100;
    int ten1 = ten / 10;
    for(int count = 0; count < 10; count++){
        output[count] += ten1;
    }
    for(int count = 0; count <= ten1; count++){
        if(hun == 0 && count == 0){
            continue;
        }
        output[count] += 10;
    }

    int sin = (input % 100) % 10;
    for(int count = 0; count <= sin; count++){
        if(hun == 0 && ten1 == 0 && count == 0){
            continue;
        }
        output[count]++;
    }
    int sin2 = input / 10;
    for(int count = 0; count < 10; count++){
        output[count] += sin2;
    }
    output[0]--;
    for(int count = 0; count < 10; count++){
        printf("%d ", output[count]);
    }
    putchar('\n');
}