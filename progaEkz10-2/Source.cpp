#include <iostream>
#include "Header.h"
using namespace std;
int main() {
	string ans;
	getline(cin, ans);
	cout << from2to10(ans)<<endl;
	long long n;
	int N;
	cin >> n>> N;
	cout << from10toN(n, N);
	return 0;
}