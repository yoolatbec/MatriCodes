#include <stdio.h>
#include <math.h>

void printNum(char* origin, int base);

int main(){
    int time;
    char input[10];
    int base;
    scanf("%d", &time);
    scanf("%d", &base);
    for(int count = 0; count < time; count++){
        scanf("%s", input);
        printNum(input, base);
    }

    return 0;
}

void printNum(char * origin, int base){
    int length = 0;
    while(origin[length] != '\0'){
        length++;
    }
    int result = 0;
    for(int count = 0; count < length; count++){
        result += (int) pow(base, length - count - 1) * (origin[count] - '0');
    }
    printf("%d ", result);

    int result_reverse = 0;
    for(int count = length - 1; count >= 0; count--){
        result_reverse += (int) pow(base, count) * (origin[count] - '0');
    }
    printf("%d\n", result_reverse);
}