#include <stdio.h>
#include <stdlib.h>

void sort(int *, int *, int *);

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    sort(&a, &b, &c);
    printf("%d %d %d", a, b, c);

    return 0;
}

void sort(int * a, int * b, int * c){
    int * num = (int *) malloc(3 * sizeof(int));
    num[0] = *a;
    num[1] = *b;
    num[2] = *c;
    for(int count = 0; count < 2; count++){
        for(int c = 0; c < 2 - count; c++){
            if(num[c] >= num[c + 1]){
                int tmp = num[c];
                num[c] = num[c + 1];
                num[c + 1] = tmp;
            }
        }
    }
    *a = num[0];
    *b = num[1];
    *c = num[2];
}