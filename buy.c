#include <stdio.h>

int main(){
    int price[] = {6, 8, 12, 3, 9};
    int num, sum;
    sum = 0;
    scanf("%d", &num);
    while(num != -1){
        sum += price[num - 1];
        scanf("%d", &num);
    }

    printf("%d", sum);

    return 0;
}