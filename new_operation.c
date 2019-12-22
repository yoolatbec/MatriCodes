#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define OPERATION_1 1
#define OPERATION_2 2
#define OPERATION_3 3

void operate(int , int);

int main(){
    int num_count, ope_count;
    scanf("%d %d", &num_count, &ope_count);
    operate(num_count, ope_count);

    return 0;
}

void operate(int num_count, int ope_count){
    long long * nums = (long long *) malloc(num_count * sizeof(long long));
    for(int count = 0; count < num_count; count++){
        scanf(" %lld", (nums + count));
    }
    int operation;
    long long accumulation = 0;
    int neg = 1;
    int last_operation;
    for(int count = 0; count < ope_count; count++){
        scanf(" %d", &operation);
        long long input;
        int left, right;
        switch(operation){
            case OPERATION_1:
                neg *= -1;
                accumulation *= -1;
                break;
            case OPERATION_2:
                scanf(" %lld", &input);
                accumulation += input;
                break;
            case OPERATION_3:
                scanf(" %d %d", &left, &right);
                long long result = 0;
                for(int c = left - 1; c <= right - 1; c++){
                    result += (*(nums + c) * neg + accumulation);
                }              
                printf("%lld\n", result);
                break;
        }
        last_operation = operation;
    }
    free(nums);
}
