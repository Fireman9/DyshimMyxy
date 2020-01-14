#include <iostream>
#include "proc.h"

using namespace std;

int main() {
	int m;
	cout << "Enter matrix size: " << endl;
	cin >> m;
	int** matr = create_matr(m);
	gener_matr(matr, m);
	cout << "Your matrix: " << endl;
	print_matr(matr, m);
	snailstep(matr, m);
	del_matr(matr, m);
	return 0;
}