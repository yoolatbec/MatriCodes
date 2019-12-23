#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void light(int total, int start, int interval);

int main(){
    int total, start, interval;
    scanf("%d%d%d", &total, &start, &interval);
    light(total, start, interval);

    return 0;
}

void light(int total, int start, int interval){
    int * lights = (int *) malloc (total * sizeof(int));
    for(int count = 0; count < total; count++){
        *(lights + count) = 1;
    }
    int rest = total;
    int current = start;
    while(rest > 0){
        *(lights + current) = 0;
        printf("%d ", current);
        rest--;
        if(rest == 0){
            break;
        }
        int skip = 0;
        while(skip < interval){
            current++;
            if(current == total){
                current = 0;
            }
            if(*(lights + current) == 0){
                continue;
            }
            skip++;
        }
    }
}