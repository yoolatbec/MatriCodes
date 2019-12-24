#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char bad_words[10][51];
char input[50][51];
char * output;

void decode(int , int);
void alter(int);
int compare(char *, char *);

int main(){
    int height, width;
    scanf("%d%d", &height, &width);
    output = (char *) malloc((height * width + 1) * sizeof(char));
    for(int count = 0; count < height; count++){
        scanf("%s", input[count]);
    }
    *(output + height * width) = '\0';
    int time;
    scanf("%d", &time);
    getchar();
    for(int count = 0; count < time; count++){
        scanf("%s", bad_words[count]);
    }
    decode(height, width);
    alter(time);
    printf("%s", output);

    return 0;
}

void decode(int height, int width){
    int orientation = 0;
    int fold = 1; 
    int layer = fold / 2;
    int currentx = 0;
    int currenty = -1;
    int len = 0;
    for(int total = 0; total < width * height; total++){
        switch(orientation){
            case 0:
            case 2:
            if(len == height - layer){
                orientation++;
                len = 0;
                fold++;
                layer = fold / 2;
            }
            break;
            case 1:
            if(len == width - layer){
                orientation++;
                len = 0;
                fold++;
                layer = fold / 2;
            }
            break;
            case 3:
            if(len == width - layer){
                orientation = 0;
                len = 0; 
                fold++;
                layer = fold / 2;
            }
            break;
        }
        switch(orientation){
            case 0:
                currenty++;
                break;
            case 1:
                currentx++;
                break;
            case 2:
                currenty--;
                break;
            case 3:
                currentx--;
                break;
        }
        *(output + total) = input[currenty][currentx];
        len++;
    }
    printf("%s\n", output);
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