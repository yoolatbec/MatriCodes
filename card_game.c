#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_max_num(int);

int main(){
    int count;
    scanf("%d", &count);
    print_max_num(count);

    return 0;
}

void print_max_num(int count){
    int zero_exist = false;
    int total = 0;
    int * nums = (int *) malloc(10 * sizeof(int));
    for(int c = 0; c < 10; c++){
        *(nums + c) = 0;
    }
    int input;
    for(int c = 0; c < count; c++){
        scanf(" %d", &input);
        if(input == 0){
            zero_exist = true;
        }
        total += input;
        *(nums + input) += 1;
    }
    if(zero_exist && total && (total % 3 == 0)){
        for(int c = 9; c >= 0; c--){
            for(int in = 0; in < *(nums + c); in++){
                putchar('0' + c);
            }
        }
        putchar('\n');
    } else {
        puts("no such number");
    }
    free(nums);
}