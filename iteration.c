#include <stdio.h>

int get(int a, int b, int c);

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d", get(a, b, c));

    return 0;
}

int get(int a, int b, int c){
    for(int count = 0; ; count++){
        int current = count * 3 + a;
        if(current % 5 == b){
            if(current % 7 == c){
                if(current == 0){
                    continue;
                }
                return current;
            }
        }
    }
}