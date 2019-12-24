#include <stdlib.h>
#include <stdio.h>

void tree(int length, int time);

int main(){
    int l, t;
    scanf("%d%d", &l, &t);
    tree(l, t);

    return 0;
}

void tree(int length, int time){
    int total = length + 1;
    int * trees = (int *) malloc(total * sizeof(int));
    for(int count = 0; count < total; count++){
        *(trees + count) = 0;
    }
    for(int count = 0; count < time; count++){
        int start, end;
        scanf("%d%d", &start, &end);
        for(int s = start; s <= end; s++){
            *(trees + s) = 1;
        }
    }

    int sum = 0;
    for(int count = 0; count < total; count++){
        if(*(trees + count) == 0){
            sum++;
        }
    }

    free(trees);
    printf("%d", sum);
}