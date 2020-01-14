#include <iostream>
#include <ctime>

using namespace std;

int** create_matr(int m) {
	int** matr = new int* [m];
	for (int i = 0; i < m; i++) {
		matr[i] = new int[m];
	}
	return matr;
}
void del_matr(int** matr, int m) {
	for (int i = 0; i < m; i++) {
		delete[]matr[i];
	}
	delete[]matr;
}
void gener_matr(int** matr, int m) {
	srand(time(0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			matr[i][j] = rand() % 51 - 25;
		}
	}
}
void print_matr(int** matr, int m) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << matr[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}
int** reflect_matr(int** matr, int m) {
	int** temp = create_matr(m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			temp[i][j] = matr[j][i];
		}
	}
	return temp;
	del_matr(temp,m);
}