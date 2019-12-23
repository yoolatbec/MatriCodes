#include <stdio.h>
#include <stdlib.h>

void output(int n);

int main(){
    int time;
    scanf("%d", &time);
    for(int count = 0; count < time; count++){
        int n; 
        scanf("%d", &n);
        output(n);
    }

    return 0;
}

void output(int n){
    int * input = (int *) malloc(n * sizeof(int));
    int * store = (int *) malloc(n * sizeof(int));
    int total = 1;

    for(int count = 0; count < n; count++){
        scanf("%d", (input + count));
        *(store + count) = 0;
    }
    *store = *input;
    for(int count = 1; count < n; count++){
        int current = *(input + count);
        int same = 0;
        for(int in = 0; in < total; in++){
            if(*(input + count) == *(store + in)){
                same = 1;
                break;
            }
        }
        if(!same){
            *(store + total) = current;
            total++;
        }
    }

    free(input);
    free(store);
    printf("%d\n", total);
}