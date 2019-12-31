#include <stdio.h>

int main(){
    int input, total = 0;
    while(1){
        scanf(" %d", &input);
        total += input;
        printf(" %d\n", total);
    }
    
    return 0;
}