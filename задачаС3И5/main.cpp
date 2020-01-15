#include <iostream>
#include "proc.h"

using namespace std;

int main() {
	int i;
	cout << "Enter number: " << endl;
	cin >> i;
	decompose(i);
	return 0;
}