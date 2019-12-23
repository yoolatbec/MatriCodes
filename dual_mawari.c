#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void find_mawari(long long);
int justidge(long long, int);

int main(){
    int time;
    scanf("%d", &time);
    for(int count = 0; count < time; count++){
        int input;
        scanf(" %d", &input);
        find_mawari(input);
    }

    return 0;
}

void find_mawari(long long min){
    int flag1 = false, flag2 = false;
    while(!flag2){
        min++;
        flag1 = false;
        flag2 = false;
        for(int count = 2; count <= 10; count++){
            flag1 ? (flag2 = justidge(min, count)) : (flag1 = justidge(min, count));
            if(flag2){
                break;
            }
        }
    }
    printf("%d\n", min);
}

int justidge(long long num, int base){
    int len = 1;
    int copy = num;
    while((copy /= base) != 0){
        len++;
    }
    char * content = (char *) malloc(len * sizeof(char));
    copy = num;
    for(int count = 0; count < len; count++){
        *(content + count) = (char)('0' + copy % base);
        copy /= base;
    }
    int mawari = true;
    if(*(content + 0) == '0'){
        free(content);
        return 0;
    }
    for(int count = 0; count < len / 2; count++){
        if(*(content + count) != *(content + len - 1 - count)){
            mawari = false;
        }
    }
    free(content);
    return mawari;
}