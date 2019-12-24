#include <stdlib.h>
#include <stdio.h>

int * nums = 0;
int nums_len = 0;

void merge(int *, int , int, int *);
void print_nums(int *, int);

int main(){
    int total;
    scanf(" %d", &total);
    nums_len = total;
    nums = (int *) malloc(nums_len * sizeof(int));
    int * tmp = (int *) malloc(nums_len * sizeof(int));
    for(int count = 0; count < nums_len; count++){
        scanf(" %d", (nums + count));
    }
    merge(nums, 0, nums_len - 1, tmp);
    free(tmp);
    free(nums);
    nums = 0;

    return 0;
}

void merge(int * source, int start, int end, int * tmp){
    if(start >= end){
        return;
    }
    int mid = (start + end) / 2;
    merge(source, start, mid, tmp);
    merge(source, mid + 1, end, tmp);
    int former_current = start;
    int latter_current = mid + 1;
    int current = 0;
    while(former_current <= mid && latter_current <= end){
        if(source[former_current] <= source[latter_current]){
            tmp[current++] = source[former_current++];
        } else {
            tmp[current++] = source[latter_current++];
        }
    }
    while(former_current <= mid){
        tmp[current++] = source[former_current++];
    }
    while(latter_current <= end){
        tmp[current++] = source[latter_current++];
    }
    for(int count = start; count <= end; count++){
        source[count] = tmp[count - start];
    }
    print_nums(nums, nums_len);
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