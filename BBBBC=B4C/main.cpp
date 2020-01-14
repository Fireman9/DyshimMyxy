#include <iostream>
#include <string>
#include <vector>
#include "proc.h"

using namespace std;

int main() {
	vector <string> textarray;
	gettext(textarray);
	proc(textarray);
	return 0;
}