#include <stdio.h>

int matrix_input(int rows, int columns, int matrix[rows][columns]) {
    printf("Enter elements of the matrix (%d x %d):\n", rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
    return 0;
}

int display_matrix(int rows, int columns, int matrix[rows][columns]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int add_matrix(int rows, int columns, int matrix1[rows][columns], int matrix2[rows][columns], int result[rows][columns]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return 0;
}

int multiply_matrix(int rows1, int columns1, int rows2, int columns2, int matrix1[rows1][columns1], int matrix2[rows2][columns2], int result[rows1][columns2]) {
    if (columns1 != rows2) {
        printf("Matrix multiplication not possible. Columns of matrix 1 must equal rows of matrix 2.\n");
        return -1;
    }
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < columns1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return 0;
}

int transpose_matrix(int rows, int columns, int matrix[rows][columns], int result[columns][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    return 0;
}

int main_menu() {
    int choice;
    printf("\nMatrix Operations Menu:\n");
    printf("--------------------------\n");
    printf("1. Add Matrices\n");
    printf("2. Multiply Matrices\n");
    printf("3. Transpose Matrix\n");
    printf("4. Exit\n");
    printf("--------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    int choice;
    int rows, columns;
    int rows1, columns1, rows2, columns2;
    
    while (1) {
        choice = main_menu();
        
        switch (choice) {
            case 1: {
                printf("\nMatrix Addition:\n");
                printf("--------------------------\n");
                printf("\nEnter rows and columns for the matrices: ");
                scanf("%d %d", &rows, &columns);
                
                int matrix1[rows][columns];
                int matrix2[rows][columns];
                int result_add[rows][columns];
                
                printf("\nEnter matrix 1:\n");
                matrix_input(rows, columns, matrix1);
                printf("\nMatrix 1:\n");
                display_matrix(rows, columns, matrix1);
                
                printf("\nEnter matrix 2:\n");
                matrix_input(rows, columns, matrix2);
                printf("\nMatrix 2:\n");
                display_matrix(rows, columns, matrix2);
                
                add_matrix(rows, columns, matrix1, matrix2, result_add);
                
                printf("\nAddition result:\n");
                display_matrix(rows, columns, result_add);
                break;
            }
            
            case 2: {
                printf("\nMatrix Multiplication:\n");
                printf("--------------------------\n");
                printf("Enter rows and columns for matrix 1: ");
                scanf("%d %d", &rows1, &columns1);
                printf("Enter rows and columns for matrix 2: ");
                scanf("%d %d", &rows2, &columns2);
                
                int matrixA[rows1][columns1];
                int matrixB[rows2][columns2];
                int result_mul[rows1][columns2];
                
                printf("\nEnter matrix 1:\n");
                matrix_input(rows1, columns1, matrixA);
                printf("\nMatrix 1:\n");
                display_matrix(rows1, columns1, matrixA);
                
                printf("\nEnter matrix 2:\n");
                matrix_input(rows2, columns2, matrixB);
                printf("\nMatrix 2:\n");
                display_matrix(rows2, columns2, matrixB);
                
                if (multiply_matrix(rows1, columns1, rows2, columns2, matrixA, matrixB, result_mul) == 0) {
                    printf("\nMultiplication result:\n");
                    display_matrix(rows1, columns2, result_mul);
                }
                break;
            }
            
            case 3: {
                printf("\nMatrix Transpose:\n");
                printf("--------------------------\n");
                printf("Enter rows and columns for the matrix: ");
                scanf("%d %d", &rows, &columns);

                int matrix_transpose[rows][columns];
                int result_transpose[columns][rows];

                printf("\nEnter matrix:\n");
                matrix_input(rows, columns, matrix_transpose);
                printf("\nOriginal matrix:\n");
                display_matrix(rows, columns, matrix_transpose);

                transpose_matrix(rows, columns, matrix_transpose, result_transpose);

                printf("\nTranspose result:\n");
                display_matrix(columns, rows, result_transpose);
                break;
            }

            case 4:
                printf("\nExiting the program...\n");
                return 0;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}