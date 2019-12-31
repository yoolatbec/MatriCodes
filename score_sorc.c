#include <stdio.h>
#include <stdlib.h>

typedef struct score{
    int id;
    char name[11];
    int score;
} Score;

int compare(Score *, Score *);
void input(Score *);

int main(){
    int total;
    scanf("%d", &total);
    Score* scores = (Score*) malloc (total * sizeof(Score));
    for(int count = 0; count < total; count++){
        input(scores + count);
    }
    for(int count = 0; count < total - 1; count++){
        for(int in = 0; in < total - 1; in++){
            compare(scores + in, scores + in + 1);
        }
    }
    for(int count = 0; count < total; count++){
        printf("%d %s %d\n", (scores + count) -> id, (scores + count) -> name, (scores + count) -> score);
    }

    free(scores);

    return 0;
}

void input(Score* score){
    scanf(" %d", &(score -> id));
    scanf("%s", score -> name);
    scanf(" %d", &(score -> score));
}

int compare(Score* former, Score* latter){
    if(former -> score < latter -> score || ((former -> score == latter -> score) && (former -> id > latter -> id))){
        Score * new = (Score *) malloc (sizeof(Score));
        new -> id = former -> id;
        new -> score = former -> score;
        for(int count = 0; count < 11; count++){
            (new -> name)[count] = (former -> name)[count];
        }
        former -> id = latter -> id;
        former -> score = latter -> score;
        for(int count = 0; count < 11; count++){
            (former -> name)[count] = (latter -> name)[count];
        }
        latter -> id = new -> id;
        latter -> score = new -> score;
        for(int count = 0; count < 11; count++){
            (latter -> name)[count] = (new -> name)[count];
        }

        free(new);
        return 1;
    }
    return 0;
}