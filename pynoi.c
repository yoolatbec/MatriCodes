#include <stdio.h>

long long getStepNum(int);

int main(){
    int input;
    scanf("%d", &input);
    long long result = getStepNum(input);
    printf("%lld", result);

    return 0;
}

long long getStepNum(int input){
    if(input == 1){
        return 3;
    }
    if(input == 2){
        return 9;
    }
    int current = 2 * getStepNum(input - 1);
    return (current + 3) % 10007;
}