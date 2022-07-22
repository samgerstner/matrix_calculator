#include "driver.h"

/**
 * @brief The C main() method.
 * 
 * @return int C exit status code.
 */
int main()
{
    //Initialize Method
    bool exitProgram = false;
    int menuSelection;

    while(!exitProgram)
    {
        menuSelection = -1;
        displayMainMenu();
        printf("Enter menu option: ");
        scanf("%d", &menuSelection);

        switch(menuSelection)
        {
            case 1:
                additionSubtractionHelper(ADDITION_FLAG);
                break;

            case 2:
                additionSubtractionHelper(SUBTRACTION_FLAG);
                break;

            case 3:
                exitProgram = true;
                break;

            default:
                printf("Invalid menu selection.\n");
                break;
        }
    }

    return 0;
}

/**
 * @brief Helper function that supports program operations for addition and subtraction.
 * 
 * @param opFlag Integer constant that indicates whether the program should perform addition or subtraction.
 */
void additionSubtractionHelper(int opFlag)
{
    //Initialize Method
    int numRows, numCols, rowIndex, colIndex;
    Matrix *a, *b, *result;

    //Prompt user for number of rows and columns in matrix A
    printf("Enter number of rows in matrix A: ");
    scanf("%d", &numRows);
    printf("Enter number of columns in matrix A: ");
    scanf("%d", &numCols);

    //Create matrix A
    a = createMatrix(numRows, numCols);

    //Prompt user for number of rows and columns in matrix B
    printf("Enter number of rows in matrix B: ");
    scanf("%d", &numRows);
    printf("Enter number of columns in matrix B: ");
    scanf("%d", &numCols);

    //Create matrix B
    b = createMatrix(numRows, numCols);

    //Verify that matrices have the same dimensions
    if(!haveSameDimensions(a, b))
    {
        printf("Matrices must have the same dimensions. Operation aborted.\n");
        return;
    }

    //Prompt user for values of matrix A
    printf("Enter values for matrix A:\n");
    for(rowIndex = 0; rowIndex < numRows; rowIndex++)
    {
        for(colIndex = 0; colIndex < numCols; colIndex++)
        {
            printf("Enter value at [%d, %d]: ", rowIndex + 1, colIndex + 1);
            scanf("%lf", &a->data[rowIndex][colIndex]);
        }
    }

    //Prompt user for values of matrix B
    printf("Enter values for matrix B:\n");
    for(rowIndex = 0; rowIndex < numRows; rowIndex++)
    {
        for(colIndex = 0; colIndex < numCols; colIndex++)
        {
            printf("Enter value at [%d, %d]: ", rowIndex + 1, colIndex + 1);
            scanf("%lf", &b->data[rowIndex][colIndex]);
        }
    }

    //Perform addition or subtraction
    if(opFlag == ADDITION_FLAG)
    {
        result = add(a, b);
    }
    else
    {
        result = subtract(a, b);
    }

    //Print result matrix
    printf("Result matrix:\n");
    displayMatrix(result);
    printf("Press Any Key to Continue\n");  
    getchar();
}

/**
 * @brief Displays the program's main menu.
 */
void displayMainMenu()
{
    printf("\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Exit Program\n");
    printf("\n");
}