#include <stdio.h>

void getInput();
void paint(int *, int);

int main(){
    getInput();

    return 0;
}

void getInput(){
    int chars[26];
    int word = 1;
    for(int count = 0; count < 26; count++){
        chars[count] = 0;
    }
    char in;
    char last = ' ';
    while((in = getchar()) != EOF){
        if(in != ' ' && in != '\n'){
            chars[in - 'a']++;
        } else if(in == ' ' || in == '\n'){
            if(last != ' ' && last != '\n'){
                word++;
            }
        }
        last = in;
    }

    if(last == ' ' || last == '\n'){
        word--;
    }
    
    paint(chars, word);
}

void paint(int * inputs, int word){
    int max = word;
    for(int count = 0; count < 26; count++){
        max = max > *(inputs + count) ? max : *(inputs + count);
    }
    for(int count = max; count > 0; count--){
        printf("%d\t", count);
        for(int c = 0; c < 26; c++){
            if(*(inputs + c) >= count){
                putchar('*');
            } else if(*(inputs + c) > 0){
                putchar(' ');
            }
        }
        if(word >= count){
            putchar('*');
        } else {
            putchar(' ');
        }
        putchar('\n');
    }
    printf(" \t");
    for(int count = 0; count < 26; count++){
        if(*(inputs + count) > 0){
            putchar('a' + count);
        }
    }
    putchar('W');
}