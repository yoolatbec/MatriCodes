#include <stdio.h>
#include <stdlib.h>

void find(int, int, int, int);
long eu_al(long, long);

int main(){
    int time;
    scanf("%d", &time);
    int * results = (int *) malloc(2 * time * sizeof(int));
    for(int count = 0; count < time; count++){
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        find(a, b, c, d);
    }

    return 0;
}

void find(int a, int b, int c, int d){
    int * result = (int *) malloc(2 * sizeof(int));
    int e, f;
    e = a * d + b * c;
    f = b * d;
    int max = (int) eu_al(e, f);
    e /= max;
    f /= max;
    printf("%d %d\n", e, f);
    free(result);
}

long eu_al(long a, long b){
    long rest = 0;
    long larger, less;
    larger = a >= b ? a : b;
    less = a >= b ? b : a;
    while((larger % less) != 0){
        rest = larger % less;
        larger = less;
        less = rest;
    }
    return less;
}