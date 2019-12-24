#include <stdio.h>

char bads[10][51];

int main(){
    int time;
    scanf("%d", &time);
    getchar();
    for(int count = 0; count < time; count++){
        scanf("%s", bads[count]);
    }
    for(int count = 0; count < time; count++){
        printf("%s", bads[count]);
    }

    return 0;
}

void decode(char * input, int height, int width, int words){
    char * output = (char *) malloc ((width * height + 1) * sizeof(char));
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
        *(output + total) = *(input + currenty * width + currentx);
        len++;
    }
    *(output + width * height) = '\0';
    printf("%s", output);
    alter(output, words);
    free(output);
}

void alter(char * origin, int count){
    int current = 0;
    while(*(origin + current) != '\0'){
        for(int c = 0; c < count; c++){
            int flag = compare(origin + current, bads[c]);
            if(flag){
                for(int in = 1; in < strlen(bads[c]); in++){
                    current++;
                    *(origin + current) = '*';
                }
                break;
            }
        }
    }
}