#include <iostream>
#include <string>

using namespace std;

void decompose(int& i) {
	string result;
	int count = 0;
	while (i > 1) {
		if (i % 3 != 0) {
			i -= 5;
			result.insert(0, " + 5)");
		}
		else {
			i /= 3;
			result.insert(0, " * 3)");
		}
		count++;
	}
	result.insert(0, "1");
	for (int i = 0; i < count; i++) {
		result.insert(0, "(");
	}
	if (i == 1) {
		cout << result << endl;
	}
}