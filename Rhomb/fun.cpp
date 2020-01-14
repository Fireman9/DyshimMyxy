#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int** creatematr(int m) {
	int** matr = new int* [m];
	for (int k = 0; k < m; k++) {
		matr[k] = new int[m];
	}
	return matr;
}

void delmatr(int** matr, int m) {
	for (int i = 0; i < m; i++) {
		delete[]matr[i];
	}
	delete[]matr;
}

void genermatr(int** matr, int m) {
	srand(time(NULL));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			matr[i][j] = rand() % 51 - 25;
		}
	}
}

void printmatr(int** matr, int m) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(5) << left << matr[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void rhombsum(int** matr, int m) {
	int sum = 0, rstart, ccount, elcount;
	if (m % 2 != 0) {	//odd
		rstart = (m - 1) / 2, ccount = 0, elcount = 1;
		while (rstart >= 0) {
			for (int i = 0; i < elcount; i++) {
				sum += matr[rstart + i][ccount];
			}
			ccount++, rstart--;
			if (elcount < m) {
				elcount += 2;
			}
			else {
				elcount -= 2;
			}
		}
		rstart+=2;
		while (rstart < m) {
			for (int i = 0; i < elcount; i++) {
				sum += matr[rstart + i][ccount];
			}
			ccount++, rstart++;
			if (elcount < m) {
				elcount -= 2;
			}
		}
	}
	else {	//even
		rstart = m / 2 - 1, ccount = 0, elcount = 2;
		while (rstart >= 0) {
			for (int i = 0; i < elcount; i++) {
				sum += matr[rstart + i][ccount];
			}
			ccount++, rstart--;
			if (elcount < m) {
				elcount += 2;
			}
			else if (elcount == m) {
				
			}
			else {
				elcount -= 2;
			}
		}
		rstart += 1;
		while (rstart < m) {
			for (int i = 0; i < elcount; i++) {
				sum += matr[rstart + i][ccount];
			}
			ccount++, rstart++;
			if (elcount <= m) {
				elcount -= 2;
			}
		}
	}
	cout << sum;
}