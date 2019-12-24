#include <stdio.h>
#include <stdlib.h>

#define SWAP_TO_LEFT 1
#define SWAP_TO_RIGHT 2

void ball_sort(int, int);
void copy(int *, int *, int);

int main(){
    int time;
    scanf("%d", &time);
    for(int count = 0; count < time; count++){
        int ball, ins;
        scanf(" %d %d", &ball, &ins);
        ball_sort(ball, ins);
    }

    return 0;
}

void ball_sort(int ball_count, int ins_count){
    int * balls = (int *) malloc(ball_count * sizeof(int));
    int * tmp = (int *) malloc(ball_count * sizeof(int));
    for(int count = 0; count < ball_count; count++){
        *(balls + count) = count + 1;
    }
    int ins, src, dst;
    for(int count = 0; count < ins_count; count++){
        scanf(" %d %d %d", &ins, &src, &dst);
        int current = 0;
        int skip = 0;
        while(*(balls + current) != dst){
            if(*(balls + current) == src){
                skip = 1;
                current++;
                continue;
            }
            *(tmp + current - skip) = *(balls + current);
            current++;
        }
        switch(ins){
            case SWAP_TO_LEFT:
                *(tmp + current++ - skip) = src;
                *(tmp + current - skip) = dst;
                break;
            case SWAP_TO_RIGHT:
                *(tmp + current++ - skip) = dst;
                *(tmp + current - skip) = src;
                break;
        }  
        while(current < ball_count){
            *(tmp + current) = *(balls + current);
            current++;
        }
    copy(tmp, balls, ball_count);
    }
    for(int c = 0; c < ball_count; c++){
        printf("%d ", *(balls + c));
    }
    putchar('\n');
    free(balls);
    free(tmp);
}

void copy(int * src, int * dst, int length){
    for(int count = 0; count < length; count++){
        *(dst + count) = *(src + count);
    }
}