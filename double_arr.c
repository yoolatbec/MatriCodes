#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD

void gen_tree(int);
=======
#include <math.h>
>>>>>>> fbb65119a9f53a9424f4b02b81ee83084ec687d8

void gen_tree(int);

int main(){
    int total;
    scanf(" %d", &total);
    gen_tree(total);

    return 0;
}

void gen_tree(int node_count){
<<<<<<< HEAD
    int * node = (int *) malloc(node_count * sizeof(int));
=======
    long long length = (int)pow(2, node_count);
    int * nodes = (int *) malloc(length * sizeof(int));
>>>>>>> fbb65119a9f53a9424f4b02b81ee83084ec687d8
    int * tmp = (int *) malloc(node_count * sizeof(int));
    for(int count = 0; count < node_count; count++){
        scanf(" %d", (tmp + count));
    }
<<<<<<< HEAD
    
=======
    for(int count = 0; count < length; count++){
        *(nodes + count) = -1;
    }
    for(int count = 0; count < node_count; count++){
        int i = 0;
        while(*(nodes + i) != -1){
            if(*(tmp + count) > *(nodes + i)){
                i = i * 2 + 2;
            } else {
                i = i * 2 + 1;
            }
        }
         *(nodes + i) = *(tmp + count);
    }
    for(int count = 0; count < length; count++){
        if(*(nodes + count) != -1){            
            printf("%d\n", *(nodes + count));
        }
    }
    free(nodes);
    free(tmp);
>>>>>>> fbb65119a9f53a9424f4b02b81ee83084ec687d8
}