#include <iostream>
#include "proc.h"

using namespace std;

int main() {
	int m;
	cout << "Enter square matrix size:" << endl;
	cin >> m;
	int** matr = create_matr(m);
	gener_matr(matr, m);
	print_matr(matr, m);
	matr = reflect_matr(matr, m);
	print_matr(matr, m);
	del_matr(matr, m);
	return 0;
}