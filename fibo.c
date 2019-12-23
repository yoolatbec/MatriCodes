#include <stdio.h>

int fibonacci(int);

int main(){
    int index;
    scanf("%d", &index);
    printf("%d", fibonacci(index));

    return 0;
}

int fibonacci(int index){
    if(index == 1){
        return 1;
    }
    if(index == 2){
        return 3;
    }

    return 1 + fibonacci(index - 1) + fibonacci(index - 2);
}