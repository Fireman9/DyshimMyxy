#include <iostream>
#include <string>

using namespace std;

void del_spaces(string &str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ' && str[i + 1] == ' ') {
			str.erase(i, 1);
			i--;
		}
	}
	if (str[0] == ' ') {
		str.erase(0, 1);
	}
	if (str[str.length()-1] != ' ') {
		str += ' ';
	}
}
void sort_str(string& str) {
	int words = 0, k = 0, q = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			words++;
		}
	}
	string ready = " ", temp;
	for (int j = 0; j < words; j++) {
		temp = " ", q = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ') {
				if (temp.length() <= i - q) {
					temp.clear();
					temp.assign(str, q, i - q);
				}
				q = i+1;
				k++;
			}
		}
		str.erase(str.find(temp),temp.length());
		if (str.length() > 1) {
			del_spaces(str);
		}
		ready += temp;
		del_spaces(ready);
	}
	cout << ready << endl;
}