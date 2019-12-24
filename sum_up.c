#include <stdio.h>

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d",  a > b && (a % b) == 0 ? a + b : a);

    return 0;
}