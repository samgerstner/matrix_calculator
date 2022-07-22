#include "calculator.h"

/**
 * @brief Calculates the sum of two matrices.
 * Note: The matrices must have the same dimensions.
 * 
 * @param a         The first matrix.
 * @param b         The second matrix.
 * 
 * @return          The sum of the two matrices.
 */
Matrix *add(Matrix *a, Matrix *b)
{
    //Initialize Method
    Matrix *result = createMatrix(a->numRows, a->numCols);
    int rowIndex, colIndex;

    for(rowIndex = 0; rowIndex < a->numRows; rowIndex++)
    {
        for(colIndex = 0; colIndex < a->numCols; colIndex++)
        {
            result->data[rowIndex][colIndex] = a->data[rowIndex][colIndex] + b->data[rowIndex][colIndex];
        }
    }

    return result;
}

/**
 * @brief Creates a new matrix object.
 * 
 * @param numRows       Number of rows in the matrix.
 * @param numCols       Number of columns in the matrix.
 * 
 * @return Matrix*      Pointer to the newly created matrix.
 */
Matrix *createMatrix(int numRows, int numCols)
{
    //Initialize Method
    Matrix *matrix = (Matrix *) malloc(sizeof(Matrix));
    matrix->numRows = numRows;
    matrix->numCols = numCols;
    matrix->data = (double**) malloc(numRows * sizeof(double*));

    if(matrix->data == NULL)
    {
        printf("Error: Unable to allocate memory for matrix.\n");
        exit(1);
    }

    for (int i = 0; i < numRows; i++)
    {
        matrix->data[i] = (double*) malloc(numCols * sizeof(double));

        if(matrix->data[i] == NULL)
        {
            printf("Error: Could not allocate memory for matrix.\n");
            exit(1);
        }
    }

    return matrix;
}

/**
 * @brief Prints out the matrix data to the console.
 * 
 * @param matrix The matrix to be displayed.
 */
void displayMatrix(Matrix *matrix)
{
    //Initialize Method
    int rowIndex, colIndex;

    for(rowIndex = 0; rowIndex < matrix->numRows; rowIndex++)
    {
        for(colIndex = 0; colIndex < matrix->numCols; colIndex++)
        {
            printf("%.2lf ", matrix->data[rowIndex][colIndex]);
        }

        printf("\n");
    }
}

/**
 * @brief Tests if two matrices have the same dimensions.
 * 
 * @param a             The first matrix.
 * @param b             The second matrix.
 * 
 * @return bool         True if the matrices have the same dimensions, false otherwise.
 */
bool haveSameDimensions(Matrix *a, Matrix *b)
{
    return a->numRows == b->numRows && a->numCols == b->numCols;
}

/**
 * @brief Subtracts matrix A from matrix B.
 * Note: The matrices must have the same dimensions.
 * 
 * @param a         The first matrix.
 * @param b         The second matrix.
 * 
 * @return          The result of the subtraction.
 */
Matrix *subtract(Matrix *a, Matrix *b)
{
    //Initialize Method
    Matrix *result = createMatrix(a->numRows, a->numCols);
    int rowIndex, colIndex;

    for(rowIndex = 0; rowIndex < a->numRows; rowIndex++)
    {
        for(colIndex = 0; colIndex < a->numCols; colIndex++)
        {
            result->data[rowIndex][colIndex] = a->data[rowIndex][colIndex] - b->data[rowIndex][colIndex];
        }
    }

    return result;
}