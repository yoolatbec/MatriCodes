#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_sort(void);

int main(){
    string_sort();

    return 0;
}

void string_sort(){
    int time;
    scanf("%d", &time);

    char* strings = (char*) malloc(time * 105 * sizeof(char));
    char ** sorted = (char **) malloc (time * sizeof(char *));

    for(int count = 0; count < time; count++){
        scanf("%s", (strings + count * 105));
        sorted[count] = (strings + count * 105);
    }

    for(int out = 0; out < time - 1; out++){
        for(int in = 0; in < time - 1 - out; in++){
            if(strcmp(sorted[in], sorted[in + 1]) > 0){
                char * tmp = sorted[in];
                sorted[in] = sorted[in + 1];
                sorted[in + 1] = tmp;
            }
        }
    }
    for(int count = 0; count < time; count++){
        printf("%s\n", sorted[count]);
    }

    free(sorted);
    free(strings);
}