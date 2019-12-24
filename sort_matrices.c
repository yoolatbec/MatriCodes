#include <stdio.h>
#include <stdlib.h>

#define MAX_TOTAL 10
#define MAX_SIZE 4

void inputMatrices(int (*mat)[MAX_SIZE], int size);
void printMatrices(int (*mat)[MAX_SIZE], int size);
int cmpMatrices(int (*mat1)[MAX_SIZE], int (*mat2)[MAX_SIZE], int * size);

int main() {
  size_t total = 0, size = 0;
  scanf("%zu%zu", &total, &size);
  int matrixArr[MAX_TOTAL][MAX_SIZE][MAX_SIZE] = {0};
  for (size_t matrixIndex = 0; matrixIndex < total; ++matrixIndex) {
    inputMatrices(matrixArr[matrixIndex], size);
  }
  qsort_r(matrixArr, total, sizeof(matrixArr[0]), &cmpMatrices, &size);
  for (size_t matrixIndex = 0; matrixIndex < total; ++matrixIndex) {
    printMatrices(matrixArr[matrixIndex], size);
  }
  return 0;
}

int cmpMatrices(int (*mat1)[MAX_SIZE], int (*mat2)[MAX_SIZE], int * size){
    int total1 = 0, total2 = 0;
    for(int count = 0; count <= *size; count++){
        total1 += mat1[count][count];
        total1 += mat1[count][*size - count];
        total2 += mat2[count][count];
        total2 += mat2[count][*size - count];
    }
    return total1 - total2;
}

void inputMatrices(int (*mat)[MAX_SIZE], int size){
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            scanf(" %d", &mat[row][col]);
        }
    }
}

void printMatrices(int (*mat)[MAX_SIZE], int size){
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            printf("%d ", mat[row][col]);
        }
        putchar('\n');
    }
    putchar('\n');
}
