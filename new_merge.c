#include <stdio.h>
#include <stdlib.h>

void print_nums(int *, int);
void sort(int *, int start, int end);

int * nums = 0; 
int length = 0;

int main(){
    int total;
    scanf(" %d", &total);
    length = total;
    nums = (int *) malloc(length * sizeof(int));
    for(int count = 0; count < length; count++){
        scanf(" %d", (nums + count));
    }
    sort(nums, 0, length - 1);

    return 0;
}

void sort(int * nums, int start, int end){
    if(start == end){
        return;
    }
    int len = end - start + 1;
    int * result = (int *) malloc(len * sizeof(int));
    int latter_start = (start + end) / 2 + 1;
    sort(nums, start, (start + end) / 2);
    sort(nums, (start + end) / 2 + 1, end);
    int former_current = start, latter_current = latter_start, current = 0;
    while(former_current < latter_start && latter_start <= end){
        if(nums[former_current] <= nums[latter_current]){
            result[current++] = nums[former_current++];
        } else {
            result[current++] = nums[latter_current++];
        }
    }
    while(former_current < latter_start){
        result[current++] = nums[former_current++];
    }
    while(latter_current <= end){
        result[current++] = nums[latter_current++];
    }
    current = 0;
    for(int count = start; count <= end; count++){
        nums[count] = result[current++];
    }
    print_nums(nums, length);
}

void print_nums(int * nums, int length){
    for(int count = 0; count < length; count++){
        if(count != length - 1){
            printf("%d ", *(nums + count));
        } else {
            printf("%d\n", *(nums + count));
        }
    }
}