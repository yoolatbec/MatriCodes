#include <stdio.h>
#include <math.h>

char * judge(long origin);

int main(){
    int origin;
    scanf("%d", &origin);
    printf("%s", judge(origin));

    return 0;
}

char * judge(long origin){
    if(origin == 1)
        return "No";
    if(origin == 2 || origin == 3)
        return "Yes";
    long squ = (long)sqrt(origin);
    for(int count = 2; count <= squ + 1; count++){
        if(origin % count == 0){
            return "Yes";
        }
    }
    return "No";
}