#include <stdio.h>
#include <stdlib.h>

void gen_tree(int);

int main(){


    return 0;
}

void gen_tree(int node_count){
    int * node = (int *) malloc(node_count * sizeof(int));
    int * tmp = (int *) malloc(node_count * sizeof(int));
    for(int count = 0; count < node_count; count++){
        scanf(" %d", (tmp + count));
    }
    
}