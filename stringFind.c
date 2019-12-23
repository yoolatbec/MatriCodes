#include <stdio.h>
#include <string.h>

void find();

int main(){
    int time;
    scanf("%d", &time);
    for(int count = 0; count < time; count++){
        find();
    }

    return 0;
}

void find(){
    char origin[10000];
    char section[10000];
    int currentMax = 0;
    int tempMax = 0;
    scanf("%s", origin);
    scanf("%s", section);
    int length = strlen(section);
    int maxLength = strlen(origin);
    int currentCompare = 0;
    for(int count = 0; count < maxLength; count++){
        if(*(origin + count) == *(section + currentCompare)){
            currentCompare++;
            if(currentCompare == length){
                currentCompare = 0;
                tempMax++;
                currentMax = currentMax > tempMax ? currentMax : tempMax;
            }
            continue;
        }
        currentCompare = 0;
        tempMax = 0;
    }
    printf("%d\n", currentMax * length);
}
