
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>



class Matrix{

private:
    int row,column;

    int** matrix;

public:

    Matrix(int r,int c);
    Matrix();
    ~Matrix();
    Matrix(const Matrix& other);


    void randomSet();
    void userGeneratedMatrix();
    void IdentityMatrixSet();

    void display();

    void addMatrix(Matrix& otherMatrix);




};

Matrix::Matrix(int r, int c) {


    while (r<=0 || c<=0){



        std::cout<<"Rows and columns values must be greater than zero.\nRows:";
        std::cin>>r;
        std::cout<<"Columns:";
        std::cin>>c;


    }

   row=r;
   column=c;

    matrix=new int*[row];

    for (int i = 0; i <row ; i++) {

        matrix[i]=new int[column];



    }

    std::cout<<"Matrix created"<<std::endl;







}

Matrix::Matrix() {


    std::random_device rd; // Create a random_device to obtain a random seed
    std::default_random_engine randomEngine(rd()); // Seed the engine with the random seed

    std::uniform_int_distribution<int> distribution(1, 5);

    row = distribution(randomEngine);
    column = distribution(randomEngine);


    std::cout<<"Number of rows and columns  are randomly generated"<<std::endl;

    std::cout << "\nRows: " << row << "\nColumns: " << column<<std::endl;

    matrix=new int*[row];

    for (int i = 0; i <row ; i++) {

        matrix[i]=new int[column];



    }



}

Matrix::~Matrix() {

    for (int i = 0; i <row ; i++) {

        delete[] matrix[i];
    }
    delete[] matrix;
    std::cout<<"Matrix destroyed"<<std::endl;

}



Matrix::Matrix(const Matrix& other) {

    row=other.row;
    column=other.column;

    for (int i = 0; i <row ; i++) {

        matrix[i]=new int[column];

    }

    for (int i = 0; i <row ; i++) {
        for (int j = 0; j <column ; j++) {
            matrix[i][j]=other.matrix[i][j];

        }

    }


}


void Matrix::display() {

    std::cout<<"\nMatrix:"<<std::endl;

    for (int i = 0; i <row ;i++) {
        for (int j = 0; j <column ;j++) {

            std::cout<<matrix[i][j]<<" ";

        }
        std::cout<<"\n";


    }

    std::cout<<"\n";

}

void Matrix::randomSet() {


    std::random_device rd; // Create a random_device to obtain a random seed
    std::default_random_engine randomEngine(rd()); // Seed the engine with the random seed

    std::uniform_int_distribution<int> distribution(1, 100);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            matrix[i][j] = distribution(randomEngine);
        }
    }

}

void Matrix::userGeneratedMatrix() {


    std::cout<<"Enter the values of matrix for each row and columns:"<<std::endl;

    int element;


    for (int i = 0; i <row ; i++) {
        for (int j = 0; j <column ;j++) {

            std::cout<<"["<<i<<"]"<<"["<<j<<"]"<<std::endl;

            std::cin>>element;

            matrix[i][j]=element;




        }


    }

    std::cout<<"Matrix  generated with random values"<<std::endl;



}

void Matrix::IdentityMatrixSet() {


    // Check if the matrix is square (i.e., number of rows == number of columns)
    if (row != column) {
        std::cout << "Identity matrix must be square. Cannot set identity matrix." << std::endl;
        return;

    }

    // Set the elements of the matrix to create an identity matrix
    for (int i = 0; i < row; i++) {

        for (int j = 0; j < column; j++) {

            if (i == j){
                matrix[i][j] = 1; // Diagonal elements are 1

            }

            else{

                matrix[i][j] = 0; // Non-diagonal elements are 0

            }

        }


    }
}

void Matrix::addMatrix(Matrix& otherMatrix) {

    // Check if the dimensions of both matrices are the same

    if (row != otherMatrix.row || column != otherMatrix.column) {

        std::cout << "Cannot perform matrix addition. Matrices have different dimensions." << std::endl;

        return;
    }

    // Perform matrix addition
    for (int i = 0; i < row; i++) {

        for (int j = 0; j < column; j++) {

            matrix[i][j] += otherMatrix.matrix[i][j];


        }
    }
}









