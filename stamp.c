#include <stdio.h>
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
    if((copy / 2) - (int) pow(2, dimension) + 1 <= 0){
        half[0] = 0;
        half[1] = 0;
    } else {
        half[0] = copy / 2 - (long long) pow(2, dimension) + 1;
        half[1] = copy / 2 + 1 + (long long) pow(2, dimension) - 1;
    }
    
    long long limit = max > (cash / 2 + 1) ? (cash / 2 + 1) : max;
    for(long long count = 2; count < limit; count++){
        if((cash % count) == 0){
            long long less = count;
            long long bigger = cash / count;
            if(bigger % 2 == 0){
                continue;
            } else {
                long long former = less - bigger / 2;
                long long latter = less + bigger / 2;
                if(former <= 0){
                    continue;
                } else {
                    if(half[0] && !has_shown && former > half[0]){
                        printf("[%d,%d]\n", half[0], half[1]);
                        has_shown = 1;
                    }
                    printf("[%d,%d]\n", former, latter);
                }
            }
        }
    }

    if(!has_shown){
        printf("[%d,%d]\n", half[0], half[1]);
    }

    if(cash <= max){
        printf("[%d,%d]\n", cash, cash);
    }
}