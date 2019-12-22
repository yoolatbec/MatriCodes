#include <stdio.h>
#include <stdlib.h>

void sort(int total);

int main(){
    int time;
    scanf("%d", &time);
    for(int count = 0; count < time; count++){
        int total;
        scanf(" %d", &total);
        sort(total);
    }

    return 0;
}

void sort(int total){
    int * nums = (int *) malloc(total * sizeof(int));
    for(int count = 0; count < total; count++){
        scanf(" %d", (nums + count));
    }
    int time = 0;
    int min = *(nums + time);
    int pos = time;
    while(time < total - 1){
        for(int count = time; count < total; count++){
            if(*(nums + count) < min){
                min = *(nums + count);
                pos = count;
            }
        }
        *(nums + pos) = *(nums + time);
        *(nums + time) = min;
        time++;
        min = *(nums + time);
        pos = time;
        for(int count = 0; count < total; count++){
            printf("%d ", *(nums + count));
        }
        putchar('\n');
    }
    free(nums);
}