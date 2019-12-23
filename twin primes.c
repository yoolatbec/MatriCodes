#include <stdio.h>
#include <stdbool.h>

int judge(int input);
int find_all(int input);

int main(){
    int input;
    scanf("%d", &input);
    int result = find_all(input);
    printf("%d", result);

    return 0;
}

int judge(int input){
    int is_primer = true;
    int half = input / 2 + 1;
    for(int count = 2; count < half; count++){
        if((input % count) == 0){
            is_primer = false;
            return is_primer;
        }
    }
    return is_primer;
}

int find_all(int input){
    int total = 0;
    int flag1 = false;
    int flag2 = false;
    for(int count = 3; count < input - 2; count += 2){
        flag1 = judge(count);
        flag2 = judge(count + 2);
        if(flag1 && flag2){
            total++;
        }
    }
    return total;
}