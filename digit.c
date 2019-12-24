#include <stdio.h>

int get_sum(long input);

int main(){
    int input;
    scanf("%d", &input);
    int result = get_sum(input);
    printf("%d", result);


    return 0;
}

int get_sum(long input){
    long current;
    int sum = 0;
    if(input < 0){
        current = -input;
    } else{
        current = input;
    }
    do{
        sum += current % 10;
        current /= 10;
    } while (current >= 1);

    return sum;
}