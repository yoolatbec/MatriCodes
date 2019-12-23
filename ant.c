#include <stdio.h>
#include <stdlib.h>

int get_max(int, int);

int main(){
    int count, length;
    scanf("%d%d", &count, &length);
    int result = get_max(count, length);
    printf("%d", result);

    return 0;
}

int get_max(int count, int length){
    int max = 0;
    char * orientation = (char *) malloc(count * sizeof(char));
    int * distance = (int *) malloc(count * sizeof(int));
    for(int c = 0; c < count; c++){
        scanf("%c", &orientation[c]);
        if(orientation[c] != 'R' && orientation[c] != 'L'){
            scanf("%c", &orientation[c]);
        }
        scanf("%d", &distance[c]);
    }
    for(int c = 0; c < count; c++){
        switch(orientation[c]){
            case 'R':
                distance[c] = length - distance[c];
                break;
            case 'L':
                break;
        }
    }
    for(int c = 0; c < count; c++){
        if(max <= distance[c]){
            max = distance[c];
        }
    }

    free(orientation);
    free(distance);
    return max;
}