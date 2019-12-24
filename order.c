#include <stdio.h>
#include <stdlib.h>

void sort(int *, int ,int );
void bubbleExchange(int *, int, int);
void copy(int *, int *, int);


int main(){
    int d; 
    scanf("%d", &d);
    int * arr = (int *) malloc(d * sizeof(int));
    for(int count = 1; count <= d; count++){
        *(arr + count - 1) = count;
    }
    sort(arr, 0, d);
    free(arr);

    return 0;
}

void sort(int * origin, int start, int length){
    if(start == length - 1){
        for(int count = 0; count < length; count++){
            printf("%d ", *(origin + count));
        }
        putchar('\n');
        return;
    }
    for(int count = start; count < length; count++){
        int * arr = (int *) malloc(length * sizeof(int));
        copy(origin, arr, length);
        bubbleExchange(arr, start, count);
        sort(arr, start + 1, length);
        free(arr);
    }
}

void bubbleExchange(int * origin, int former, int latter){
    for(int count = latter; count > former; count--){
        int tmp = *(origin + count);
        *(origin + count) = *(origin + count - 1);
        *(origin + count - 1) = tmp;
    }
}

void copy(int * origin, int * target, int length){
    for(int count = 0; count < length; count++){
        *(target + count) = *(origin + count);
    }
}