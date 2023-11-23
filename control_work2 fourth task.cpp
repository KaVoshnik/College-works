#include <iostream>

using namespace std;

int main()
{
    int rows;
    int column;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of column: ";
    cin >> column;

    int **matrix = new int*[rows];
    for(int i = 0; i < rows; i++)
    {
        matrix[i] = new int[column];
        for(int j = 0; j < column; j++)
        {
            cout << "Enter value for matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    int **transposedMatrix = new int*[column];
    for(int i = 0; i < column; i++)
    {
        transposedMatrix[i] = new int[rows];
        for(int j = 0; j < rows; j++)
        {
            transposedMatrix[i][j] = matrix[j][i];
        }
    }

    cout << "Original Matrix:\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < column; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Transposed Matrix:\n";
    for(int i = 0; i < column; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            cout << transposedMatrix[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    for(int i = 0; i < column; i++)
    {
        delete[] transposedMatrix[i];
    }
    delete[] transposedMatrix;

    return 0;
}
