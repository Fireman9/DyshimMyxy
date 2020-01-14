#include <iostream>
#include "Header.h"

using namespace std;

int main() {
	int n, m;
	cout << "Enter matrix size(m): " << endl;
	cin >> m;
	int** matr = creatematr(m);
	genermatr(matr, m);
	cout << "Your matrix: " << endl;
	printmatr(matr, m);
	rhombsum(matr, m);
	delmatr(matr, m);
	return 0;
}