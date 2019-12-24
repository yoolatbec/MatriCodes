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
    long long origin = cash * 2;
    long long limit = max > ((long long ) sqrt(((double)(origin)))) ? ((long long)sqrt((double)(origin))) : max;
    for(long long count = limit; count > 1; count--){
        if(origin % count == 0){
            long long less = count;
            long long bigger = origin / count;
            if((bigger % 2 == 0) && (less % 2 != 0)){
                long long a = bigger / 2 - less / 2;
                long long b = bigger / 2 + less / 2;
                if(a > 0){
                    printf("[%d,%d]\n", a, b);
                }
            } else if((bigger % 2 != 0) && (less % 2 == 0)){
                long long a = bigger / 2 - less / 2 + 1;
                long long b = bigger / 2 + less / 2;
                if(a > 0){
                    printf("[%d,%d]\n", a, b);
                }
            }
        }
    }
    if(max >= cash){
        printf("[%d,%d]\n", cash, cash);
    }
}