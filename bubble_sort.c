#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int total);

int main(){
    int time;
    scanf("%d", &time);
    for(int count = 0; count < time; count++){
        int total;
        scanf(" %d", &total);
        bubble_sort(total);
    }

    return 0;
}

void bubble_sort(int total){
    int * nums = (int *) malloc(total * sizeof(int));
    for(int count = 0; count < total; count++){
        scanf(" %d", (nums + count));
    }
    int exchange = 0;
    for(int time = 0; time < total - 1; time++){
        exchange = 0;
        for(int pos = 0; pos < total - 1 - time; pos++){
            if(*(nums + pos) > *(nums + pos + 1)){
                exchange = 1;
                int tmp = *(nums + pos);
                *(nums + pos) = *(nums + pos + 1);
                *(nums + pos + 1) = tmp;
            }
            for(int count = 0; count < total; count++){
                printf("%d ", *(nums + count));
            }
            putchar('\n');
        }
        if(!exchange){
            break;
        }
    }
    free(nums);
}