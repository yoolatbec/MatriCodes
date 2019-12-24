#include <stdio.h>

int compare(long long, long long, long long, long long);

int main(){
    long long a, b, c, d;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    int result = compare(a, b, c, d);
    printf("%d\n", result);

    return 0;
}

int compare(long long a, long long b, long long c, long long d){
    long long result = a * d - b * c;
    if(result != 0L){
        if(result > 0){
            return 1;
        } else {
            return -1;
        }
    } else{
        return 0;
    }
}