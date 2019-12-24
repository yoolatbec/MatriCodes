#include <stdio.h>

int eu_al(int a, int b);

int main(){
    long a, b;
    scanf("%d%d", &a, &b);
    printf("%d", eu_al(a, b));

    return 0;
}

int eu_al(int a, int b){
    int rest = 0;
    int larger, less;
    larger = a >= b ? a : b;
    less = a >= b ? b : a;
    while((larger % less) != 0){
        rest = larger % less;
        larger = less;
        less = rest;
    }
    return less;
}