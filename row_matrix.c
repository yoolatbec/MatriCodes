#include <stdio.h>

void printMatrix(int, int);

int main(){
    int row, col;
    scanf("%d%d", &row, &col);
    printMatrix(row, col);

    return 0;
}

void printMatrix(int row, int col){
    for(int current_row = 0; current_row < row; current_row++){
        if((current_row % 2) == 0){
            for(int current = current_row * col + 1; current <= (current_row + 1) * col; current++){
                printf("%3d", current);
            }
            printf("\n");
        } else {
            for(int current = (current_row + 1) * col; current >= current_row * col + 1; current--){
                printf("%3d", current);
            }
            printf("\n");
        }
    }
}