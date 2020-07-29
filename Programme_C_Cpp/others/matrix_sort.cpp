#include <stdio.h>
#include <stdlib.h>
#define MAX_TOTAL 10
#define MAX_SIZE 4

void inputMatrices(int (*matrix)[MAX_SIZE], size_t size)
{
  int i, j;
  for(i = 0; i < size; i++)
    for(j = 0; j < size; j++)
      scanf("%d", &matrix[i][j]);
}

void printMatrices(int (*matrix)[MAX_SIZE], size_t size)
{
  int i, j;
  for(i = 0; i < size; i++)
  {
    for(j = 0; j < size; j++)
      printf("%d ", matrix[i][j]);
    printf("\n");
  }
  printf("\n");
}

int cmpMatrices(const void *firstMatrixPtr, const void *secondMatrixPtr, void *sizePtr) 
{
  size_t *matrixSizePtr = (size_t *)sizePtr;
  size_t matrixSize = *matrixSizePtr;
  int *first = *((int (*)[MAX_SIZE])firstMatrixPtr);
  int *second = *((int (*)[MAX_SIZE])secondMatrixPtr);
  int ans1 = 0, ans2 = 0, i, j;
  for(i = 0; i < matrixSize; i++)
  {
    if(i == matrixSize - 1 - i)
      ans1 += first[i * MAX_SIZE + i];
    else
      ans1 += first[i * MAX_SIZE + i] + first[i * MAX_SIZE + matrixSize - 1 - i];
  }
  for(i = 0; i < matrixSize; i++)
  {
    if(i == matrixSize - 1 - i)
      ans2 += second[i * MAX_SIZE + i];
    else
      ans2 += second[i * MAX_SIZE + i] + second[i * MAX_SIZE + matrixSize - 1 - i];
  }
  if(ans1 < ans2)return -1;
  if(ans1 > ans)return 1;
  else return 0;    
}

int main() {
  size_t total = 0, size = 0;
  scanf("%zu%zu", &total, &size);
  int matrixArr[MAX_TOTAL][MAX_SIZE][MAX_SIZE] = {0};
  for (size_t matrixIndex = 0; matrixIndex < total; ++matrixIndex) {
    inputMatrices(matrixArr[matrixIndex], size);
  }
  for (size_t matrixIndex = 0; matrixIndex < total; ++matrixIndex) {
    f(matrixArr[matrixIndex], size);
  }
  qsort_r(matrixArr, total, sizeof(matrixArr[0]), &cmpMatrices, &size);
  for (size_t matrixIndex = 0; matrixIndex < total; ++matrixIndex) {
    printMatrices(matrixArr[matrixIndex], size);
  }
  return 0;
}