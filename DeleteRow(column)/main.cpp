#include <iostream>
#include "proc.h"

using namespace std;

int main() {
	int m, n;
	cout << "Enter matrix size(m,n):" << endl;
	cin >> m >> n;
	int **matr = create_matr(m,n);
	gener_matr(matr, m, n);
	print_matr(matr, m, n);
	matr = del_row(matr, m, n);
	print_matr(matr, m, n);
	matr = del_col(matr, m, n);
	print_matr(matr, m, n);
	del_matr(matr, m);
	return 0;
}