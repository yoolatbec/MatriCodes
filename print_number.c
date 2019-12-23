#include <stdio.h>
#include <math.h>

void print(int input);

int main(){
    int input;
    scanf("%d", &input);
    print(input);

    return 0;
}

void print(int input){
    int current_line = 1;
    for(int count = 0; count < input; count++){
        for(int c = 0; c < (input - current_line) * 5; c++){
            putchar(' ');
        }
        for(int current = 0; current < current_line; current++){
            printf("%5d", (int) pow(2, current));
        }
        for(int current = current_line - 1; current > 0; current--){
            printf("%5d", (int) pow(2, current - 1));
        }
        for(int c = 0; c < (input - current_line) * 6; c++){
            putchar(' ');
        }
        putchar('\n');
        current_line++;
    }
}