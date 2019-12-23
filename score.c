#include <stdio.h>

int main(){
    int score;
    scanf("%d", &score);
    if(score > 100 || score < 0){
        printf("Invalid");
    } else {
        if(score < 60){
            printf("Failed");
        } else {
            float result = (score - 50) / 10.0;
            printf("%.1f", result);
        }
    }

    return 0;
}