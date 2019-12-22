#include <stdio.h>
#include <stdlib.h>

void discard(int);

int main(){
    int time;
    scanf("%d", &time);
    for(int count = 0; count < time; count++){
        int total;
        scanf(" %d", &total);
        discard(total);
    }

    return 0;
}

void discard(int total){
    int * cards = (int *) malloc ((total * 2 + 1) * sizeof(int));
    for(int count = 0; count < total; count++){
        *(cards + count) = count + 1;
    }
    int current = 0;
    int last = total;
    int rest = total;
    while(rest > 0){
        printf("%d ", *(cards + current));
        current++;
        *(cards + last) = *(cards + current);
        last++;
        current++;
        rest--;
    }
    putchar('\n');
    free(cards);
}