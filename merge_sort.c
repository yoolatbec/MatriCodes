#include <stdio.h>
#include <stdlib.h>

void sort(int *, int *, int);
void merge_sort(int num_count);
void print_nums(int *, int);

int num_length = 0;
int * nums = 0;

int main(){
    int input;
    scanf("%d", &input);
    merge_sort(input);

    return 0;
}

void merge_sort(int num_count){
    num_length = num_count;
    nums = (int *) malloc(num_count * sizeof(int));
    for(int count = 0; count < num_count; count++){
        scanf(" %d", (nums + count));
    }
    sort(nums, (nums + num_length - 1), num_length);
}

void sort(int * start, int * end, int length){
   if(start == end){
       return;
   }
   int former_len, latter_len;
   latter_len = length / 2;
   former_len = length - latter_len;
//    printf("%d %d\n", former_len, latter_len);
//    print_nums(start, former_len);
//    print_nums((start + former_len), latter_len);
   sort((start + former_len), end, latter_len);
   sort(start, (start + former_len - 1), former_len);
   int * result = (int *) malloc(length * sizeof(int));
   int * former_current = start;
   int * latter_current = start + former_len;
   int former_count = former_len, latter_count = latter_len;
   for(int count = 0; count < length; count++){
       if(former_count > 0 && (*latter_current >= *former_current)){
           *(result + count) = *former_current;
           former_count--;
           former_current++;
       }
       if(latter_count > 0 && (*former_current >= *latter_current)){
           *(result + count) = *latter_current;
           latter_current++;
           latter_count--;
       }
   }
   for(int count = 0; count < length; count++){
       *(start + count) = *(result + count);
   }
   print_nums(result, length);
   return;
}

void print_nums(int * start, int length){
    for(int count = 0; count < length; count++){
        if(count != length - 1){
            printf("%d ", *(start + count));
        } else {
            printf("%d\n", *(start + count));
        }
    }
}