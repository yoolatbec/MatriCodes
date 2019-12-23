#include <stdio.h>
#include <stdlib.h>

char * sortString(const char *);

int main(){
    char str[50];
    scanf("%s", str);
    char * re = sortString(str);
    printf("%s", re);

    return 0;
}

char * sortString(const char * input){
    int len = 1;
    const char * current = input;
    int * counts = (int *) malloc(52 * sizeof(int));
    for(int c = 0; c < 52; c++){
        *(counts + c) = 0;
    }
    while(*current != '\0'){
        len++;
        if(*current >= 'a' && *current <= 'z'){
            *(counts + 26 + (*current - 'a')) += 1;
        }else{
            *(counts + (*current - 'A')) += 1;
        }
        current++;
    }
    char * result = (char *) malloc(len * sizeof(char));
    char * new_current = result;
    for(int c = 0; c < 52; c++){
        if(c < 26){
            for(int c1 = 0; c1 < *(counts + c); c1++){
                *new_current = 'A' + c;
                new_current++;
            }
        } else {
            for(int c1 = 0; c1 < *(counts + c); c1++){
                *new_current = 'a' + c - 26;
                new_current++;
            }
        }
    }
    *(result + len - 1) = '\0';
    return result;
}