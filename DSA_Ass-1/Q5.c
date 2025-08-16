#include <stdio.h>

int main() {
    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[50][50];
    int rowSum[50] = {0};
    int colSum[50] = {0};
  printf("The elements of matrix are:");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            rowSum[i] += matrix[i][j];
            colSum[j] += matrix[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("| %d\n", rowSum[i]);
    }

    printf("\n");
    for (int j = 0; j < cols; j++) {
        printf("%d ", colSum[j]);
    }
    printf("\n");

    return 0;
}