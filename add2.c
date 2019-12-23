#include <stdio.h>

double m(int);

int main(){
    int index;
    scanf("%d", &index);
    printf("%0.2f", m(index));

    return 0;
}

double m(int i){
    if(i == 0){
        return 0;
    }

    return (double)i / (double)(i * 2 + 1) + m(i - 1);
}