#include <stdio.h>

void put(void);

int main(){
    put();
    putchar('\n');

    return 0;
}

void put(){
    char ch = getchar();
    if(ch == '\n'){
        return;
    }
    put();
    putchar(ch);
    return;
}