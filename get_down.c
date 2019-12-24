#include <stdio.h>

int get_down(int, int);

int main(){
    int h, s;
    scanf(" %d %d", &h, &s);
    printf("%d\n", get_down(h, s));

    return 0;
}

int get_down(int h, int s){
    if(h <= 0){
        return 1;
    }
    int count = 0;
    for(int step = 1; step <= s; step++){
        if(step > h)
            break;
        count += get_down(h - step, s);
    }
    return count;
}