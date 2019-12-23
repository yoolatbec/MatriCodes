#include <stdio.h>

void decode(char *);
int getNum(char *);

int main(){
    char input[105];
    scanf("%s", input);
    decode(input);

    return 0;
}

void decode(char * input){
    int current = 0;
    int skip = 1;
    while(*(input + current) != '\0'){
        if(*(input + current) <= '9' && *(input + current) >= '0'){
            int time = getNum(input + current);
            if(time <= 7){
                for(int count = 1; count < time; count++){
                    putchar(*(input + current - 1));
                }
            } else {
                int real_time = time % 7;
                for(int count = 0; count < real_time; count++){
                    putchar(*(input + current - 1));
                }
            }
            while(time / 10 != 0){
                skip++;
                time /= 10;
            }
        } else {
            putchar(*(input + current));
        }
        current += skip;
        skip = 1;
    }
}

int getNum(char * section){
    int result = 0;
    int current = 0;
    while(*(section + current) >= '0' && *(section + current) <= '9'){
        result = result * 10 + *(section + current) - '0';
        current++;
    }
    return result;
}