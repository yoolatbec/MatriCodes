#include <stdio.h>
int main() {
    int a[3][4]={1,5,8,10,11,3,4,8,7};
    int *p = (int*)a;
    int (*q)[4] = a;
    p += 1;
    q += 1;
    printf("%d ", *p);
    printf("%d ", **q);
    printf("%d ", (*q)[2]);
    printf("%d\n", *q+3-p);
    return 0;
}