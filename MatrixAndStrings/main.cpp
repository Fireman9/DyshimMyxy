#include <iostream>
#include <iomanip>

#include "Header.h"

using namespace std;
int main()
{
	setlocale(0, "russian");
	int n, m;
	cout << "Enter matrix size(m, n): " << endl;
	cin >> m >> n;
	int** matrix = CreateMatrix(m,n);
	
	
	GenerateMatrix(matrix, m, n);
	cout << "Созданная целочисленная матрица" << endl;
	outputMatrix(matrix, m, n);
	
	cout << endl;
	
	int** arr_string = CreateArray(matrix, m, n);
	cout << "матрица из разницы соседних чисел строк" << endl;
	outputMatrix(arr_string, m, n-1);
	cout << endl;

	char** arr = Sort(ToStringArray( ChangingArray(arr_string, m, n-1) , m, n-1), m);
	cout << "Отсортированная матрица по длинне строк" << endl;
	for (int i = 0; i < m; i++)
		cout <<setw(3) << arr[i] << endl;
	
	delete[] matrix;
	delete[] arr_string;
}
