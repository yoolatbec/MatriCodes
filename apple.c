#include <stdio.h>

int main(){
    int apple_height[10];
    int height;
    for(int count = 0; count < 10; count++){
        scanf("%d", &apple_height[count]);
    }
    scanf("%d", &height);
    int total = 0;
    for(int count = 0; count < 10; count++){
        if(*(apple_height + count) < height + 30){
            total++;
        }
    }
    printf("%d\n", total);
}