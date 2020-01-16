#include <string>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<string, int> psi;
void input(vector<string>& v) {
	string temp;
	while(1) {
		getline(cin, temp);	
		if (temp.length() <= 1)
			break;
		v.push_back(temp);
	}
}
psi* an(const vector<string> arr) {
	psi* ans = new psi[arr.size()];
	int count = 0;
	for (int i = 0; i < arr.size(); i++) {
		ans[i].second = 0;
		for (int j = 0; j < arr[i].length(); j++) {
			if (arr[i][j] == '=' || arr[i][j] == '+') {
				count++;
				continue;
			}
			if (count == 0)
				ans[i].first += arr[i][j];
			if (count == 1)
				continue;
			if (count == 2) {
				ans[i].second = ans[i].second * 10 + (arr[i][j] - '0');
			}
		}
	}
	return ans;
}
void output(psi* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i].first << "+=" << arr[i].second<<endl;
	}
}
int main()
{
	vector<string> arr;
	input(arr);
	psi* ans = an(arr);
	output(ans, arr.size());
	return 0;
}
