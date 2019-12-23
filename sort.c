#include <stdio.h>
#include <stdlib.h>

void sort(int * start);

int main(){
    int sum, * numbers;
    scanf("%d", &sum);
    numbers = malloc(sum * 3 * sizeof(int));
    for(int count = 0; count < sum * 3; count++){
        scanf("%d", numbers + count);
    }
    for(int group = 0; group < sum; group++){
        sort(numbers + group * 3);
    }
    for(int count = 0; count < sum; count++){
        printf("%d %d %d", *(numbers + count * 3), *(numbers + count * 3 + 1), *(numbers + count * 3 + 2));
        if(!(count == sum - 1)){
            printf("\n");
        }
    }

    free(numbers);

    return 0;
}

void sort(int * start){
    for(int count = 0; count < 2; count++){
        for(int c = 0; c < 2; c++){
            if(*(start + c) > * (start + c + 1)){
                int tmp = * (start + c);
                *(start + c) = *(start + c + 1);
                *(start + c + 1) = tmp;
            }
        }
    }
}