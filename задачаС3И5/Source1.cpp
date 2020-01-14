#include "Header.h"
std::string answer(int n) {
	std::string ans = "1";
	while (n > 1) {
		if (n % 3 != 0)
		{
			n -= 5;
			ans = '(' + ans;
			ans += "+5)";
		}
		else {
			n /= 3;
			ans = '(' + ans;
			ans += "*3)";
		}
	}
	if (n == 1)
		return ans;
	else
		return "None";
}