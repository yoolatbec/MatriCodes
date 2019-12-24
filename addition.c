#include <stdio.h>
#include <stdlib.h>

void addition(char *, char *);
void copy(char *, char *, int);
void add(char *, char *, int, int);

int main(){
    char a[100], b[100];
    scanf("%s", a);
    scanf("%s", b);
    addition(a, b);

    return 0;
}

void addition(char * a, char * b){
    int length_a = 1, length_b = 1;
    char * result;

    for(int count = 0; a[count] != '\0'; count++){
        length_a++;
    }
    for(int count = 0; b[count] != '\0'; count++){
        length_b++;
    }

    length_a > length_b ? (result = (char *) malloc((length_a + 1) * sizeof(char))) : (result = (char *) malloc((length_b + 1) * sizeof(char)));

    if(length_a > length_b){
        *result = '0';
        copy(result, a, length_a);
        add(result, b, length_a, length_b);
        for(int count = length_a; count > 0; count--){
            if(*(result + count) > '9'){
                *(result + count) -= 10;
                *(result + count - 1) += 1;
            }
        }
    } else {
        *result = '0';
        copy(result, b, length_b);
        add(result, a, length_b, length_a);
        for(int count = length_b; count > 0; count--){
            if(*(result + count) > '9'){
                *(result + count) -= 10;
                *(result + count - 1) += 1;
            }
        }
    }

    if(result[0] != '0'){
        printf("%s", result);
    } else {
        printf("%s", (result + 1));
    }

    free(result);
}

void copy(char * target, char * origin, int length){
    for(int count = 0; count < length; count++){
        *(target + count + 1) = *(origin + count);
    }
}

void add(char * target, char * origin, int length_a, int length_b){
    for(int count = 1; count < length_b; count++){
            *(target + length_a - count) += *(origin + length_b - 1 - count) - '0';
            if(*(target + length_a - count) > '9'){
                *(target + length_a - count) -= 10;
                *(target + length_a - count - 1) += 1;
            }
        }
}