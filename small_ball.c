#include <stdio.h>
#include <stdlib.h>

#define SWAP_TO_LEFT 1
#define SWAP_TO_RIGHT 2

void ball_sort(int, int);
void copy(int *, int *, int);

int main(){
    int ball, ins;
    scanf(" %d %d", &ball, &ins);
    ball_sort(ball, ins);

    return 0;
}

void ball_sort(int ball_count, int ins_count){
    int * balls = (int *) malloc(ball_count * sizeof(int));
    int * tmp = (int *) malloc(ball_count * sizeof(int));
    for(int count = 0; count < ball_count; count++){
        *(balls + count) = count + 1;
    }
    int ins, src, dst;
    for(int current = 0; current < ins_count; current++){
        scanf(" %d %d %d", &ins, &src, &dst);
        switch(ins){
            case SWAP_TO_LEFT:
                if(src < dst){
                    int count;
                    for(count = 0; count < src - 1; count++){
                        *(tmp + count) = *(balls + count);
                    }
                    for(; count < dst - 2; count++){
                        *(tmp + count) = *(balls + count + 1);
                    }
                    *(tmp + count++) = *(balls + src - 1);
                    *(tmp + count++) = *(balls + dst - 1);
                    for(; count < ball_count; count++){
                        *(tmp + count) = *(balls + count);
                    }
                } else {
                    int count;
                    for(count = 0; count < dst - 1; count++){
                        *(tmp + count) = *(balls + count);
                    }
                    *(tmp + count++) = *(balls + src - 1);
                    *(tmp + count++) = *(balls + dst - 1);
                    for(count--; count < src - 1; count++){
                        *(tmp + count + 1) = *(balls + count);
                    }
                    for(count++; count < ball_count; count++){
                        *(tmp + count) = *(balls + count);
                    }
                }
                copy(tmp, balls, ball_count);
                break;
            case SWAP_TO_RIGHT:
                if(src < dst){
                    int count;
                    for(count = 0; count < src - 1; count++){
                        *(tmp + count) = *(balls + count);
                    }
                    for(; count < dst - 2; count++){
                        *(tmp + count) = *(balls + count + 1);
                    }
                    *(tmp + count++) = *(balls + dst - 1);
                    *(tmp + count++) = *(balls + src - 1);
                    for(; count < ball_count; count++){
                        *(tmp + count) = *(balls + count);
                    }
                } else {
                    int count;
                    for(count = 0; count < dst - 1; count++){
                        *(tmp + count) = *(balls + count);
                    }
                    *(tmp + count++) = *(balls + dst - 1);
                    *(tmp + count++) = *(balls + src - 1);
                    for(count--; count < src - 1; count++){
                        *(tmp + count + 1) = *(balls + count);
                    }
                    for(count++; count < ball_count; count++){
                        *(tmp + count) = *(balls + count);
                    }
                }
                copy(tmp, balls, ball_count);
                break;
        }
        
    }
    for(int count = 0; count < ball_count; count++){
        printf("%d ", *(balls + count));
    }
    putchar('\n');
}

void copy(int * src, int * dst, int length){
    for(int count = 0; count < length; count++){
        *(dst + count) = *(src + count);
    }
}