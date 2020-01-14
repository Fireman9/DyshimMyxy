#include <iostream>
#include <ctime>

using namespace std;

int **create_matr(int m, int n) {
	int** matr = new int* [m];
	for (int i = 0; i < m; i++) {
		matr[i] = new int[n];
	}
	return matr;
}
void del_matr(int **matr, int m) {
	for (int i = 0; i < m; i++) {
		delete[]matr[i];
	}
	delete[]matr;
}
void gener_matr(int** matr, int m, int n) {
	srand(time(0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matr[i][j] = rand()%51-25;
		}
	}
}
void print_matr(int** matr, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matr[i][j] << "  ";
		}
		cout << endl;
	}
}
int** del_row(int** matr, int &m, int &n) {
	int ndel;
	cout << "Enter number of a row that you want delete" << endl;
	cin >> ndel;
	ndel--;
	int** temp = create_matr(m - 1, n);
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < n; j++) {
			if (i >= ndel) {
				temp[i][j] = matr[i + 1][j];
			}
			else {
				temp[i][j] = matr[i][j];
			}
		}
	}
	m--;
	return temp;
	del_matr(temp, m - 1);
}
int** del_col(int** matr, int& m, int& n) {
	int ndel;
	cout << "Enter number of a column that you want delete" << endl;
	cin >> ndel;
	ndel--;
	int** temp = create_matr(m, n - 1);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (j >= ndel) {
				temp[i][j] = matr[i][j + 1];
			}
			else {
				temp[i][j] = matr[i][j];
			}
		}
	}
	n--;
	return temp;
	del_matr(temp, m);
}