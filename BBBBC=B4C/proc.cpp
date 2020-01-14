#include <iostream>
#include <string>
#include <vector>

using namespace std;

void gettext(vector <string>& textarray) {
	string text;
	int count = 1;
	cout << "Enter text(if you want stop writting text enter '-1'): " << endl;
	while (true) {
		cout << "Line" + to_string(count) + ": ";
		count++;
		getline(cin, text);
		if (text != "-1") {
			text += ' ';
			textarray.push_back(text);
		}
		else {
			break;
		}
	}
}
void proc(vector <string>& textarray) {
	int sum, j;
	string temp;
	for (int k = 0;k<textarray.size();k++) {
		for (int i = 0; i < textarray[k].length()-1; i++) {		//all symbols without last " "
			sum = 1, temp = "";
			for (j = i; j < textarray[k].length(); j++) {
				if (textarray[k][j + 1] != textarray[k][j]) {
					if (sum == 1) {
						break;
					}
					else {
						temp = "{" + to_string(sum) + "}";
						textarray[k].replace(i+1, j - i, temp);
						break;
					}
				}
				else {
					sum++;
				}
			}
		}
	}
	for (string t : textarray) {
		sum = 1;
		cout << "Line" + to_string(sum) + ": ";
		cout << t << endl;
	}
}