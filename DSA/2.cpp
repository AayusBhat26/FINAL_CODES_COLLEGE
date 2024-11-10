#include<iostream>
using namespace std; 

int main(){
    int row, col;
    // Getting matrix size and checking if within bounds
    cout << "\nProvide the number of rows and columns (max 10): ";
    cin >> row >> col;
    if(row > 10 || col > 10 || row <= 0 || col <= 0){
        cout << "Error: Matrix size should be between 1 and 10.\n";
        return 1;
    }
    int sparseMatrix[10][10]; // maximum matrix size is 10x10
    int size = 0;
    // Taking input for matrix elements
    cout << "\nProvide the matrix values:\n";
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> sparseMatrix[i][j];
            if(sparseMatrix[i][j] != 0){
                size++;
            }
        }
    }
    // Display the entered matrix
    cout << "\nCURRENT MATRIX:\n";
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << sparseMatrix[i][j] << " ";
        }
        cout << endl;
    }
    // Display matrix stats
    cout << "\nNumber of total elements: " << row * col;
    cout << "\nNumber of non-zero elements: " << size << endl;

    // Check if it is a sparse matrix
    if(size <= (row * col) / 2){
        cout << "\nIt is a Sparse Matrix\n";
    } else {
        cout << "\nIt is NOT a Sparse Matrix\n";
    }

    if(size > 0) {
        int betterMatrix[size][3];
        int k = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(sparseMatrix[i][j] != 0){
                    betterMatrix[0][k] = i;
                    betterMatrix[1][k] = j;
                    betterMatrix[2][k] = sparseMatrix[i][j];
                    k++;
                }
            }
        }
        if(size < (row * col)/4){ 
            // Displaying the 3-column sparse matrix
        cout << "\n3-column Sparse Matrix Representation:\n";
        cout << "Row Col Value\n";
        for(int i = 0; i < size; i++){
            cout << betterMatrix[0][i] << "    " << betterMatrix[1][i] << "    " << betterMatrix[2][i] << endl;
        }
        }
       
    } else {
        cout << "\nThe matrix contains no non-zero elements.\n";
    }
    return 0;
}
