#include <stdio.h>
#include <stdlib.h>

int main(){
    int count;
    int * score;
    int highest_score;

    scanf("%d", &count);
    score = malloc(count * sizeof(int));
    for(int c = 0; c < count; c++){
        scanf("%d", score + c);
    }
    highest_score = *score;
    for(int c = 1; c < count; c++){
        if(highest_score < * (score + c)){
            highest_score = * (score + c);
        }
    }

    printf("%d", highest_score);
    free(score);

    return 0;
}