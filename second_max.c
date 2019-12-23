#include <stdio.h>
#include <stdlib.h>

int get_second_max(int count);

int main(){
    int time;
    scanf("%d", &time);
    int * result = (int *)malloc(time * sizeof(int));
    for(int count = 0; count < time; count++){
        int c;
        scanf("%d", &c);
        result[count] = get_second_max(c);
    }
    for(int count = 0; count < time; count++){
        printf("%d", result[count]);
        if(count != time - 1){
            printf("\n");
        }
    }

    free(result);

    return 0;
}

int get_second_max(int count){
    int max = 0;
    int second = 0;
    int input;
    scanf("%d%d", &max, &second);
    if(max < second){
        int tmp = second;
        second = max;
        max = tmp;
    }
    for(int rest = count - 2; rest > 0; rest--){
        scanf("%d", &input);
        if(input >= max){
            second = max;
            max = input;
        } else {
            if(input >= second){
                second = input;
            }
        }
    }
    return second;
}