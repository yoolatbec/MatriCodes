#include <stdio.h>

void hanoi(int, int, int, int);

int main(){
    int sum;
    scanf("%d", &sum);
    hanoi(sum, 1, 3, 2);

    return 0;
}

void hanoi(int sum, int origin, int target, int aux){
    if(sum == 1){
        printf("%d%d\n", origin, target);
        return;
    }


    hanoi(sum - 1, origin, aux, target);
    hanoi(1, origin, target, aux);
    hanoi(sum - 1, aux, target, origin);
}