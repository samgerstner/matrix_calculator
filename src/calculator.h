#ifndef CALCULATOR_H
#define CALCULATOR_H

    //Include Statements
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>

    //Struct Declaration
    typedef struct Matrix
    {
        int numRows;
        int numCols;
        double **data;
    } Matrix;

    //Function Stubs
    Matrix *add(Matrix *a, Matrix *b);
    Matrix *createMatrix(int numRows, int numCols);
    void displayMatrix(Matrix *matrix);
    bool haveSameDimensions(Matrix *a, Matrix *b);
    Matrix *subtract(Matrix *a, Matrix *b);

#endif