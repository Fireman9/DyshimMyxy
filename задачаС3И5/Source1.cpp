#include "Header.h"
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
string answer(int n) {
	int k3;
	int k5=-1;
	string ans="(1)";
	for (int i = 0; pow(3, i) <= n; i++) {
		if ((n - (int)pow(3, i )) % 5 == 0) {
			k5 = (n - (int)pow(3, i)) / 5;
			k3 = i;
			//break;
		}
		cout << k3 << endl;
	}

	if (k5==-1)
		return "none";
	for (int i = 0; i < k3; i++) {
		ans = '(' + ans;
		if (k5 >= pow(3, k3 - i)) {
			ans = '(' + ans + "+5)";
			k5 -= pow(3, k3 - i);
		}
		ans += "*3)";	
	}
	for (int i = 0; i < k5; i++) {
		ans = '(' + ans + "+5)";
	}
	//cout << k3<<' '<<k5;
	return ans;
}