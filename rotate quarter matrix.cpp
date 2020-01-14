#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;
const int n = 4;
void createMatrix(int mat[][n], int n);
void outputMatrix(int mat[][n], int n);
void processMatrix(int mat[][n], int n);
int main()
{
    int matrix[n][n];
    srand(time(NULL));
    createMatrix(matrix, n);
    outputMatrix(matrix, n);
    processMatrix(matrix, n);
    cout<<"\n";
    outputMatrix(matrix, n);
}
void createMatrix(int mat[n][n],int n)
{
    for (int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            mat[i][j] = rand()%10;
}
void outputMatrix(int mat[n][n], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void processMatrix(int mat[][n], int n)
{
    for(int counter=0; counter<3; counter++){
	
	int matrix2[n][n];
    for (int i=0; i<n/2; i++)
        for(int j=0; j<n/2; j++)
            matrix2[i][j] = mat[i+n/2][j];
 
    for (int i=0; i<n/2; i++)
        for(int j=0; j<n/2; j++)
            matrix2[i][j+n/2] = mat[i][j];
 
    for (int i=0; i<n/2; i++)
        for(int j=0; j<n/2; j++)
            matrix2[i+n/2][j+n/2] = mat[i][j+n/2];
 
    for (int i=0; i<n/2; i++)
        for(int j=0; j<n/2; j++)
            matrix2[i+n/2][j] = mat[i+n/2][j+n/2];
 
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            mat[i][j] = matrix2[i][j];
        }
}
