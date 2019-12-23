#include <stdio.h>

int get_number(int);

int main(){
    int input;
    int result;
    while(scanf("%d", &input) != EOF){
        result = get_number(input);
        printf("%d\n", result);
    }

    return 0;
}

int get_number(int position){
    int former = 1;
    int latter = 1;
    if(position == 1 || position == 2){
        return 1;
    }
    for(int count = 2; count < position; count++){
        int tmp = latter;
        latter = former;
        former += tmp;
    }
    return former;
}