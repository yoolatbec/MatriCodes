#include <stdio.h>
#include <stdlib.h>

void print_grades(int student, int test);

int main(){
    int time;
    scanf("%d", &time);
    for(int count = 0; count < time; count++){
        int student; 
        scanf(" %d", &student);
        print_grades(student, count + 1);
    }

    return 0;
}

void print_grades(int student, int test){
    char * grades = (char *) malloc((student + 1) * 10 * sizeof(char));
    for(int count = 0; count < (student + 1) * 10; count++){
        char ch;
        while((ch = getchar()) == ' ' || ch == '\n'){
            continue;
        }
        *(grades + count) = ch;
    }
    char * answer = (grades + student * 10);
    char * scores = (char *) malloc(student * sizeof(char));
    for(int s = 0; s < student; s++){
        int score = 0;
        for(int count = 0; count < 10; count++){
            if(*(answer + count) == *(grades + s * 10 + count))
                score++;
        }
        *(scores + s) = score;
    }
    int time = 0;
    printf("test case %d:\n", test);
    while(time < student){
        int pos = 0;
        int min = *(scores + pos);
        for(int count = 0; count < student; count++){
            if(*(scores + count) < min){
                pos = count;
                min = *(scores + count);
            }
        }
        printf("Student %d: %d\n", pos, min);
        *(scores + pos) = 11;
        time++;
    }
}