#include <stdio.h>

int main(){
    int sum, count, p_count, n_count, current;
    count = 0;
    sum = 0;
    p_count = 0;
    n_count = 0;
    float average = 0;
    scanf("%d", &current);
    while(current){
        if(current < 0){
            n_count++;
        } else {
            p_count++;
        }
        sum += current;
        count++;
        scanf("%d", &current);
    }
    if(count){
        average = (sum + 0.0) / count;
    } else {
        average = 0.0;
    }
    printf("%d %d %d %.2f", p_count, n_count, sum, average);

    return 0;
}