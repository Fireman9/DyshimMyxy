#include <iostream>
#include <iomanip>
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
			matr[i][j] = rand() % 51;
		}
	}
}
void print_matr(int** matr, int m) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(4) << left << matr[i][j];
		}
		cout << endl;
	}
}
void snailstep(int** matr, int m) {
	int bypass = m, mcounter = 0;
	int* ready = new int[m*m];
	for (int z = 0; z < bypass; z++) {
		for (int i = z; i < bypass; i++) {
			ready[mcounter] = matr[i][z];
			mcounter++;
		}
		for (int i = z + 1; i < bypass; i++) {
			ready[mcounter] = matr[bypass - 1][i];
			mcounter++;
		}
		for (int i = bypass-2; i >= z; i--) {
			ready[mcounter] = matr[i][bypass - 1];
			mcounter++;
		}
		for (int i = bypass - 2; i >= z+1; i--) {
			ready[mcounter] = matr[z][i];
			mcounter++;
		}
		bypass--;
	}
	for (int i = 0; i < m * m; i++) {
		cout << ready[i] << " ";
	}
}