#include <iostream>
#include <string>

using namespace std;

void proc(string& text) {
	int words = 0, index = 0, tcount = 0;
	text += " ";
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == ' ') {
			words++;
		}
	}
	string* temp = new string[words];
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == ' ') {
			temp[tcount].assign(text, index, i-index);
			index = i + 1;
			tcount++;
		}
	}
	for (int i = 0; i < words; i++) {
		for (int i = 0; i < words - 1; i++) {
			if (temp[i].length() < temp[i + 1].length()) {
				swap(temp[i], temp[i + 1]);
			}
		}
	}

	for (int i = 0; i < words; i++) {
		cout << temp[i] << " ";
	}
	delete[] temp;
}