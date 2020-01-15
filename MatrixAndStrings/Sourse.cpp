#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

int** CreateMatrix(int m, int n) {
	int** matrix = new int* [m];
	for (int k = 0; k < m; k++) {
		matrix[k] = new int[n];
	}
	return matrix;
}

void outputMatrix(int** matrix, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout <<setw(3)<< matrix[i][j] << " ";
		}
		cout << endl;
	}
}
void GenerateMatrix(int** matrix, int m, int n) {
	srand(time(NULL));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = rand() %  61 - 30;
		}
	}
}
int** CreateArray(int** matrix, int m, int n) {
	int **arr_string = new int *[m];
	for (int i = 0; i < m; i++) {
		arr_string[i] = new int[n - 1];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n - 1; j++) {
			arr_string[i][j] = matrix[i][j] - matrix[i][j + 1];
		}
	}
	return arr_string;
}
int** ChangingArray(int** arr_string, int m, int n) {
	int tmp = 0;
	for (int i = 0; i < m; i++) {
		int q = 0;
		for (int j = 0; j < n; j++) {
			if (arr_string[i][j] < 0) {
				tmp = arr_string[i][q];
				arr_string[i][q] = arr_string[i][j];
				arr_string[i][j] = tmp;
				q++;
			}
		}
	}
	return arr_string;
}
char** ToStringArray(int** arr, int m, int n)
{
	char** matrix = new char* [m];

	for (int i = 0; i < m; i++) {
		string s;
		for (int j = 0; j < n; j++)
		{
			s += " " + to_string(arr[i][j]);
		}
		matrix[i] = new char[s.length() + 1];
		strcpy_s(matrix[i], s.length()+1, s.c_str());
	}
	return matrix;
}

char** Sort(char** arr, int m)
{
	string* temp = new string[m];
	for (int j = 0; j < m; j++)
	{
		temp[j] = string(arr[j]);
	}
	delete[] arr;
	arr = new char* [m];

	for (int i = 0; i < m; i++) {
		for (int t = 0; t < m - 1; t++) {
			if (temp[t].length() < temp[t + 1].length()) {
				string s = temp[t + 1];
				temp[t + 1] = temp[t];
				temp[t] = s;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		arr[i] = new char[temp[i].length() + 1];
		strcpy_s(arr[i], temp[i].length() + 1, temp[i].c_str());
	}
	return arr;
}
