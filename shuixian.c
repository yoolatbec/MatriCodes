#include <stdio.h>

int getRightNum(int max);

int main(){
    int input;
    scanf("%d", &input);
    int output = getRightNum(input);
    printf("%d", output);

    return 0;
}

int getRightNum(int max){
    int current = max;
    int numbers[3];
    int sum;
    if(max < 100 || max > 999){
        return -1;
    }
    while(current > 100){
        sum = 0;
        numbers[0] = current / 100;
        numbers[1] = (current / 10) % 10;
        numbers[2] = current %  10;
        for(int index = 0; index < 3; index++){
            int n = numbers[index];
            sum += n * n * n;
        }
        if(sum == current){
            break;
        }
        current--;
    }
    if(current != 100){
        return current;
    } else {
        return -1;
    }
}