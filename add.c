#include <stdio.h>

double m(int);

int main(){
    int input;
    scanf("%d", &input);
    double result = m(input);
    printf("%0.2f", result);

    return 0;
}

double m(int n){
    double result = 0;
    if(n == 0){
        return 0;
    }
    return (double)n / (double)(n + 1) + m(n - 1);
}