#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char bad_words[10][51];
char input[50][51];
char * output;

int compare(char*, char *);
void alter(int);

int main(){
    int time;
    scanf("%d", &time);
    getchar();
    for(int count = 0; count < time; count++){
        scanf("%s", bad_words[count]);
    }
    output = (char *) malloc (50 * sizeof(char));
    scanf("%s", output);
    alter(time);
    printf("%s", output);

    return 0;
}

void alter(int word_count){
    int current = 0;
    while(*(output + current) != '\0'){
        for(int count = 0; count < word_count; count++){
            if(compare((output + current), bad_words[count])){
                int len = strlen(bad_words[count]);
                for(int c = 1; c < len; c++){
                    current++;
                    *(output + current) = '*';
                }
            }
        }
        current++;
    }
}

int compare(char * origin, char * to_compare){
    int len = strlen(to_compare);
    int is_same = 1;
    for(int count = 0; count < len; count++){
        if(*(origin + count) != *(to_compare + count)){
            is_same = 0;
            break;
        }
    }
    return is_same;
}