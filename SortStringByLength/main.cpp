#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

int main() {
	string str;
	int words = 0;
	cout << "Enter your line:" << endl;
	getline(cin, str);
	del_spaces(str);
	cout << "You've entered: " << str << endl;
	sort_str(str);
	return 0;
}