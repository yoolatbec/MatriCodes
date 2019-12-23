#include <stdio.h>

int quick_power(int, int, int);

int main(){
    int a, b, p;
    scanf("%d%d%d", &a, &b, &p);
    printf("%d", quick_power(a, b, p));

    return 0;
}

int quick_power(int a, int b, int p){
    if(b == 1){
        return a % p;
    }

    return (a * quick_power(a, b - 1, p)) % p;
}