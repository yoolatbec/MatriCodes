#include <stdio.h>
#include <math.h>

long long BintoDec(char binary[]);

int main(){
    char * input = "10111";
    long long output = BintoDec(input);
    printf("%lld\n", output);

    return 0;
}

long long BintoDec(char * binary){
    int count = 0;
    long long sum = 0;
    while(*(binary + count) != '\0'){
        count++;
    }
    for(int c = count; c > 0; c--){
        sum += ((long long)pow(2, count - c) * (*(binary + c - 1) - '0'));
    }
    return sum;
}