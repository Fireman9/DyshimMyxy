#include <algorithm>
#include "Header.h"
using namespace std;
typedef long long ll;
string from10toN(ll n, int N) {
	string arr = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string ans="";
	while (n > 0) {
		ans += arr[n % N];
		n /= N;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
ll from2to10(string n) {
	reverse(n.begin(), n.end());
	ll ans=0;
	for (int i = 0; i < n.size(); i++) {
		ans += pow(2, i)*(n[i]-'0');

	}
	return ans;
}