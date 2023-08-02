#include <iostream>
#include "MatrixClass.h"

int main() {

    std::cout << "Welcome to the Matrix Operations Program!" << std::endl;

    // Create a matrix with random dimensions and values
    Matrix matrix1;
    matrix1.randomSet();
    std::cout << "Matrix 1:" << std::endl;
    matrix1.display();



    // Create a matrix with specific dimensions and let the user input values
    int rows, columns;
    std::cout << "Enter the number of rows for Matrix 2: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns for Matrix 2: ";
    std::cin >> columns;

    Matrix matrix2(rows, columns);
    matrix2.userGeneratedMatrix();
    std::cout << "Matrix 2:" << std::endl;
    matrix2.display();



    // Perform matrix addition and display the result
    Matrix result = matrix1; // Use the copy constructor to create a copy of matrix1
    result.addMatrix(matrix2);
    std::cout << "Result of matrix addition:" << std::endl;
    result.display();




    // Let's create an identity matrix

    int identitySize;
    std::cout << "Enter the size of the identity matrix: ";
    std::cin >> identitySize;

    Matrix identity(identitySize, identitySize);
    identity.IdentityMatrixSet();
    std::cout << "Identity Matrix:" << std::endl;
    identity.display();

    return 0;
}

