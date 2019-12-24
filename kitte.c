#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void find(long long, long long);

int main(){
    long long max, cash;
    scanf("%lld%lld", &max, &cash);
    find(max, cash);

    return 0;
}

void find(long long max, long long cash){
    int dimension = 0;
    int copy = cash;
    int half[2];
    int has_shown = 0;
    while((copy % 2) == 0){
        copy /= 2;
        dimension++;
    }
    if((copy / 2) - dimension <= 0){
        half[0] = 0;
        half[1] = 0;
    } else {
        half[0] = copy / 2 - (int) pow(2, dimension) + 1;
        half[1] = copy / 2 + 1 + (int ) pow(2, dimension) - 1;
    }
    
    long long limit = max < (cash / 2 + 1) ? max : (cash / 2 + 1);
    long long length = 0;
    for(long long count = 2; count < limit; count++){
        if((cash % count) == 0){
            length++;
        }
    }
    long long * factors = (long long *) malloc(length * 2 * sizeof(long long));
    long long current = 0;
    for(long long count = 2; count < limit; count++){
        if((cash % count) == 0){
            *(factors + current) = count;
            *(factors + length * 2 - 1 - current) = cash / count;
            current++;
        }
    }
    for(long long count = 0; count < length; count++){
        if(*(factors + 2 * length - 1 - count) % 2 == 0){
            continue;
        }
        long long less = *(factors + count) - *(factors + 2 * length - 1 - count) / 2;
        long long bigger = *(factors + count) + *(factors + 2 * length - 1 - count) / 2;
        if(less <= 0){
            continue;
        }
        if(less > half[0] && !has_shown &&(half[0] != 0)){
            printf("[%d,%d]\n", half[0], half[1]);
            has_shown = 1;
        }
        printf("[%d,%d]\n", less, bigger);
    }

    if(cash <= max){
        printf("[%d,%d]\n", cash, cash);
    }

    free(factors);
}