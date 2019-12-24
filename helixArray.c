#include <stdio.h>

void printHelixArray(int dimension);

int main(){
    int d;
    scanf("%d", &d);
    printHelixArray(d);

    return 0;
}

void printHelixArray(int dimension){
    int numbers[100][100];
    for(int count = 0; count < dimension; count++){
        for(int in = 0; in < dimension; in++){
            numbers[count][in] = 0;
        }
    }
    int ima = 0;
    int currentx = -1;
    int currenty = 0;
    int currentlen = 0;
    int orientation = 0;
    int fold = 1;
    int layer = fold / 2;
    for(int count = 0; count < (dimension * dimension); count++){
        if(currentlen == (dimension - layer)){
            if(orientation != 3){
                orientation++;
            } else {
                orientation = 0;
            }
            fold++;
            layer = fold / 2;
            currentlen = 0;
        }
        switch(orientation){
            case 0:
                currentx++;
                break;
            case 1:
                currenty++;
                break;
            case 2:
                currentx--;
                break;
            case 3:
                currenty--;
                break;
        }
        numbers[currenty][currentx] = ++ima;
        currentlen++;
    }
    for(int y = 0; y < dimension; y++){
        for(int x = 0; x < dimension; x++){
            if(x != (dimension - 1)){
                printf("%d ", numbers[y][x]);
            } else {
                printf("%d\n", numbers[y][x]);
            }
        }
    }
}
